#include "DialogoResultadoConsulta.h"
#include "ui_DialogoResultadoConsulta.h"

// stl
#include <unordered_map>

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

DialogoResultadoConsulta::DialogoResultadoConsulta(QWidget *parent) : QWidget(parent) {

    ui = new Ui::DialogoResultadoConsulta();
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->conectar_componentes();

    this->meses_con_treinta_dias = std::vector<unsigned int>{ 4, 6, 9, 11 };
    this->nombres_columnas_csv = { "nombre", "medio", "seccion", "termino", "es_concepto", "apariciones", "porcentaje", "fuerza", "positividad", "negatividad", "neutralidad", "fecha" };

    this->ui->progressbar_exportacion->hide();
}


DialogoResultadoConsulta::DialogoResultadoConsulta(
    std::vector<modelo::Medio*> medios,
    std::vector<modelo::Concepto*> conceptos,
    std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados,
    const info_consulta& info,
    QWidget *parent)
    : medios(medios), conceptos(conceptos), resultados(resultados), spinner(this, false, false), info(info), QWidget(parent)
{
    ui = new Ui::DialogoResultadoConsulta();
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->conectar_componentes();

    this->meses_con_treinta_dias = std::vector<unsigned int>{ 4, 6, 9, 11 };
    this->nombres_columnas_csv = { "nombre", "medio", "seccion", "termino", "es_concepto", "apariciones", "porcentaje", "fuerza", "positividad", "negatividad", "neutralidad", "fecha" };

    this->ui->progressbar_exportacion->hide();

    this->ui->layout_exportar->addWidget(&this->spinner);
    this->spinner.setColor(QColor(61, 174, 233));
    this->spinner.setLineLength(3);
    this->spinner.setLineWidth(3);
    this->spinner.setInnerRadius(5);

    if (false == info.conceptos) {
        this->ui->analisis->removeTab(3);
    }
    if (false == info.tendencias) {
        this->ui->analisis->removeTab(2);
    }
    this->ui->analisis->removeTab(1);
    this->ui->analisis->removeTab(0);

    this->volcar_datos(medios, conceptos, resultados);
}

DialogoResultadoConsulta::~DialogoResultadoConsulta() {
    std::for_each(this->sentimientos.begin(), this->sentimientos.end(), [](std::pair<unsigned long long int, QTreeWidget*> id_y_tabla) { delete id_y_tabla.second; });
    std::for_each(this->fuerzas_en_noticia.begin(), this->fuerzas_en_noticia.end(), [](std::pair<unsigned long long int, QTreeWidget*> id_y_tabla) { delete id_y_tabla.second; });
    std::for_each(this->tendencias.begin(), this->tendencias.end(), [](std::pair<unsigned long long int, std::vector<QWidget*>> id_y_tabla) { 
        std::for_each(id_y_tabla.second.begin(), id_y_tabla.second.end(), [=](QWidget* widget) { delete widget; });
    });
    std::for_each(this->resultados_por_conceptos.begin(), this->resultados_por_conceptos.end(), [](std::pair<unsigned long long int, std::vector<QWidget*>> id_y_arbol) {
        std::for_each(id_y_arbol.second.begin(), id_y_arbol.second.end(), [=](QWidget* widget) { delete widget; });
    });
    delete ui;
}

