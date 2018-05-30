#include "DialogoResultadoConsulta.h"
#include "ui_DialogoResultadoConsulta.h"

DialogoResultadoConsulta::DialogoResultadoConsulta(QWidget *parent) : QWidget(parent) {

    ui = new Ui::DialogoResultadoConsulta();
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->conectar_componentes();

    this->meses_con_treinta_dias = std::vector<unsigned int>{ 4, 6, 9, 11 };

    this->ui->progressbar_exportacion->hide();
}


DialogoResultadoConsulta::DialogoResultadoConsulta(
    std::vector<modelo::Medio*> medios,
    std::vector<modelo::Concepto*> conceptos,
    std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados,
    QWidget *parent)
    : medios(medios), conceptos(conceptos), resultados(resultados), QWidget(parent)
{
    ui = new Ui::DialogoResultadoConsulta();
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->conectar_componentes();

    this->meses_con_treinta_dias = std::vector<unsigned int>{ 4, 6, 9, 11 };

    this->ui->progressbar_exportacion->hide();

    this->volcar_datos(medios, conceptos, resultados);

    //this->completar_arboles(medios, conceptos, resultados);

    //std::string string_fecha_minima = std::to_string((*resultados.begin())->getId()->numero());
    //QDate qfecha_minima = QDate::fromString(string_fecha_minima.c_str(), "yyyyMMdd");
    //this->ui->dateedit_desde->setDate(qfecha_minima);

    //this->fecha_actual = herramientas::utiles::Fecha::parsearFormatoAAAAMMDD(string_fecha_minima);

    //std::string string_fecha_maxima = std::to_string((*(resultados.end() - 1))->getId()->numero());
    //QDate qfecha_maxima = QDate::fromString(string_fecha_maxima.c_str(), "yyyyMMdd");
    //this->ui->dateedit_hasta->setDate(qfecha_maxima);

    //this->ui->dias->setMinimum(qfecha_minima.toJulianDay());
    //this->ui->dias->setMaximum(qfecha_maxima.toJulianDay());

    //this->ui->calendario->setDateRange(qfecha_minima, qfecha_maxima);
    //this->ui->calendario->setDate(qfecha_minima);

    //this->mostrar_resultado(std::stoi(string_fecha_minima));

}

DialogoResultadoConsulta::~DialogoResultadoConsulta()
{
    std::for_each(this->sentimientos.begin(), this->sentimientos.end(), [](std::pair<unsigned long long int, QTreeWidget*> id_y_tabla) { delete id_y_tabla.second; });
    std::for_each(this->fuerzas_en_noticia.begin(), this->fuerzas_en_noticia.end(), [](std::pair<unsigned long long int, QTreeWidget*> id_y_tabla) { delete id_y_tabla.second; });

    delete ui;
}

void DialogoResultadoConsulta::volcar_datos(std::vector<modelo::Medio*> medios, std::vector<modelo::Concepto*> conceptos, std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados)
{
    this->completar_arboles(medios, conceptos, resultados);

    std::string string_fecha_minima = std::to_string((*resultados.begin())->getId()->numero());
    QDate qfecha_minima = QDate::fromString(string_fecha_minima.c_str(), "yyyyMMdd");
    this->ui->dateedit_desde->setDate(qfecha_minima);

    this->fecha_actual = herramientas::utiles::Fecha::parsearFormatoAAAAMMDD(string_fecha_minima);

    std::string string_fecha_maxima = std::to_string((*(resultados.end() - 1))->getId()->numero());
    QDate qfecha_maxima = QDate::fromString(string_fecha_maxima.c_str(), "yyyyMMdd");
    this->ui->dateedit_hasta->setDate(qfecha_maxima);

    this->ui->dias->setMinimum(qfecha_minima.toJulianDay());
    this->ui->dias->setMaximum(qfecha_maxima.toJulianDay());

    this->ui->calendario->setDateRange(qfecha_minima, qfecha_maxima);
    this->ui->calendario->setDate(qfecha_minima);

    this->mostrar_resultado(std::stoi(string_fecha_minima));
}

