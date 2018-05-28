#include "DialogoResultadoConsulta.h"
#include "ui_DialogoResultadoConsulta.h"

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

DialogoResultadoConsulta::~DialogoResultadoConsulta()
{
    std::for_each(this->sentimientos.begin(), this->sentimientos.end(), [](std::pair<unsigned long long int, QTreeWidget*> id_y_tabla) { delete id_y_tabla.second; });
    std::for_each(this->fuerzas_en_noticia.begin(), this->fuerzas_en_noticia.end(), [](std::pair<unsigned long long int, QTreeWidget*> id_y_tabla) { delete id_y_tabla.second; });

    delete ui;
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

void DialogoResultadoConsulta::exportar(int fecha) {

    QTreeWidget * fuerza_en_noticia = this->fuerzas_en_noticia[fecha];
    QTreeWidget * sentimimento = this->sentimientos[fecha];

    herramientas::utiles::Json json_fecha;

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
            QTreeWidgetItem * fuerza_en_noticia_item_concepto = fuerza_en_noticia->topLevelItem(i_conceptos);
            QTreeWidgetItem * sentimiento_item_concepto = sentimimento->topLevelItem(i_conceptos);

            std::string nombre_concepto = fuerza_en_noticia_item_concepto->text(0).toStdString();
            std::string fuerza_en_noticia_valor_concepto_en_medio = fuerza_en_noticia_item_concepto->text(i_medios).toStdString();
            std::string sentimiento_valor_concepto_en_medio = sentimiento_item_concepto->text(i_medios).toStdString();

            herramientas::utiles::Json * json_concepto = new herramientas::utiles::Json();
            json_concepto->agregarAtributoValor("nombre", nombre_concepto);
            json_concepto->agregarAtributoValor("fuerza_en_noticia", std::stof(fuerza_en_noticia_valor_concepto_en_medio));
            json_concepto->agregarAtributoValor("sentimiento", sentimiento_valor_concepto_en_medio);

            int cantidad_de_terminos = fuerza_en_noticia_item_concepto->childCount();
            for (unsigned int i_terminos = 0; i_terminos < cantidad_de_terminos; i_terminos++) { // itero terminos
                QTreeWidgetItem * fuerza_en_noticia_item_termino = fuerza_en_noticia_item_concepto->child(i_terminos);
                QTreeWidgetItem * sentimiento_item_termino = sentimiento_item_concepto->child(i_terminos);

                std::string nombre_termino = fuerza_en_noticia_item_termino->text(0).toStdString();
                std::string fuerza_en_noticia_valor_termino_en_medio = fuerza_en_noticia_item_termino->text(i_medios).toStdString();
                std::string sentimiento_valor_termino_en_medio = sentimiento_item_termino->text(i_medios).toStdString();

                herramientas::utiles::Json * json_termino = new herramientas::utiles::Json();
                json_termino->agregarAtributoValor("nombre", nombre_termino);
                json_termino->agregarAtributoValor("fuerza_en_noticia", std::stof(fuerza_en_noticia_valor_termino_en_medio));
                json_termino->agregarAtributoValor("sentimiento", sentimiento_valor_termino_en_medio);
                terminos_de_concepto.push_back(json_termino);
            }
            json_concepto->agregarAtributoArray("terminos", terminos_de_concepto);
            conceptos_de_medio.push_back(json_concepto);
        }

        json_medio->agregarAtributoArray("conceptos", conceptos_de_medio);
        medios_en_fecha.push_back(json_medio);
    }

    json_fecha.agregarAtributoValor("fecha", static_cast<unsigned long long int>(fecha));
    json_fecha.agregarAtributoArray("medios", medios_en_fecha);

    std::string path_exportacion = "consulta_" + herramientas::utiles::Fecha::getFechaActual().getStringAAAAMMDDHHmmSS() + ".json";
    herramientas::utiles::FuncionesSistemaArchivos::escribir(path_exportacion, json_fecha.jsonStringLindo());

    std::for_each(medios_en_fecha.begin(), medios_en_fecha.end(), [](herramientas::utiles::Json * json_medio) { delete json_medio; });
    std::for_each(conceptos_de_medio.begin(), conceptos_de_medio.end(), [](herramientas::utiles::Json * json_concepto) { delete json_concepto; });
    std::for_each(terminos_de_concepto.begin(), terminos_de_concepto.end(), [](herramientas::utiles::Json * json_termino) { delete json_termino; });
}

void DialogoResultadoConsulta::exportar_actual() {

    std::string string_fecha_actual = this->fecha_actual.getStringAAAAMMDD();
    this->exportar(std::stoi(string_fecha_actual));
    this->fechas_exportadas.push_back(std::stoi(string_fecha_actual));
}

void DialogoResultadoConsulta::exportar_todo() {

    std::for_each(this->fuerzas_en_noticia.begin(), this->fuerzas_en_noticia.end(),
        [this](std::pair<unsigned long long int, QTreeWidget*> fecha_arbol)
    {
        if (std::count(this->fechas_exportadas.begin(), this->fechas_exportadas.end(), fecha_arbol.first)) {

        }
        else {
            this->exportar(fecha_arbol.first);
            this->fechas_exportadas.push_back(fecha_arbol.first);
        }
    });
}

void DialogoResultadoConsulta::exportar_rango() {



    for (unsigned int i = this->ui->dateedit_desde->date().toJulianDay(); i < this->ui->dateedit_hasta->date().toJulianDay(); i++) {
        std::string string_fecha = QDate::fromJulianDay(i).toString("yyyyMMdd").toStdString();

        this->exportar(std::stoi(string_fecha));
    }
}

void DialogoResultadoConsulta::conectar_componentes() {

    QObject::connect(this->ui->dias, &QAbstractSlider::valueChanged, this, &DialogoResultadoConsulta::mostrar_resultado_dia);
    QObject::connect(this->ui->btn_exportar_fecha_actual, &QPushButton::released, this, &DialogoResultadoConsulta::exportar_actual);
    QObject::connect(this->ui->btn_exportar_todo, &QPushButton::released, this, &DialogoResultadoConsulta::exportar_todo);
    QObject::connect(this->ui->btn_exportar_rango, &QPushButton::released, this, &DialogoResultadoConsulta::exportar_rango);
}