void DialogoResultadoConsulta::volcar_datos(const std::vector<modelo::Medio*>& medios, const std::vector<modelo::Concepto*>& conceptos, const std::vector<scraping::preparacion::ResultadoAnalisisDiario*>& resultados)
{
    if (this->info.conceptos) {
        this->completar_resultados_por_concepto(conceptos, medios, resultados);
    }

    if (this->info.tendencias) {
        this->completar_tendencias(medios, resultados);
    }
    //this->completar_arboles(medios, conceptos, resultados);

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


void DialogoResultadoConsulta::completar_resultados_por_concepto(const std::vector<modelo::Concepto*> & conceptos, const std::vector<modelo::Medio*>& medios, const std::vector<scraping::preparacion::ResultadoAnalisisDiario*>& resultados) {

    std::for_each(resultados.begin(), resultados.end(),
        [=](scraping::preparacion::ResultadoAnalisisDiario * resultado) {

        std::for_each(medios.begin(), medios.end(), [=](modelo::Medio* medio) {
            this->nuevo_arbol_medio(conceptos, medio, resultado);
        });
    });
}

void DialogoResultadoConsulta::completar_tendencias(const std::vector<modelo::Medio*>& medios, const std::vector<scraping::preparacion::ResultadoAnalisisDiario*>& resultados) {
	std::for_each(resultados.begin(), resultados.end(),
		[=](scraping::preparacion::ResultadoAnalisisDiario * resultado) {

		std::for_each(medios.begin(), medios.end(), [=](modelo::Medio* medio) {
			this->nueva_tendencia(medio, resultado);
		});
	});
}

//void DialogoResultadoConsulta::completar_arboles(const std::vector<modelo::Medio*>& medios, const std::vector<modelo::Concepto*>& conceptos, const std::vector<scraping::preparacion::ResultadoAnalisisDiario*>& resultados) {
//    
//    // y paso los resultados a la tabla.
//    std::for_each(resultados.begin(), resultados.end(),
//        [this, &conceptos, &medios](scraping::preparacion::ResultadoAnalisisDiario * resultado)
//    {
//        herramientas::utiles::ID * id_resultado = resultado->getId();
//
//        // lleno los datos de los arboles
//        herramientas::utiles::Fecha fecha_arbol = herramientas::utiles::Fecha::parsearFormatoAAAAMMDD(id_resultado->string());
//
//        QTreeWidget * sentimiento = this->nuevo_arbol_sentimiento(id_resultado->numero(), medios);
//        QTreeWidget * fuerza_en_noticia = this->nuevo_arbol_fuerza_en_noticia(id_resultado->numero(), medios);
//
//        std::for_each(conceptos.begin(), conceptos.end(),
//            [&resultado,
//            &sentimiento,
//            &fuerza_en_noticia,
//            &medios,
//            this]
//        (modelo::Concepto * concepto)
//        {
//            QTreeWidgetItem * item_concepto_sentimiento = this->completar_sentimiento(concepto, medios, resultado);
//            QTreeWidgetItem * item_concepto_fuerza_en_noticia = this->completar_fuerza_en_noticia(concepto, medios, resultado);
//
//            std::vector<modelo::Termino*> terminos = concepto->getTerminos();
//            std::for_each(terminos.begin(), terminos.end(),
//                [&resultado,
//                &medios,
//                &item_concepto_sentimiento,
//                &item_concepto_fuerza_en_noticia,
//                this](modelo::Termino * termino)
//            {
//                QTreeWidgetItem * item_termino_sentimiento = this->completar_sentimiento(termino, medios, resultado);
//                QTreeWidgetItem * item_termino_fuerza_en_noticia = this->completar_fuerza_en_noticia(termino, medios, resultado);
//
//                item_concepto_sentimiento->addChild(item_termino_sentimiento);
//                item_concepto_fuerza_en_noticia->addChild(item_termino_fuerza_en_noticia);
//            });
//
//            sentimiento->addTopLevelItem(item_concepto_sentimiento);
//            fuerza_en_noticia->addTopLevelItem(item_concepto_fuerza_en_noticia);
//        });
//    });
//}

//QTreeWidgetItem * DialogoResultadoConsulta::completar_sentimiento(modelo::Concepto * concepto, std::vector<modelo::Medio*> medios, scraping::preparacion::ResultadoAnalisisDiario * resultados)
//{
//    std::vector<modelo::Termino*> terminos = concepto->getTerminos();
//
//    QStringList valores_de_concepto_por_medio(concepto->getEtiqueta().c_str());
//
//    std::for_each(medios.begin(), medios.end(),
//        [&resultados, &terminos, &valores_de_concepto_por_medio](modelo::Medio * medio)
//    {
//        scraping::analisis::tecnicas::ResultadoSentimiento::sentimiento sentimiento_de_concepto_en_medio;
//
//        std::for_each(terminos.begin(), terminos.end(),
//            [&resultados, &medio, &sentimiento_de_concepto_en_medio](modelo::Termino * termino)
//        {
//            std::string expresion = termino->getValor();
//            unsigned long long int id_medio = medio->getId()->numero();
//
//            scraping::preparacion::ResultadoAnalisisMedio * resultado_medio = resultados->getResultadoMedio(id_medio);
//
//            if (resultado_medio) {
//                scraping::analisis::tecnicas::ResultadoSentimiento resultado;
//                resultado_medio->sentimiento_de_categoria(&resultado, medio->seccion());
//                sentimiento_de_concepto_en_medio += resultado.valores(expresion);
//            }
//        });
//
//        valores_de_concepto_por_medio.push_back(sentimiento_de_concepto_en_medio.informar().c_str());
//    });
//
//    return new QTreeWidgetItem(valores_de_concepto_por_medio);
//}

//QTreeWidgetItem * DialogoResultadoConsulta::completar_fuerza_en_noticia(modelo::Concepto * concepto, std::vector<modelo::Medio*> medios, scraping::preparacion::ResultadoAnalisisDiario * resultados)
//{
//    std::vector<modelo::Termino*> terminos = concepto->getTerminos();
//
//    QStringList valores_de_concepto_por_medio(concepto->getEtiqueta().c_str());
//
//    std::for_each(medios.begin(), medios.end(),
//        [&resultados, &terminos, &valores_de_concepto_por_medio](modelo::Medio * medio)
//    {
//        double fuerza_en_noticia_de_concepto_en_medio = 0.0f;
//
//        std::for_each(terminos.begin(), terminos.end(),
//            [&resultados, &medio, &fuerza_en_noticia_de_concepto_en_medio](modelo::Termino * termino)
//        {
//            std::string expresion = termino->getValor();
//            unsigned long long int id_medio = medio->getId()->numero();
//
//            scraping::preparacion::ResultadoAnalisisMedio * resultado_medio = resultados->getResultadoMedio(id_medio);
//
//            if (resultado_medio) {
//                scraping::analisis::tecnicas::ResultadoFuerzaEnNoticia resultado;
//                resultado_medio->fuerza_en_noticia_de_categoria(&resultado, medio->seccion());
//                fuerza_en_noticia_de_concepto_en_medio += resultado.getFuerza(expresion);
//            }
//        });
//
//        valores_de_concepto_por_medio.push_back(herramientas::utiles::FuncionesString::toString(fuerza_en_noticia_de_concepto_en_medio).c_str());
//    });
//
//    return new QTreeWidgetItem(valores_de_concepto_por_medio);
//}

//QTreeWidgetItem * DialogoResultadoConsulta::completar_sentimiento(modelo::Termino * termino, std::vector<modelo::Medio*> medios, scraping::preparacion::ResultadoAnalisisDiario * resultados)
//{
//    QStringList valores_de_termino_por_medio(termino->getValor().c_str());
//
//    std::for_each(medios.begin(), medios.end(),
//        [&resultados, &termino, &valores_de_termino_por_medio](modelo::Medio * medio)
//    {
//        std::string expresion = termino->getValor();
//        unsigned long long int id_medio = medio->getId()->numero();
//
//        scraping::preparacion::ResultadoAnalisisMedio * resultado_medio = resultados->getResultadoMedio(id_medio);
//
//        scraping::analisis::tecnicas::ResultadoSentimiento::sentimiento sentimiento_de_termino_en_medio;
//        if (resultado_medio) {
//            scraping::analisis::tecnicas::ResultadoSentimiento resultado;
//            resultado_medio->sentimiento_de_categoria(&resultado, medio->seccion());
//            sentimiento_de_termino_en_medio = resultado.valores(expresion);
//        }
//
//        valores_de_termino_por_medio.push_back(sentimiento_de_termino_en_medio.informar().c_str());
//    });
//
//    return new QTreeWidgetItem(valores_de_termino_por_medio);
//}
//
//QTreeWidgetItem * DialogoResultadoConsulta::completar_fuerza_en_noticia(modelo::Termino * termino, std::vector<modelo::Medio*> medios, scraping::preparacion::ResultadoAnalisisDiario * resultados)
//{
//    QStringList valores_de_termino_por_medio(termino->getValor().c_str());
//
//    std::for_each(medios.begin(), medios.end(),
//        [&resultados, &termino, &valores_de_termino_por_medio](modelo::Medio * medio)
//    {
//        std::string expresion = termino->getValor();
//        unsigned long long int id_medio = medio->getId()->numero();
//
//        scraping::preparacion::ResultadoAnalisisMedio * resultado_medio = resultados->getResultadoMedio(id_medio);
//
//        double fuerza_en_noticia_de_termino_en_medio = 0.0f;
//        if (resultado_medio) {
//            scraping::analisis::tecnicas::ResultadoFuerzaEnNoticia resultado;
//            resultado_medio->fuerza_en_noticia_de_categoria(&resultado, medio->seccion());
//            fuerza_en_noticia_de_termino_en_medio = resultado.getFuerza(expresion);
//        }
//
//        valores_de_termino_por_medio.push_back(herramientas::utiles::FuncionesString::toString(fuerza_en_noticia_de_termino_en_medio).c_str());
//    });
//
//    return new QTreeWidgetItem(valores_de_termino_por_medio);
//}

void DialogoResultadoConsulta::nueva_tendencia(modelo::Medio* medio, scraping::preparacion::ResultadoAnalisisDiario * resultado) {
    QTableWidget * tendencia = new QTableWidget(this->ui->pestania_3);
    tendencia->setSortingEnabled(false);
    tendencia->setEditTriggers(QAbstractItemView::NoEditTriggers);

    tendencia->setAlternatingRowColors(true);
    tendencia->setColumnCount(7);
    tendencia->setHorizontalHeaderLabels({ "palabra", "menciones", "porcentaje", "fuerza", "sentimiento", "tipo", "seccion" });
    tendencia->hideColumn(5);
    tendencia->hideColumn(6);

    tendencia->horizontalHeader()->setVisible(true);
    tendencia->horizontalHeader()->setContentsMargins(0, 0, 0, 0);
    tendencia->horizontalHeader()->setDefaultAlignment(Qt::AlignmentFlag::AlignLeft);
    tendencia->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents);
    tendencia->horizontalHeader()->setStretchLastSection(true);

    tendencia->verticalHeader()->setVisible(false);
    tendencia->verticalHeader()->setDefaultSectionSize(20);

    scraping::preparacion::ResultadoAnalisisMedio * resultado_medio = resultado->getResultadoMedio(medio->getId()->numero());
    if (resultado_medio) {
        std::vector<std::string> top_terminos;

        scraping::analisis::tecnicas::ResultadoFuerzaEnNoticia resultado_fuerzas;
        resultado_medio->fuerza_en_noticia_de_categoria(&resultado_fuerzas, medio->seccion());
        if (this->info.orden == info_consulta::FUERZA) {
            std::vector<std::pair<std::string, float>> fuerzas;
            fuerzas = resultado_fuerzas.getTop(this->info.top_tendencias);
            std::for_each(fuerzas.begin(), fuerzas.end(), [&top_terminos](std::pair<std::string, float> termino_fuerza) {
                top_terminos.push_back(termino_fuerza.first);
            });
        }

        scraping::analisis::tecnicas::ResultadoSentimiento resultado_sentimiento;
        resultado_medio->sentimiento_de_categoria(&resultado_sentimiento, medio->seccion());
        if (this->info.orden == info_consulta::APARICIONES) {
            std::vector<std::pair<std::string, scraping::analisis::tecnicas::ResultadoSentimiento::sentimiento>> top_sentimientos;
            resultado_sentimiento.top(&top_sentimientos, this->info.top_tendencias);
            std::for_each(top_sentimientos.begin(), top_sentimientos.end(), [&top_terminos](std::pair<std::string, scraping::analisis::tecnicas::ResultadoSentimiento::sentimiento> top_sentimientos) {
                top_terminos.push_back(top_sentimientos.first);
            });
        }

        tendencia->setRowCount(top_terminos.size());

        double_t fuerza_total = resultado_fuerzas.getFuerzaTotal();
        uint32_t fila = 0;
        std::for_each(top_terminos.begin(), top_terminos.end(), [=, &fila, &resultado_fuerzas](std::string termino) {
            float fuerza = resultado_fuerzas.getFuerza(termino);
            scraping::analisis::tecnicas::ResultadoSentimiento resultado_sentimiento;
            std::string sentimiento = "";
            if (resultado_medio->sentimiento_de_categoria(&resultado_sentimiento, medio->seccion())) {
                sentimiento = resultado_sentimiento.valores(termino).informar();
            }

            tendencia->setItem(fila, 0, new QTableWidgetItem(termino.c_str()));
            tendencia->setItem(fila, 1, new QTableWidgetItem(herramientas::utiles::FuncionesString::toString(resultado_sentimiento.valores(termino).total(), 0).c_str()));
            tendencia->setItem(fila, 2, new QTableWidgetItem((herramientas::utiles::FuncionesString::toString((fuerza / fuerza_total) * 100, 0) + "%").c_str()));
            tendencia->setItem(fila, 3, new QTableWidgetItem(herramientas::utiles::FuncionesString::toString(fuerza).c_str()));
            tendencia->setItem(fila, 4, new QTableWidgetItem(sentimiento.c_str()));
            tendencia->setItem(fila, 5, new QTableWidgetItem(this->tipo_medio(medio).c_str()));
            tendencia->setItem(fila, 6, new QTableWidgetItem(medio->seccion().c_str()));

            fila++;
        });
    }
    
    QVBoxLayout * layout_tendencia = new QVBoxLayout(this->ui->pestania_3);
    layout_tendencia->setContentsMargins(QMargins(0, 0, 0, 0));
    layout_tendencia->setSpacing(0);

    QWidget * widget_tendencia = new QWidget(this->ui->pestania_3);
    widget_tendencia->setLayout(layout_tendencia);
    widget_tendencia->setVisible(false);

    QHBoxLayout * layout_etiqueta = new QHBoxLayout(this->ui->pestania_3);
    layout_etiqueta->setContentsMargins(QMargins(1, 1, 1, 1));
    layout_etiqueta->setSpacing(1);
    layout_etiqueta->setAlignment(Qt::AlignLeft);

    QWidget * widget_etiqueta = new QWidget(this->ui->pestania_3);
    widget_etiqueta->setLayout(layout_etiqueta);

    QLabel * etiqueta = new QLabel(medio->getNombre().c_str(), this->ui->pestania_3);
    QLabel * icono = new QLabel(this->ui->pestania_3);

    icono->setPixmap(QIcon(this->path_icono(medio).c_str()).pixmap(QSize(16, 16)));
    layout_etiqueta->addWidget(icono);
    layout_etiqueta->addWidget(etiqueta);

    layout_tendencia->addWidget(widget_etiqueta);
    layout_tendencia->addWidget(tendencia);

    this->ui->layout_pestania_3->addWidget(widget_tendencia);
    (&this->tendencias[resultado->getId()->numero()])->push_back(widget_tendencia);
    (&this->tablas_tendencias[resultado->getId()->numero()])->push_back(std::make_pair(medio->getNombre(),tendencia));
}