void DialogoResultadoConsulta::completar_arboles(std::vector<modelo::Medio*> medios, std::vector<modelo::Concepto*> conceptos, std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados) {
    
    // rescato los nombres de columnas(medios),
    QStringList etiquetas_medios("fecha-a-reemplazar");
    std::for_each(medios.begin(), medios.end(),
        [&etiquetas_medios](modelo::Medio * medio)
    {
        etiquetas_medios.push_back(QString(medio->getNombre().c_str()));
    });

    // y paso los resultados a la tabla.
    std::for_each(resultados.begin(), resultados.end(),
        [this, &conceptos, &etiquetas_medios, &medios](scraping::preparacion::ResultadoAnalisisDiario * resultado)
    {
        herramientas::utiles::ID * id_resultado = resultado->getId();

        // lleno los datos de los arboles
        herramientas::utiles::Fecha fecha_arbol = herramientas::utiles::Fecha::parsearFormatoAAAAMMDD(id_resultado->string());
        etiquetas_medios.pop_front();
        etiquetas_medios.push_front(fecha_arbol.getStringDDmesAAAA(" ").c_str());

        QTreeWidget * sentimiento = this->nuevo_arbol_sentimiento(id_resultado->numero(), etiquetas_medios);
        QTreeWidget * fuerza_en_noticia = this->nuevo_arbol_fuerza_en_noticia(id_resultado->numero(), etiquetas_medios);

        std::for_each(conceptos.begin(), conceptos.end(),
            [&resultado,
            &sentimiento,
            &fuerza_en_noticia,
            &medios,
            this]
        (modelo::Concepto * concepto)
        {
            QTreeWidgetItem * item_concepto_sentimiento = this->completar_sentimiento(concepto, medios, resultado);
            QTreeWidgetItem * item_concepto_fuerza_en_noticia = this->completar_fuerza_en_noticia(concepto, medios, resultado);

            std::vector<modelo::Termino*> terminos = concepto->getTerminos();
            std::for_each(terminos.begin(), terminos.end(),
                [&resultado,
                &medios,
                &item_concepto_sentimiento,
                &item_concepto_fuerza_en_noticia,
                this](modelo::Termino * termino)
            {
                QTreeWidgetItem * item_termino_sentimiento = this->completar_sentimiento(termino, medios, resultado);
                QTreeWidgetItem * item_termino_fuerza_en_noticia = this->completar_fuerza_en_noticia(termino, medios, resultado);

                item_concepto_sentimiento->addChild(item_termino_sentimiento);
                item_concepto_fuerza_en_noticia->addChild(item_termino_fuerza_en_noticia);
            });

            sentimiento->addTopLevelItem(item_concepto_sentimiento);
            fuerza_en_noticia->addTopLevelItem(item_concepto_fuerza_en_noticia);
        });
    });
}

QTreeWidgetItem * DialogoResultadoConsulta::completar_sentimiento(modelo::Concepto * concepto, std::vector<modelo::Medio*> medios, scraping::preparacion::ResultadoAnalisisDiario * resultados)
{
    std::vector<modelo::Termino*> terminos = concepto->getTerminos();

    QStringList valores_de_concepto_por_medio(concepto->getEtiqueta().c_str());

    std::for_each(medios.begin(), medios.end(),
        [&resultados, &terminos, &valores_de_concepto_por_medio](modelo::Medio * medio)
    {
        scraping::analisis::tecnicas::ResultadoSentimiento::sentimiento sentimiento_de_concepto_en_medio;

        std::for_each(terminos.begin(), terminos.end(),
            [&resultados, &medio, &sentimiento_de_concepto_en_medio](modelo::Termino * termino)
        {
            std::string expresion = termino->getValor();
            unsigned long long int id_medio = medio->getMedioAScrapear()->getId()->numero();

            sentimiento_de_concepto_en_medio += resultados->getResultadoMedio(id_medio)->getResultadoSentimiento()->valores(expresion);
        });

        valores_de_concepto_por_medio.push_back(sentimiento_de_concepto_en_medio.informar().c_str());
    });

    return new QTreeWidgetItem(valores_de_concepto_por_medio);
}

QTreeWidgetItem * DialogoResultadoConsulta::completar_fuerza_en_noticia(modelo::Concepto * concepto, std::vector<modelo::Medio*> medios, scraping::preparacion::ResultadoAnalisisDiario * resultados)
{
    std::vector<modelo::Termino*> terminos = concepto->getTerminos();

    QStringList valores_de_concepto_por_medio(concepto->getEtiqueta().c_str());

    std::for_each(medios.begin(), medios.end(),
        [&resultados, &terminos, &valores_de_concepto_por_medio](modelo::Medio * medio)
    {
        double fuerza_en_noticia_de_concepto_en_medio;

        std::for_each(terminos.begin(), terminos.end(),
            [&resultados, &medio, &fuerza_en_noticia_de_concepto_en_medio](modelo::Termino * termino)
        {
            std::string expresion = termino->getValor();
            unsigned long long int id_medio = medio->getMedioAScrapear()->getId()->numero();

            fuerza_en_noticia_de_concepto_en_medio += resultados->getResultadoMedio(id_medio)->getResultadoFuerzaEnNoticia()->getFuerza(expresion);
        });

        valores_de_concepto_por_medio.push_back(herramientas::utiles::FuncionesString::toString(fuerza_en_noticia_de_concepto_en_medio).c_str());
    });

    return new QTreeWidgetItem(valores_de_concepto_por_medio);
}

QTreeWidgetItem * DialogoResultadoConsulta::completar_sentimiento(modelo::Termino * termino, std::vector<modelo::Medio*> medios, scraping::preparacion::ResultadoAnalisisDiario * resultados)
{
    QStringList valores_de_termino_por_medio(termino->getValor().c_str());

    std::for_each(medios.begin(), medios.end(),
        [&resultados, &termino, &valores_de_termino_por_medio](modelo::Medio * medio)
    {
        std::string expresion = termino->getValor();
        unsigned long long int id_medio = medio->getMedioAScrapear()->getId()->numero();

        scraping::analisis::tecnicas::ResultadoSentimiento::sentimiento sentimiento_de_termino_en_medio = resultados->getResultadoMedio(id_medio)->getResultadoSentimiento()->valores(expresion);

        valores_de_termino_por_medio.push_back(sentimiento_de_termino_en_medio.informar().c_str());
    });

    return new QTreeWidgetItem(valores_de_termino_por_medio);
}

QTreeWidgetItem * DialogoResultadoConsulta::completar_fuerza_en_noticia(modelo::Termino * termino, std::vector<modelo::Medio*> medios, scraping::preparacion::ResultadoAnalisisDiario * resultados)
{
    QStringList valores_de_termino_por_medio(termino->getValor().c_str());

    std::for_each(medios.begin(), medios.end(),
        [&resultados, &termino, &valores_de_termino_por_medio](modelo::Medio * medio)
    {
        std::string expresion = termino->getValor();
        unsigned long long int id_medio = medio->getMedioAScrapear()->getId()->numero();

        double fuerza_en_noticia_de_termino_en_medio = resultados->getResultadoMedio(id_medio)->getResultadoFuerzaEnNoticia()->getFuerza(expresion);

        valores_de_termino_por_medio.push_back(herramientas::utiles::FuncionesString::toString(fuerza_en_noticia_de_termino_en_medio).c_str());
    });

    return new QTreeWidgetItem(valores_de_termino_por_medio);
}

QTreeWidget * DialogoResultadoConsulta::nuevo_arbol_sentimiento(const unsigned long long int & fecha, const QStringList & etiquetas_medios)
{
    QTreeWidget * sentimiento = new QTreeWidget(this->ui->pestania_2);

    QObject::connect(sentimiento, &QTreeWidget::itemCollapsed, this, &DialogoResultadoConsulta::colapsar_sentimiento);
    QObject::connect(sentimiento, &QTreeWidget::itemExpanded, this, &DialogoResultadoConsulta::expandir_sentimiento);

    sentimiento->move(this->ui->lbl_sin_valores_2->pos());
    this->ui->layout_pestania_2->addWidget(sentimiento);

    sentimiento->setHeaderLabels(etiquetas_medios);
    sentimiento->setColumnCount(etiquetas_medios.size());
    sentimiento->setSortingEnabled(true);
    sentimiento->setVisible(false);
    sentimiento->setSelectionMode(QAbstractItemView::SelectionMode::ContiguousSelection);

    this->sentimientos[fecha] = sentimiento;

    return sentimiento;
}