void DialogoResultadoConsulta::nuevo_arbol_medio(const std::vector<modelo::Concepto*> &conceptos, modelo::Medio* medio, scraping::preparacion::ResultadoAnalisisDiario* resultado) {
    QTreeWidget * arbol = new QTreeWidget(this->ui->pestania_4);

    arbol->setEditTriggers(QAbstractItemView::NoEditTriggers);
    arbol->setColumnCount(7);
    arbol->setHeaderLabels({ "palabra", "menciones", "porcentaje", "fuerza", "sentimiento", "tipo", "seccion" });
    arbol->setAlternatingRowColors(true);
    arbol->hideColumn(5);
    arbol->hideColumn(6);

    arbol->header()->setVisible(true);
    arbol->header()->setContentsMargins(0, 0, 0, 0);
    arbol->header()->setDefaultAlignment(Qt::AlignmentFlag::AlignLeft);
    arbol->header()->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents);
    arbol->header()->setStretchLastSection(true);

    arbol->setSortingEnabled(false);
    arbol->setSelectionMode(QAbstractItemView::SelectionMode::ContiguousSelection);

    std::for_each(conceptos.begin(), conceptos.end(), [=](modelo::Concepto * concepto) {
        QTreeWidgetItem * fila_concepto = this->completar_fila_arbol(concepto, medio, resultado);

        std::vector<modelo::Termino*> terminos = concepto->getTerminos();
        std::for_each(terminos.begin(), terminos.end(), [=](modelo::Termino* termino) {
            QTreeWidgetItem * fila_termino = this->completar_fila_arbol(termino, medio, resultado);
            fila_concepto->addChild(fila_termino);
        });

        arbol->addTopLevelItem(fila_concepto);
    });

    QVBoxLayout * layout_conceptos = new QVBoxLayout(this->ui->pestania_4);
    layout_conceptos->setContentsMargins(QMargins(0, 0, 0, 0));
    layout_conceptos->setSpacing(0);

    QWidget * widget_conceptos = new QWidget(this->ui->pestania_4);
    widget_conceptos->setLayout(layout_conceptos);
    widget_conceptos->setVisible(false);

    QHBoxLayout * layout_etiqueta = new QHBoxLayout(this->ui->pestania_4);
    layout_etiqueta->setContentsMargins(QMargins(1, 1, 1, 1));
    layout_etiqueta->setSpacing(1);
    layout_etiqueta->setAlignment(Qt::AlignLeft);

    QWidget * widget_etiqueta = new QWidget(this->ui->pestania_4);
    widget_etiqueta->setLayout(layout_etiqueta);

    QLabel * etiqueta = new QLabel(medio->getNombre().c_str(), this->ui->pestania_4);
    QLabel * icono = new QLabel(this->ui->pestania_4);

    icono->setPixmap(QIcon(this->path_icono(medio).c_str()).pixmap(QSize(16, 16)));
    layout_etiqueta->addWidget(icono);
    layout_etiqueta->addWidget(etiqueta);

    layout_conceptos->addWidget(widget_etiqueta);
    layout_conceptos->addWidget(arbol);

    this->ui->layout_pestania_4->addWidget(widget_conceptos);
    (&this->resultados_por_conceptos[resultado->getId()->numero()])->push_back(widget_conceptos);
    (&this->arboles_resultados_por_conceptos[resultado->getId()->numero()])->push_back(std::make_pair(medio->getNombre(), arbol));
}