QTreeWidget * DialogoResultadoConsulta::nuevo_arbol_fuerza_en_noticia(const unsigned long long int & fecha, const QStringList & etiquetas_medios)
{
    QTreeWidget * fuerza_en_noticia = new QTreeWidget(this->ui->pestania_1);

    QObject::connect(fuerza_en_noticia, &QTreeWidget::itemCollapsed, this, &DialogoResultadoConsulta::colapsar_fuerza_en_noticia);
    QObject::connect(fuerza_en_noticia, &QTreeWidget::itemExpanded, this, &DialogoResultadoConsulta::expandir_fuerza_en_noticia);

    fuerza_en_noticia->move(this->ui->lbl_sin_valores_1->pos());
    this->ui->layout_pestania_1->addWidget(fuerza_en_noticia);

    fuerza_en_noticia->setHeaderLabels(etiquetas_medios);
    fuerza_en_noticia->setColumnCount(etiquetas_medios.size());
    fuerza_en_noticia->setSortingEnabled(true);
    fuerza_en_noticia->setVisible(false);
    fuerza_en_noticia->setSelectionMode(QAbstractItemView::SelectionMode::ContiguousSelection);

    this->fuerzas_en_noticia[fecha] = fuerza_en_noticia;

    return fuerza_en_noticia;
}

void DialogoResultadoConsulta::mostrar_resultado(int fecha) {

    if (this->fuerzas_en_noticia.count(fecha)) {
        this->fuerzas_en_noticia[fecha]->setVisible(true);
        this->fuerzas_en_noticia[fecha]->raise();
        this->ui->lbl_sin_valores_1->setVisible(false);
    }
    else {
        this->ui->lbl_sin_valores_1->setVisible(true);
        this->ui->lbl_sin_valores_1->raise();
    }

    if (this->sentimientos.count(fecha)) {
        this->sentimientos[fecha]->setVisible(true);
        this->fuerzas_en_noticia[fecha]->raise();
        this->ui->lbl_sin_valores_2->setVisible(false);
    }
    else {
        this->ui->lbl_sin_valores_2->setVisible(true);
        this->ui->lbl_sin_valores_2->raise();
    }
}

void DialogoResultadoConsulta::ocultar_resultado(int fecha) {

    if (this->fuerzas_en_noticia.count(fecha)) {
        this->fuerzas_en_noticia[fecha]->setVisible(false);
    }

    if (this->sentimientos.count(fecha)) {
        this->sentimientos[fecha]->setVisible(false);
    }
}

void DialogoResultadoConsulta::mostrar_resultado_dia(int dia) {

    herramientas::utiles::Fecha fecha_anterior = this->fecha_actual;

    QDate fecha = QDate::fromJulianDay(dia);

    this->fecha_actual = herramientas::utiles::Fecha(fecha.day(), fecha.month(), fecha.year());

    std::string string_fecha = herramientas::utiles::Fecha(fecha.day(), fecha.month(), fecha.year()).getStringAAAAMMDD();

    this->mostrar_resultado(std::stoi(fecha_actual.getStringAAAAMMDD()));

    this->ocultar_resultado(std::stoi(fecha_anterior.getStringAAAAMMDD()));

    this->ui->calendario->setDate(fecha);
}

void DialogoResultadoConsulta::colapsar_sentimiento(QTreeWidgetItem * item) {

    int indice = this->sentimientos[std::stoi(fecha_actual.getStringAAAAMMDD())]->indexOfTopLevelItem(item);

    if (indice < 0) {
        return;
    }

    std::for_each(this->sentimientos.begin(), this->sentimientos.end(),
        [&indice](std::pair<unsigned long long int, QTreeWidget*> fecha_sentimiento)
    {
        fecha_sentimiento.second->blockSignals(true);
        fecha_sentimiento.second->topLevelItem(indice)->setExpanded(false);
        fecha_sentimiento.second->blockSignals(false);
    });
}

void DialogoResultadoConsulta::expandir_sentimiento(QTreeWidgetItem * item) {

    int indice = this->sentimientos[std::stoi(fecha_actual.getStringAAAAMMDD())]->indexOfTopLevelItem(item);

    if (indice < 0) {
        return;
    }

    std::for_each(this->sentimientos.begin(), this->sentimientos.end(),
        [&indice](std::pair<unsigned long long int, QTreeWidget*> fecha_sentimiento)
    {
        fecha_sentimiento.second->blockSignals(true);
        fecha_sentimiento.second->topLevelItem(indice)->setExpanded(true);
        fecha_sentimiento.second->blockSignals(false);
    });
}

void DialogoResultadoConsulta::colapsar_fuerza_en_noticia(QTreeWidgetItem * item) {

    int indice = this->fuerzas_en_noticia[std::stoi(fecha_actual.getStringAAAAMMDD())]->indexOfTopLevelItem(item);

    if (indice < 0) {
        return;
    }

    std::for_each(this->fuerzas_en_noticia.begin(), this->fuerzas_en_noticia.end(),
        [&indice](std::pair<unsigned long long int, QTreeWidget*> fecha_fuerza_en_noticia)
    {
        fecha_fuerza_en_noticia.second->blockSignals(true);
        fecha_fuerza_en_noticia.second->topLevelItem(indice)->setExpanded(false);
        fecha_fuerza_en_noticia.second->blockSignals(false);
    });
}

void DialogoResultadoConsulta::expandir_fuerza_en_noticia(QTreeWidgetItem * item) {

    int indice = this->fuerzas_en_noticia[std::stoi(fecha_actual.getStringAAAAMMDD())]->indexOfTopLevelItem(item);

    if (indice < 0) {
        return;
    }

    std::for_each(this->fuerzas_en_noticia.begin(), this->fuerzas_en_noticia.end(),
        [&indice](std::pair<unsigned long long int, QTreeWidget*> fecha_fuerza_en_noticia)
    {
        fecha_fuerza_en_noticia.second->blockSignals(true);
        fecha_fuerza_en_noticia.second->topLevelItem(indice)->setExpanded(true);
        fecha_fuerza_en_noticia.second->blockSignals(false);
    });
}
//
//void DialogoResultadoConsulta::exportar(int fecha) {
//
//    QTreeWidget * fuerza_en_noticia = this->fuerzas_en_noticia[fecha];
//    QTreeWidget * sentimiento = this->sentimientos[fecha];
//
//    herramientas::utiles::Json json_fecha;
//
//    std::vector<herramientas::utiles::Json*> medios_en_fecha;
//    std::vector<herramientas::utiles::Json*> conceptos_de_medio;
//    std::vector<herramientas::utiles::Json*> terminos_de_concepto;
//
//    int cantidad_de_columnas = fuerza_en_noticia->columnCount();
//    for (unsigned int i_medios = 1; i_medios < cantidad_de_columnas; i_medios++) { // itero medios/columnas
//        std::string nombre_medio = fuerza_en_noticia->headerItem()->text(i_medios).toStdString();
//
//        herramientas::utiles::Json * json_medio = new herramientas::utiles::Json();
//        json_medio->agregarAtributoValor("nombre", nombre_medio);
//
//        int cantidad_de_conceptos = fuerza_en_noticia->topLevelItemCount();
//        for (unsigned int i_conceptos = 0; i_conceptos < cantidad_de_conceptos; i_conceptos++) { // itero conceptos/top level items
//
//            herramientas::utiles::Json * json_concepto = this->concepto_a_json(fuerza_en_noticia, sentimiento, i_conceptos, i_medios);
//
//            int cantidad_de_terminos = fuerza_en_noticia->topLevelItem(i_conceptos)->childCount();
//            for (unsigned int i_terminos = 0; i_terminos < cantidad_de_terminos; i_terminos++) { // itero terminos
//
//                herramientas::utiles::Json * json_termino = this->termino_a_json(fuerza_en_noticia, sentimiento, i_conceptos, i_terminos, i_medios);
//
//                terminos_de_concepto.push_back(json_termino);
//            }
//            json_concepto->agregarAtributoArray("terminos", terminos_de_concepto);
//            conceptos_de_medio.push_back(json_concepto);
//        }
//
//        json_medio->agregarAtributoArray("conceptos", conceptos_de_medio);
//        medios_en_fecha.push_back(json_medio);
//    }
//
//    json_fecha.agregarAtributoValor("fecha", static_cast<unsigned long long int>(fecha));
//    json_fecha.agregarAtributoArray("medios", medios_en_fecha);
//
//    std::string path_exportacion = "consulta_" + herramientas::utiles::Fecha::getFechaActual().getStringAAAAMMDDHHmmSS() + ".json";
//    herramientas::utiles::FuncionesSistemaArchivos::escribir(path_exportacion, json_fecha.jsonStringLindo());
//
//    std::for_each(medios_en_fecha.begin(), medios_en_fecha.end(), [](herramientas::utiles::Json * json_medio) { delete json_medio; });
//    std::for_each(conceptos_de_medio.begin(), conceptos_de_medio.end(), [](herramientas::utiles::Json * json_concepto) { delete json_concepto; });
//    std::for_each(terminos_de_concepto.begin(), terminos_de_concepto.end(), [](herramientas::utiles::Json * json_termino) { delete json_termino; });
//}