//QTreeWidget * DialogoResultadoConsulta::nuevo_arbol_sentimiento(const unsigned long long int & fecha, const std::vector<modelo::Medio*> & medios)
//{
//    QTreeWidget * sentimiento = new QTreeWidget(this->ui->pestania_2);
//
//    QObject::connect(sentimiento, &QTreeWidget::itemCollapsed, this, &DialogoResultadoConsulta::colapsar_sentimiento);
//    QObject::connect(sentimiento, &QTreeWidget::itemExpanded, this, &DialogoResultadoConsulta::expandir_sentimiento);
//
//    sentimiento->move(this->ui->lbl_sin_valores_2->pos());
//    this->ui->layout_pestania_2->addWidget(sentimiento);
//
//    sentimiento->setColumnCount((medios.size() + 1));
//
//    QStringList etiquetas_medios(herramientas::utiles::Fecha::parsearFormatoAAAAMMDD(std::to_string(fecha)).getStringDDmesAAAA(" ").c_str());
//    std::for_each(medios.begin(), medios.end(),
//        [=, &etiquetas_medios, &sentimiento](modelo::Medio * medio) {
//        sentimiento->model()->setHeaderData(etiquetas_medios.size(), Qt::Horizontal, QVariant::fromValue(QIcon(this->path_icono(medio).c_str())), Qt::DecorationRole);
//        etiquetas_medios.push_back(QString(medio->getNombre().c_str()));
//    });
//
//    sentimiento->setHeaderLabels(etiquetas_medios);
//    sentimiento->setSortingEnabled(true);
//    sentimiento->setVisible(false);
//    sentimiento->setSelectionMode(QAbstractItemView::SelectionMode::ContiguousSelection);
//
//    this->sentimientos[fecha] = sentimiento;
//
//    return sentimiento;
//}
//
//QTreeWidget * DialogoResultadoConsulta::nuevo_arbol_fuerza_en_noticia(const unsigned long long int & fecha, const std::vector<modelo::Medio*> & medios)
//{
//    QTreeWidget * fuerza_en_noticia = new QTreeWidget(this->ui->pestania_1);
//
//    QObject::connect(fuerza_en_noticia, &QTreeWidget::itemCollapsed, this, &DialogoResultadoConsulta::colapsar_fuerza_en_noticia);
//    QObject::connect(fuerza_en_noticia, &QTreeWidget::itemExpanded, this, &DialogoResultadoConsulta::expandir_fuerza_en_noticia);
//
//    fuerza_en_noticia->move(this->ui->lbl_sin_valores_1->pos());
//    this->ui->layout_pestania_1->addWidget(fuerza_en_noticia);
//
//    fuerza_en_noticia->setColumnCount(medios.size() + 1);
//
//    QStringList etiquetas_medios(herramientas::utiles::Fecha::parsearFormatoAAAAMMDD(std::to_string(fecha)).getStringDDmesAAAA(" ").c_str());
//    std::for_each(medios.begin(), medios.end(),
//        [=, &etiquetas_medios, &fuerza_en_noticia](modelo::Medio * medio) {
//        fuerza_en_noticia->model()->setHeaderData(etiquetas_medios.size(), Qt::Horizontal, QVariant::fromValue(QIcon(this->path_icono(medio).c_str())), Qt::DecorationRole);
//        etiquetas_medios.push_back(QString(medio->getNombre().c_str()));
//    });
//
//    fuerza_en_noticia->setHeaderLabels(etiquetas_medios);
//    fuerza_en_noticia->setSortingEnabled(true);
//    fuerza_en_noticia->setVisible(false);
//    fuerza_en_noticia->setSelectionMode(QAbstractItemView::SelectionMode::ContiguousSelection);
//
//    this->fuerzas_en_noticia[fecha] = fuerza_en_noticia;
//
//    return fuerza_en_noticia;
//}

void DialogoResultadoConsulta::mostrar_resultado(int fecha) {

    //if (this->fuerzas_en_noticia.count(fecha)) {
    //    this->fuerzas_en_noticia[fecha]->setVisible(true);
    //    this->fuerzas_en_noticia[fecha]->raise();
    //    this->ui->lbl_sin_valores_1->setVisible(false);
    //}
    //else {
    //    this->ui->lbl_sin_valores_1->setVisible(true);
    //    this->ui->lbl_sin_valores_1->raise();
    //}

    //if (this->sentimientos.count(fecha)) {
    //    this->sentimientos[fecha]->setVisible(true);
    //    this->sentimientos[fecha]->raise();
    //    this->ui->lbl_sin_valores_2->setVisible(false);
    //}
    //else {
    //    this->ui->lbl_sin_valores_2->setVisible(true);
    //    this->ui->lbl_sin_valores_2->raise();
    //}

    if (this->tendencias.count(fecha)) {
        std::for_each(this->tendencias[fecha].begin(), this->tendencias[fecha].end(), [=](QWidget * widget_tendencia) {
            widget_tendencia->setVisible(true);
            widget_tendencia->raise();
        });
        this->ui->lbl_sin_valores_3->setVisible(false);
    }
    else {
        this->ui->lbl_sin_valores_3->setVisible(true);
        this->ui->lbl_sin_valores_3->raise();
    }

    if (this->resultados_por_conceptos.count(fecha)) {
        std::for_each(this->resultados_por_conceptos[fecha].begin(), this->resultados_por_conceptos[fecha].end(), [=](QWidget * widget_conceptos) {
            widget_conceptos->setVisible(true);
            widget_conceptos->raise();
        });
        this->ui->lbl_sin_valores_4->setVisible(false);
    }
    else {
        this->ui->lbl_sin_valores_4->setVisible(true);
        this->ui->lbl_sin_valores_4->raise();
    }
}