herramientas::utiles::Json * DialogoResultadoConsulta::fecha_a_json(int fecha) {

    if (0 == this->fuerzas_en_noticia.count(fecha)) { // si no existe la fecha, devuelvo false.
        return nullptr;
    }

    QTreeWidget * fuerza_en_noticia = this->fuerzas_en_noticia[fecha];
    QTreeWidget * sentimiento = this->sentimientos[fecha];

    std::vector<herramientas::utiles::Json*> medios_en_fecha;
    std::vector<herramientas::utiles::Json*> conceptos_de_medio;
    std::vector<herramientas::utiles::Json*> terminos_de_concepto;

    int cantidad_de_columnas = fuerza_en_noticia->columnCount();
    for (unsigned int i_medios = 1; i_medios < cantidad_de_columnas; i_medios++) { // itero medios/columnas
        std::string nombre_medio = fuerza_en_noticia->headerItem()->text(i_medios).toStdString();

        herramientas::utiles::Json * json_medio = new herramientas::utiles::Json();
        json_medio->agregarAtributoValor("nombre", nombre_medio);

        int cantidad_de_conceptos = fuerza_en_noticia->topLevelItemCount();
        for (unsigned int i_conceptos = 0; i_conceptos < cantidad_de_conceptos; i_conceptos++) { // itero conceptos/top level items

            herramientas::utiles::Json * json_concepto = this->concepto_a_json(fuerza_en_noticia, sentimiento, i_conceptos, i_medios);

            int cantidad_de_terminos = fuerza_en_noticia->topLevelItem(i_conceptos)->childCount();
            for (unsigned int i_terminos = 0; i_terminos < cantidad_de_terminos; i_terminos++) { // itero terminos

                herramientas::utiles::Json * json_termino = this->termino_a_json(fuerza_en_noticia, sentimiento, i_conceptos, i_terminos, i_medios);

                terminos_de_concepto.push_back(json_termino);
            }
            json_concepto->agregarAtributoArray("terminos", terminos_de_concepto);
            conceptos_de_medio.push_back(json_concepto);
        }

        json_medio->agregarAtributoArray("conceptos", conceptos_de_medio);
        medios_en_fecha.push_back(json_medio);
    }

    herramientas::utiles::Json json_fecha_aux;
    json_fecha_aux.agregarAtributoValor("fecha", static_cast<unsigned long long int>(fecha));
    json_fecha_aux.agregarAtributoArray("medios", medios_en_fecha);
    std::string string_json_fecha = json_fecha_aux.jsonString();

    std::for_each(medios_en_fecha.begin(), medios_en_fecha.end(), [](herramientas::utiles::Json * json_medio) { delete json_medio; });
    std::for_each(conceptos_de_medio.begin(), conceptos_de_medio.end(), [](herramientas::utiles::Json * json_concepto) { delete json_concepto; });
    std::for_each(terminos_de_concepto.begin(), terminos_de_concepto.end(), [](herramientas::utiles::Json * json_termino) { delete json_termino; });

    return new herramientas::utiles::Json(string_json_fecha);
}

herramientas::utiles::Json * DialogoResultadoConsulta::concepto_a_json(QTreeWidget * fuerza_en_noticia, QTreeWidget * sentimiento, int idx_concepto, int idx_medio)
{
    QTreeWidgetItem * fuerza_en_noticia_item_concepto = fuerza_en_noticia->topLevelItem(idx_concepto);
    QTreeWidgetItem * sentimiento_item_concepto = sentimiento->topLevelItem(idx_concepto);

    std::string nombre_concepto = fuerza_en_noticia_item_concepto->text(0).toStdString();
    std::string fuerza_en_noticia_valor_concepto_en_medio = fuerza_en_noticia_item_concepto->text(idx_medio).toStdString();
    std::string sentimiento_valor_concepto_en_medio = sentimiento_item_concepto->text(idx_medio).toStdString();

    herramientas::utiles::Json * json_concepto = new herramientas::utiles::Json();
    json_concepto->agregarAtributoValor("nombre", nombre_concepto);
    json_concepto->agregarAtributoValor("fuerza_en_noticia", std::stof(fuerza_en_noticia_valor_concepto_en_medio));
    json_concepto->agregarAtributoValor("sentimiento", sentimiento_valor_concepto_en_medio);

    return json_concepto;
}

herramientas::utiles::Json * DialogoResultadoConsulta::termino_a_json(QTreeWidget* fuerza_en_noticia, QTreeWidget * sentimiento, int idx_concepto, int idx_termino, int idx_medio)
{
    QTreeWidgetItem * fuerza_en_noticia_item_termino = fuerza_en_noticia->topLevelItem(idx_concepto)->child(idx_termino);
    QTreeWidgetItem * sentimiento_item_termino = sentimiento->topLevelItem(idx_concepto)->child(idx_termino);

    std::string nombre_termino = fuerza_en_noticia_item_termino->text(0).toStdString();
    std::string fuerza_en_noticia_valor_termino_en_medio = fuerza_en_noticia_item_termino->text(idx_medio).toStdString();
    std::string sentimiento_valor_termino_en_medio = sentimiento_item_termino->text(idx_medio).toStdString();

    herramientas::utiles::Json * json_termino = new herramientas::utiles::Json();
    json_termino->agregarAtributoValor("nombre", nombre_termino);
    json_termino->agregarAtributoValor("fuerza_en_noticia", std::stof(fuerza_en_noticia_valor_termino_en_medio));
    json_termino->agregarAtributoValor("sentimiento", sentimiento_valor_termino_en_medio);

    return json_termino;
}

void DialogoResultadoConsulta::exportar_actual() {

    QFuture<void> tarea_exportacion = QtConcurrent::run([this]() {

        std::string string_fecha_actual = this->fecha_actual.getStringAAAAMMDD();

        herramientas::utiles::Json json_consulta;

        herramientas::utiles::Json * json_fecha_actual = this->fecha_a_json(std::stoi(string_fecha_actual));

        std::vector<herramientas::utiles::Json*> json_fechas = { json_fecha_actual };

        json_consulta.agregarAtributoArray("fechas", json_fechas);

        std::string path_exportacion = "consulta_" + herramientas::utiles::Fecha::getFechaActual().getStringAAAAMMDDHHmmSS() + ".json";
        herramientas::utiles::FuncionesSistemaArchivos::escribir(path_exportacion, json_consulta.jsonStringLindo());

        std::for_each(json_fechas.begin(), json_fechas.end(), [](herramientas::utiles::Json * json_fecha) { delete json_fecha; });
    });

    this->observador_exportacion.setFuture(tarea_exportacion);
}