void DialogoResultadoConsulta::ocultar_resultado(int fecha) {

    //if (this->fuerzas_en_noticia.count(fecha)) {
    //    this->fuerzas_en_noticia[fecha]->setVisible(false);
    //}

    //if (this->sentimientos.count(fecha)) {
    //    this->sentimientos[fecha]->setVisible(false);
    //}

    if (this->tendencias.count(fecha)) {
        std::for_each(this->tendencias[fecha].begin(), this->tendencias[fecha].end(), [=](QWidget * widget_tendencia) {
            widget_tendencia->setVisible(false);
        });
    }

    if (this->resultados_por_conceptos.count(fecha)) {
        std::for_each(this->resultados_por_conceptos[fecha].begin(), this->resultados_por_conceptos[fecha].end(), [=](QWidget * widget_conceptos) {
            widget_conceptos->setVisible(false);
        });
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

bool DialogoResultadoConsulta::fecha_tendencia_a_csv(int fecha, herramientas::utiles::csv * doc) {
    if (0 == this->tendencias.count(fecha)) { // si no existe la fecha, devuelvo false.
        return false;
    }

    std::vector<std::pair<std::string, QTableWidget*>> tendencias = this->tablas_tendencias[fecha];
    std::for_each(tendencias.begin(), tendencias.end(), [=](std::pair<std::string, QTableWidget*> medio_tabla) {
        for (uint16_t i_fila = 0; i_fila < medio_tabla.second->rowCount(); i_fila++) {
            std::string medio = medio_tabla.first;
            std::string es_concepto = "0";
            std::string termino = medio_tabla.second->item(i_fila, 0)->text().toStdString();
            std::string apariciones = medio_tabla.second->item(i_fila, 1)->text().toStdString();
            std::string porcentaje = medio_tabla.second->item(i_fila, 2)->text().toStdString();
            herramientas::utiles::FuncionesString::eliminarOcurrencias(porcentaje, "%");

            std::string fuerza = medio_tabla.second->item(i_fila, 3)->text().toStdString();

            std::string sentimiento = medio_tabla.second->item(i_fila, 4)->text().toStdString();
            herramientas::utiles::FuncionesString::eliminarOcurrencias(sentimiento, "+");
            herramientas::utiles::FuncionesString::eliminarOcurrencias(sentimiento, "-");
            herramientas::utiles::FuncionesString::eliminarOcurrencias(sentimiento, "n");

            std::vector<std::string> positividad_negatividad_neutralidad = herramientas::utiles::FuncionesString::separar(sentimiento);
            std::string positividad = positividad_negatividad_neutralidad[0];
            std::string negatividad = positividad_negatividad_neutralidad[1];
            std::string neutralidad = positividad_negatividad_neutralidad[2];

            std::string tipo = medio_tabla.second->item(i_fila, 5)->text().toStdString();
            std::string seccion = medio_tabla.second->item(i_fila, 6)->text().toStdString();

            std::string string_fecha = std::to_string(fecha);

            doc->agregar({medio, tipo, seccion, termino, es_concepto, apariciones, porcentaje, fuerza, positividad, negatividad, neutralidad, string_fecha });
        }
    });
    return true;
}

bool DialogoResultadoConsulta::fecha_conceptos_a_csv(int fecha, herramientas::utiles::csv * doc) {
        if (0 == this->arboles_resultados_por_conceptos.count(fecha)) { // si no existe la fecha, devuelvo false.
            return false;
        }
    
        std::vector<std::pair<std::string, QTreeWidget*>> arboles = this->arboles_resultados_por_conceptos[fecha];

        std::for_each(arboles.begin(), arboles.end(), [=](std::pair<std::string, QTreeWidget*> nombre_arbol) {

            std::string medio = nombre_arbol.first;
            QTreeWidget* arbol = nombre_arbol.second;

            int cantidad_de_columnas = arbol->columnCount();
            for (unsigned int i_medios = 1; i_medios < cantidad_de_columnas; i_medios++) {  // itero medios/columnas
                std::string nombre_medio = arbol->headerItem()->text(i_medios).toStdString();

                int cantidad_de_conceptos = arbol->topLevelItemCount();
                for (unsigned int i_conceptos = 0; i_conceptos < cantidad_de_conceptos; i_conceptos++) {  // itero conceptos/top level items

                    std::string concepto = arbol->topLevelItem(i_conceptos)->text(0).toStdString();
                    std::string apariciones = arbol->topLevelItem(i_conceptos)->text(1).toStdString();
                    std::string porcentaje = arbol->topLevelItem(i_conceptos)->text(2).toStdString();
                    herramientas::utiles::FuncionesString::eliminarOcurrencias(porcentaje, "%");

                    std::string fuerza = arbol->topLevelItem(i_conceptos)->text(3).toStdString();
                    std::string string_sentimiento_concepto = arbol->topLevelItem(i_conceptos)->text(4).toStdString();
                    herramientas::utiles::FuncionesString::eliminarOcurrencias(string_sentimiento_concepto, "+");
                    herramientas::utiles::FuncionesString::eliminarOcurrencias(string_sentimiento_concepto, "-");
                    herramientas::utiles::FuncionesString::eliminarOcurrencias(string_sentimiento_concepto, "n");

                    std::vector<std::string> positividad_negatividad_neutralidad_concepto = herramientas::utiles::FuncionesString::separar(string_sentimiento_concepto);
                    std::string positividad = positividad_negatividad_neutralidad_concepto[0];
                    std::string negatividad = positividad_negatividad_neutralidad_concepto[1];
                    std::string neutralidad = positividad_negatividad_neutralidad_concepto[2];

                    std::string tipo = arbol->topLevelItem(i_conceptos)->text(5).toStdString();
                    std::string seccion = arbol->topLevelItem(i_conceptos)->text(6).toStdString();

                    std::string string_fecha = std::to_string(fecha);

                    doc->agregar({ medio, tipo, seccion, concepto, "1", apariciones, porcentaje, fuerza, positividad, negatividad, neutralidad, string_fecha });

                    int cantidad_de_terminos = arbol->topLevelItem(i_conceptos)->childCount();
                    for (unsigned int i_terminos = 0; i_terminos < cantidad_de_terminos; i_terminos++) {  // itero terminos

                        std::string termino = arbol->topLevelItem(i_conceptos)->child(i_terminos)->text(0).toStdString();
                        std::string apariciones = arbol->topLevelItem(i_conceptos)->child(i_terminos)->text(1).toStdString();
                        std::string porcentaje = arbol->topLevelItem(i_conceptos)->child(i_terminos)->text(2).toStdString();
                        herramientas::utiles::FuncionesString::eliminarOcurrencias(porcentaje, "%");

                        std::string fuerza = arbol->topLevelItem(i_conceptos)->child(i_terminos)->text(3).toStdString();

                        std::string string_sentimiento_concepto = arbol->topLevelItem(i_conceptos)->child(i_terminos)->text(4).toStdString();
                        herramientas::utiles::FuncionesString::eliminarOcurrencias(string_sentimiento_concepto, "+");
                        herramientas::utiles::FuncionesString::eliminarOcurrencias(string_sentimiento_concepto, "-");
                        herramientas::utiles::FuncionesString::eliminarOcurrencias(string_sentimiento_concepto, "n");

                        std::vector<std::string> positividad_negatividad_neutralidad_concepto = herramientas::utiles::FuncionesString::separar(string_sentimiento_concepto);
                        std::string positividad = positividad_negatividad_neutralidad_concepto[0];
                        std::string negatividad = positividad_negatividad_neutralidad_concepto[1];
                        std::string neutralidad = positividad_negatividad_neutralidad_concepto[2];

                        std::string tipo = arbol->topLevelItem(i_conceptos)->child(i_terminos)->text(5).toStdString();
                        std::string seccion = arbol->topLevelItem(i_conceptos)->child(i_terminos)->text(6).toStdString();

                        doc->agregar({ medio, tipo, seccion, termino, "0", apariciones, porcentaje, fuerza, positividad, negatividad, neutralidad, string_fecha });
                    }
                }
            }
        });
    
        return true;
}

//bool DialogoResultadoConsulta::fecha_fuerza_sentimiento_a_csv(int fecha, herramientas::utiles::csv * doc) {
//    if (0 == this->fuerzas_en_noticia.count(fecha)) { // si no existe la fecha, devuelvo false.
//        return false;
//    }
//
//    QTreeWidget * fuerza_en_noticia = this->fuerzas_en_noticia[fecha];
//    QTreeWidget * sentimiento = this->sentimientos[fecha];
//
//    int cantidad_de_columnas = fuerza_en_noticia->columnCount();
//    for (unsigned int i_medios = 1; i_medios < cantidad_de_columnas; i_medios++) {  // itero medios/columnas
//        std::string nombre_medio = fuerza_en_noticia->headerItem()->text(i_medios).toStdString();
//
//        int cantidad_de_conceptos = fuerza_en_noticia->topLevelItemCount();
//        for (unsigned int i_conceptos = 0; i_conceptos < cantidad_de_conceptos; i_conceptos++) {  // itero conceptos/top level items
//
//            std::string nombre_concepto = fuerza_en_noticia->topLevelItem(i_conceptos)->text(0).toStdString();
//            std::string fuerza_en_noticia_valor_concepto_en_medio = fuerza_en_noticia->topLevelItem(i_conceptos)->text(i_medios).toStdString();
//
//            std::string string_sentimiento_concepto = sentimiento->topLevelItem(i_conceptos)->text(i_medios).toStdString();
//            herramientas::utiles::FuncionesString::eliminarOcurrencias(string_sentimiento_concepto, "+");
//            herramientas::utiles::FuncionesString::eliminarOcurrencias(string_sentimiento_concepto, "-");
//            herramientas::utiles::FuncionesString::eliminarOcurrencias(string_sentimiento_concepto, "n");
//
//            std::vector<std::string> positividad_negatividad_neutralidad_concepto = herramientas::utiles::FuncionesString::separar(string_sentimiento_concepto);
//            std::string positividad_concepto = positividad_negatividad_neutralidad_concepto[0];
//            std::string negatividad_concepto = positividad_negatividad_neutralidad_concepto[1];
//            std::string neutralidad_concepto = positividad_negatividad_neutralidad_concepto[2];
//
//            doc->agregar( {nombre_medio, nombre_concepto, "1", fuerza_en_noticia_valor_concepto_en_medio, positividad_concepto, negatividad_concepto, neutralidad_concepto, std::to_string(fecha)} );
//
//            int cantidad_de_terminos = fuerza_en_noticia->topLevelItem(i_conceptos)->childCount();
//            for (unsigned int i_terminos = 0; i_terminos < cantidad_de_terminos; i_terminos++) {  // itero terminos
//
//                std::string nombre_termino = fuerza_en_noticia->topLevelItem(i_conceptos)->child(i_terminos)->text(0).toStdString();
//                std::string fuerza_en_noticia_valor_concepto_en_medio = fuerza_en_noticia->topLevelItem(i_conceptos)->child(i_terminos)->text(i_medios).toStdString();
//                std::string string_sentimiento_termino = sentimiento->topLevelItem(i_conceptos)->child(i_terminos)->text(i_medios).toStdString();
//                herramientas::utiles::FuncionesString::eliminarOcurrencias(string_sentimiento_termino, "+");
//                herramientas::utiles::FuncionesString::eliminarOcurrencias(string_sentimiento_termino, "-");
//                herramientas::utiles::FuncionesString::eliminarOcurrencias(string_sentimiento_termino, "n");
//
//                std::vector<std::string> positividad_negatividad_neutralidad_termino = herramientas::utiles::FuncionesString::separar(string_sentimiento_termino);
//                std::string positividad_termino = positividad_negatividad_neutralidad_termino[0];
//                std::string negatividad_termino = positividad_negatividad_neutralidad_termino[1];
//                std::string neutralidad_termino = positividad_negatividad_neutralidad_termino[2];
//                doc->agregar({ nombre_medio, nombre_termino, "0", fuerza_en_noticia_valor_concepto_en_medio, positividad_concepto, negatividad_concepto, neutralidad_concepto, std::to_string(fecha) });
//            }
//        }
//    }
//
//    return true;
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
    for (unsigned int i_medios = 1; i_medios < cantidad_de_columnas; i_medios++) {  // itero medios/columnas
        std::string nombre_medio = fuerza_en_noticia->headerItem()->text(i_medios).toStdString();

        herramientas::utiles::Json * json_medio = new herramientas::utiles::Json();
        json_medio->agregarAtributoValor("nombre", nombre_medio);  // medio,

        int cantidad_de_conceptos = fuerza_en_noticia->topLevelItemCount();
        for (unsigned int i_conceptos = 0; i_conceptos < cantidad_de_conceptos; i_conceptos++) {  // itero conceptos/top level items

            herramientas::utiles::Json * json_concepto = this->concepto_a_json(fuerza_en_noticia, sentimiento, i_conceptos, i_medios);  // termino, es_concepto, fuerza, sentimiento, fecha
            std::string nombre_concepto = fuerza_en_noticia->topLevelItem(i_conceptos)->text(0).toStdString();
            std::string fuerza_en_noticia_valor_concepto_en_medio = fuerza_en_noticia->topLevelItem(i_conceptos)->text(i_medios).toStdString();
            std::string sentimiento_valor_concepto_en_medio = sentimiento->topLevelItem(i_conceptos)->text(i_medios).toStdString();

            int cantidad_de_terminos = fuerza_en_noticia->topLevelItem(i_conceptos)->childCount();
            for (unsigned int i_terminos = 0; i_terminos < cantidad_de_terminos; i_terminos++) {  // itero terminos

                herramientas::utiles::Json * json_termino = this->termino_a_json(fuerza_en_noticia, sentimiento, i_conceptos, i_terminos, i_medios);

                std::string nombre_termino = fuerza_en_noticia->topLevelItem(i_conceptos)->child(i_terminos)->text(0).toStdString();
                std::string fuerza_en_noticia_valor_concepto_en_medio = fuerza_en_noticia->topLevelItem(i_conceptos)->child(i_terminos)->text(i_medios).toStdString();
                std::string sentimiento_valor_concepto_en_medio = sentimiento->topLevelItem(i_conceptos)->child(i_terminos)->text(i_medios).toStdString();

                terminos_de_concepto.push_back(json_termino);
            }
            json_concepto->agregarAtributoArray("terminos", terminos_de_concepto);
            conceptos_de_medio.push_back(json_concepto);

            std::for_each(terminos_de_concepto.begin(), terminos_de_concepto.end(), [](herramientas::utiles::Json * json_termino) { delete json_termino; });
            terminos_de_concepto.clear();
        }

        json_medio->agregarAtributoArray("conceptos", conceptos_de_medio);
        medios_en_fecha.push_back(json_medio);

        std::for_each(conceptos_de_medio.begin(), conceptos_de_medio.end(), [](herramientas::utiles::Json * json_concepto) { delete json_concepto; });
        conceptos_de_medio.clear();
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

std::string DialogoResultadoConsulta::path_icono(modelo::Medio * medio) {
    if (visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedioFacebook() == medio->getGrupo()) {
        return "Resources/icono_facebook.png";
    }
    if (visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedioTwitter() == medio->getGrupo()) {
        return "Resources/icono_twitter.png";
    }
    if (visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedioPortalNoticias() == medio->getGrupo()) {
        return "Resources/icono_portal.png";
    }
    return "Resources/icono_portal.png";
}

std::string DialogoResultadoConsulta::tipo_medio(modelo::Medio * medio) {
    if (visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedioFacebook() == medio->getGrupo()) {
        return "facebook";
    }
    if (visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedioTwitter() == medio->getGrupo()) {
        return "twitter";
    }
    if (visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedioPortalNoticias() == medio->getGrupo()) {
        return "portal";
    }
    return "Resources/icono_portal.png";
}

void DialogoResultadoConsulta::exportar_actual() {

    QFuture<void> tarea_exportacion = QtConcurrent::run([this]() {

        //std::string string_fecha_actual = this->fecha_actual.getStringAAAAMMDD();

        //herramientas::utiles::Json json_consulta;

        //herramientas::utiles::Json * json_fecha_actual = this->fecha_a_json(std::stoi(string_fecha_actual));

        //std::vector<herramientas::utiles::Json*> json_fechas = { json_fecha_actual };

        //json_consulta.agregarAtributoArray("fechas", json_fechas);

        //std::string path_exportacion = "consulta_" + herramientas::utiles::Fecha::getFechaActual().getStringAAAAMMDDHHmmSS() + ".json";
        //herramientas::utiles::FuncionesSistemaArchivos::escribir(path_exportacion, json_consulta.jsonStringLindo());

        //std::for_each(json_fechas.begin(), json_fechas.end(), [](herramientas::utiles::Json * json_fecha) { delete json_fecha; });

        std::string string_fecha_actual = this->fecha_actual.getStringAAAAMMDD();

        //herramientas::utiles::csv csv_fecha_fuerza_sentimiento(this->nombres_columnas_csv);
        //if (this->fecha_fuerza_sentimiento_a_csv(std::stoi(string_fecha_actual), &csv_fecha_fuerza_sentimiento)) {
        //    std::string path_exportacion = "fuerza_y_sentimiento_" + herramientas::utiles::Fecha::getFechaActual().getStringAAAAMMDDHHmmSS() + ".csv";
        //    std::ofstream salida(path_exportacion);
        //    csv_fecha_fuerza_sentimiento.exportar(salida);
        //}
        std::string string_fecha_y_hora_actual = herramientas::utiles::Fecha::getFechaActual().getStringAAAAMMDDHHmmSS();

        herramientas::utiles::csv csv_fecha_tendencia(this->nombres_columnas_csv);
        if (this->fecha_tendencia_a_csv(std::stoi(string_fecha_actual), &csv_fecha_tendencia)) {
            std::string path_exportacion = visualizador::aplicacion::ConfiguracionAplicacion::dirConsultas() + "/tendencia_" + string_fecha_y_hora_actual + ".csv";
            std::ofstream salida(path_exportacion);
            csv_fecha_tendencia.exportar(salida);
        }

        herramientas::utiles::csv csv_fecha_conceptos(this->nombres_columnas_csv);
        if (this->fecha_conceptos_a_csv(std::stoi(string_fecha_actual), &csv_fecha_conceptos)) {
            std::string path_exportacion = visualizador::aplicacion::ConfiguracionAplicacion::dirConsultas() + "/conceptos_" + string_fecha_y_hora_actual + ".csv";
            std::ofstream salida(path_exportacion);
            csv_fecha_conceptos.exportar(salida);
        }
    });

    this->observador_exportacion.setFuture(tarea_exportacion);
}

void DialogoResultadoConsulta::exportar_todo() {

    QFuture<void> tarea_exportacion = QtConcurrent::run([this]() {

        //herramientas::utiles::Json json_consulta;

        //std::vector<herramientas::utiles::Json*> json_fechas;
        //std::for_each(this->fuerzas_en_noticia.begin(), this->fuerzas_en_noticia.end(),
        //    [this, &json_fechas](std::pair<unsigned long long int, QTreeWidget*> fecha_arbol) {

        //    herramientas::utiles::Json * json_fecha = this->fecha_a_json(fecha_arbol.first);
        //    json_fechas.push_back(json_fecha);
        //});

        //json_consulta.agregarAtributoArray("fechas", json_fechas);

        //std::string path_exportacion = "consulta_" + herramientas::utiles::Fecha::getFechaActual().getStringAAAAMMDDHHmmSS() + ".json";
        //herramientas::utiles::FuncionesSistemaArchivos::escribir(path_exportacion, json_consulta.jsonStringLindo());

        //std::for_each(json_fechas.begin(), json_fechas.end(), [](herramientas::utiles::Json * json_fecha) { delete json_fecha; });

        //herramientas::utiles::csv csv_fechas_fuerza_sentimiento(this->nombres_columnas_csv);
        std::string string_fecha_actual = herramientas::utiles::Fecha::getFechaActual().getStringAAAAMMDDHHmmSS();

        herramientas::utiles::csv csv_fechas_tendencia(this->nombres_columnas_csv);
        std::for_each(this->tendencias.begin(), this->tendencias.end(),
            [this, &csv_fechas_tendencia](std::pair<unsigned long long int, std::vector<QWidget*>> fecha_arbol) {

            herramientas::utiles::csv csv_fecha_tendencia({});
            if (this->fecha_tendencia_a_csv(fecha_arbol.first, &csv_fecha_tendencia)) {
                csv_fechas_tendencia += csv_fecha_tendencia;
            }
        });
        if (csv_fechas_tendencia.filas().size()) {
            std::string path_exportacion = visualizador::aplicacion::ConfiguracionAplicacion::dirConsultas() + "/tendencia_" + string_fecha_actual + ".csv";
            std::ofstream salida(path_exportacion);
            csv_fechas_tendencia.exportar(salida);
        }

        herramientas::utiles::csv csv_fechas_conceptos(this->nombres_columnas_csv);
        std::for_each(this->resultados_por_conceptos.begin(), this->resultados_por_conceptos.end(),
            [this, &csv_fechas_conceptos](std::pair<unsigned long long int, std::vector<QWidget*>> fecha_arbol) {

            herramientas::utiles::csv csv_fecha_conceptos({});
            if (this->fecha_conceptos_a_csv(fecha_arbol.first, &csv_fecha_conceptos)) {
                csv_fechas_conceptos += csv_fecha_conceptos;
            }
        });
        if (csv_fechas_conceptos.filas().size()) {
            std::string path_exportacion = visualizador::aplicacion::ConfiguracionAplicacion::dirConsultas() + "/conceptos_" + string_fecha_actual + ".csv";
            std::ofstream salida(path_exportacion);
            csv_fechas_conceptos.exportar(salida);
        }
    });

    this->observador_exportacion.setFuture(tarea_exportacion);
}

void DialogoResultadoConsulta::exportar_rango() {

    QFuture<void> tarea_exportacion = QtConcurrent::run([this]() {

        //herramientas::utiles::Json json_consulta;

        //std::vector<herramientas::utiles::Json*> json_fechas;

        //for (unsigned int i = this->ui->dateedit_desde->date().toJulianDay(); i < this->ui->dateedit_hasta->date().toJulianDay(); i++) {
        //    std::string string_fecha = QDate::fromJulianDay(i).toString("yyyyMMdd").toStdString();

        //    herramientas::utiles::Json * json_fecha = this->fecha_a_json(std::stoi(string_fecha));

        //    if (json_fecha) {
        //        json_fechas.push_back(json_fecha);
        //    }
        //}

        //json_consulta.agregarAtributoArray("fechas", json_fechas);

        //std::string path_exportacion = "consulta_" + herramientas::utiles::Fecha::getFechaActual().getStringAAAAMMDDHHmmSS() + ".json";
        //herramientas::utiles::FuncionesSistemaArchivos::escribir(path_exportacion, json_consulta.jsonStringLindo());

        //std::for_each(json_fechas.begin(), json_fechas.end(), [](herramientas::utiles::Json * json_fecha) { delete json_fecha; });

        //herramientas::utiles::csv csv_fechas_fuerza_sentimiento(this->nombres_columnas_csv);
        herramientas::utiles::csv csv_fechas_tendencia(this->nombres_columnas_csv);
        herramientas::utiles::csv csv_fechas_conceptos(this->nombres_columnas_csv);

        for (unsigned int i = this->ui->dateedit_desde->date().toJulianDay(); i < this->ui->dateedit_hasta->date().toJulianDay(); i++) {
            std::string string_fecha = QDate::fromJulianDay(i).toString("yyyyMMdd").toStdString();

            //herramientas::utiles::csv csv_fecha_fuerza_sentimiento({});
            //if (this->fecha_fuerza_sentimiento_a_csv(std::stoi(string_fecha), &csv_fecha_fuerza_sentimiento)) {
            //    csv_fechas_fuerza_sentimiento += csv_fecha_fuerza_sentimiento;
            //}

            herramientas::utiles::csv csv_fecha_tendencia({});
            if (this->fecha_tendencia_a_csv(std::stoi(string_fecha), &csv_fecha_tendencia)) {
                csv_fechas_tendencia += csv_fecha_tendencia;
            }

            herramientas::utiles::csv csv_fecha_conceptos({});
            if (this->fecha_conceptos_a_csv(std::stoi(string_fecha), &csv_fecha_conceptos)) {
                csv_fechas_conceptos += csv_fecha_conceptos;
            }
        }

        //if (csv_fechas_fuerza_sentimiento.filas().size()) {
        //    std::string path_exportacion = "fuerza_y_sentimiento_" + herramientas::utiles::Fecha::getFechaActual().getStringAAAAMMDDHHmmSS() + ".csv";
        //    std::ofstream salida(path_exportacion);
        //    csv_fechas_fuerza_sentimiento.exportar(salida);
        //}

        std::string string_fecha_actual = herramientas::utiles::Fecha::getFechaActual().getStringAAAAMMDDHHmmSS();
        if (csv_fechas_tendencia.filas().size()) {
            std::string path_exportacion = visualizador::aplicacion::ConfiguracionAplicacion::dirConsultas() + "/tendencia_" + string_fecha_actual + ".csv";
            std::ofstream salida(path_exportacion);
            csv_fechas_tendencia.exportar(salida);
        }

        if (csv_fechas_conceptos.filas().size()) {
            std::string path_exportacion = visualizador::aplicacion::ConfiguracionAplicacion::dirConsultas() + "/conceptos_" + string_fecha_actual + ".csv";
            std::ofstream salida(path_exportacion);
            csv_fechas_conceptos.exportar(salida);
        }
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
    QObject::connect(&(this->observador_exportacion), &QFutureWatcher<void>::started, &(this->spinner), &WaitingSpinnerWidget::start);
    QObject::connect(&(this->observador_exportacion), &QFutureWatcher<void>::finished, this, &DialogoResultadoConsulta::habilitar_exportar_botones);
    QObject::connect(&(this->observador_exportacion), &QFutureWatcher<void>::finished, &(this->spinner), &WaitingSpinnerWidget::stop);
    QObject::connect(&(this->observador_exportacion), &QFutureWatcher<void>::progressValueChanged, this->ui->progressbar_exportacion, &QProgressBar::valueChanged);
}

QTreeWidgetItem * DialogoResultadoConsulta::completar_fila_arbol(modelo::Concepto * concepto, modelo::Medio * medio, scraping::preparacion::ResultadoAnalisisDiario * resultado) {
    std::vector<modelo::Termino*> terminos = concepto->getTerminos();
    QStringList valores_de_concepto_por_medio(concepto->getEtiqueta().c_str());
    
    double fuerza_total = 1.0f;
    double fuerza = 0.0f;
    scraping::analisis::tecnicas::ResultadoSentimiento::sentimiento sentimiento;

    std::for_each(terminos.begin(), terminos.end(),
        [&resultado, &medio, &fuerza_total, &fuerza, &sentimiento](modelo::Termino * termino)
    {
        std::string expresion = termino->getValor();
        unsigned long long int id_medio = medio->getId()->numero();

        scraping::preparacion::ResultadoAnalisisMedio * resultado_medio = resultado->getResultadoMedio(id_medio);

        if (resultado_medio) {
            scraping::analisis::tecnicas::ResultadoFuerzaEnNoticia resultado_fuerza;
            resultado_medio->fuerza_en_noticia_de_categoria(&resultado_fuerza, medio->seccion());
            fuerza += resultado_fuerza.getFuerza(expresion);
            fuerza_total = resultado_fuerza.getFuerzaTotal();  // lo reseteo todo el tiempo, pero el valor tiene que ser siempre el mismo.

            scraping::analisis::tecnicas::ResultadoSentimiento resultado_sentimiento;
            resultado_medio->sentimiento_de_categoria(&resultado_sentimiento, medio->seccion());
            sentimiento += resultado_sentimiento.valores(expresion);
        }
    });

    valores_de_concepto_por_medio.push_back(herramientas::utiles::FuncionesString::toString(sentimiento.total(), 0).c_str());
    valores_de_concepto_por_medio.push_back((herramientas::utiles::FuncionesString::toString((fuerza / fuerza_total) * 100, 0) + "%").c_str());
    valores_de_concepto_por_medio.push_back(herramientas::utiles::FuncionesString::toString(fuerza).c_str());
    valores_de_concepto_por_medio.push_back(sentimiento.informar().c_str());
    valores_de_concepto_por_medio.push_back(this->tipo_medio(medio).c_str());
    valores_de_concepto_por_medio.push_back(medio->seccion().c_str());

    return new QTreeWidgetItem(valores_de_concepto_por_medio);
}

QTreeWidgetItem * DialogoResultadoConsulta::completar_fila_arbol(modelo::Termino * termino, modelo::Medio * medio, scraping::preparacion::ResultadoAnalisisDiario * resultado) {
    QStringList valores_de_termino_por_medio(termino->getValor().c_str());

    std::string expresion = termino->getValor();
    unsigned long long int id_medio = medio->getId()->numero();

    scraping::preparacion::ResultadoAnalisisMedio * resultado_medio = resultado->getResultadoMedio(id_medio);

    double fuerza_total = 1.0f;
    double fuerza_en_noticia = 0.0f;
    scraping::analisis::tecnicas::ResultadoSentimiento::sentimiento sentimiento;
    if (resultado_medio) {
        scraping::analisis::tecnicas::ResultadoFuerzaEnNoticia resultado_fuerza;
        resultado_medio->fuerza_en_noticia_de_categoria(&resultado_fuerza, medio->seccion());
        fuerza_en_noticia = resultado_fuerza.getFuerza(expresion);
        fuerza_total = resultado_fuerza.getFuerzaTotal();

        scraping::analisis::tecnicas::ResultadoSentimiento resultado_sentimiento;
        resultado_medio->sentimiento_de_categoria(&resultado_sentimiento, medio->seccion());
        sentimiento = resultado_sentimiento.valores(expresion);
    }

    valores_de_termino_por_medio.push_back(herramientas::utiles::FuncionesString::toString(sentimiento.total(), 0).c_str());
    valores_de_termino_por_medio.push_back((herramientas::utiles::FuncionesString::toString((fuerza_en_noticia / fuerza_total) * 100, 0) + "%").c_str());
    valores_de_termino_por_medio.push_back(herramientas::utiles::FuncionesString::toString(fuerza_en_noticia).c_str());
    valores_de_termino_por_medio.push_back(sentimiento.informar().c_str());
    valores_de_termino_por_medio.push_back(this->tipo_medio(medio).c_str());
    valores_de_termino_por_medio.push_back(medio->seccion().c_str());

    return new QTreeWidgetItem(valores_de_termino_por_medio);
}