void DialogoResultadoConsulta::exportar_todo() {

    QFuture<void> tarea_exportacion = QtConcurrent::run([this]() {

        herramientas::utiles::Json json_consulta;

        std::vector<herramientas::utiles::Json*> json_fechas;
        std::for_each(this->fuerzas_en_noticia.begin(), this->fuerzas_en_noticia.end(),
            [this, &json_fechas](std::pair<unsigned long long int, QTreeWidget*> fecha_arbol) {

            herramientas::utiles::Json * json_fecha = this->fecha_a_json(fecha_arbol.first);
            json_fechas.push_back(json_fecha);
        });

        json_consulta.agregarAtributoArray("fechas", json_fechas);

        std::string path_exportacion = "consulta_" + herramientas::utiles::Fecha::getFechaActual().getStringAAAAMMDDHHmmSS() + ".json";
        herramientas::utiles::FuncionesSistemaArchivos::escribir(path_exportacion, json_consulta.jsonStringLindo());

        std::for_each(json_fechas.begin(), json_fechas.end(), [](herramientas::utiles::Json * json_fecha) { delete json_fecha; });
    });

    this->observador_exportacion.setFuture(tarea_exportacion);
}

void DialogoResultadoConsulta::exportar_rango() {

    QFuture<void> tarea_exportacion = QtConcurrent::run([this]() {

        herramientas::utiles::Json json_consulta;

        std::vector<herramientas::utiles::Json*> json_fechas;

        for (unsigned int i = this->ui->dateedit_desde->date().toJulianDay(); i < this->ui->dateedit_hasta->date().toJulianDay(); i++) {
            std::string string_fecha = QDate::fromJulianDay(i).toString("yyyyMMdd").toStdString();

            herramientas::utiles::Json * json_fecha = this->fecha_a_json(std::stoi(string_fecha));

            if (json_fecha) {
                json_fechas.push_back(json_fecha);
            }
        }

        json_consulta.agregarAtributoArray("fechas", json_fechas);

        std::string path_exportacion = "consulta_" + herramientas::utiles::Fecha::getFechaActual().getStringAAAAMMDDHHmmSS() + ".json";
        herramientas::utiles::FuncionesSistemaArchivos::escribir(path_exportacion, json_consulta.jsonStringLindo());

        std::for_each(json_fechas.begin(), json_fechas.end(), [](herramientas::utiles::Json * json_fecha) { delete json_fecha; });
    });

    this->observador_exportacion.setFuture(tarea_exportacion);
}

void DialogoResultadoConsulta::habilitar_exportar_botones() {

    this->ui->widget_exportar_botones->setEnabled(true);
}

void DialogoResultadoConsulta::deshabilitar_exportar_botones() {

    this->ui->widget_exportar_botones->setDisabled(true);
}

void DialogoResultadoConsulta::conectar_componentes() {

    QObject::connect(this->ui->dias, &QAbstractSlider::valueChanged, this, &DialogoResultadoConsulta::mostrar_resultado_dia);

    QObject::connect(this->ui->btn_exportar_fecha_actual, &QPushButton::released, this, &DialogoResultadoConsulta::exportar_actual);
    QObject::connect(this->ui->btn_exportar_todo, &QPushButton::released, this, &DialogoResultadoConsulta::exportar_todo);
    QObject::connect(this->ui->btn_exportar_rango, &QPushButton::released, this, &DialogoResultadoConsulta::exportar_rango);

    QObject::connect(&(this->observador_exportacion), &QFutureWatcher<void>::started, this, &DialogoResultadoConsulta::deshabilitar_exportar_botones);
    QObject::connect(&(this->observador_exportacion), &QFutureWatcher<void>::started, this->ui->progressbar_exportacion, &QProgressBar::show);
    QObject::connect(&(this->observador_exportacion), &QFutureWatcher<void>::finished, this, &DialogoResultadoConsulta::habilitar_exportar_botones);
    QObject::connect(&(this->observador_exportacion), &QFutureWatcher<void>::finished, this->ui->progressbar_exportacion, &QProgressBar::hide);
    QObject::connect(&(this->observador_exportacion), &QFutureWatcher<void>::progressValueChanged, this->ui->progressbar_exportacion, &QProgressBar::valueChanged);
}