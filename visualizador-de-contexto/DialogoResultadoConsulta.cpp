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

    QObject::connect(this->ui->anios, &QAbstractSlider::sliderMoved, this, &DialogoResultadoConsulta::mostrar_resultado_anio);
    QObject::connect(this->ui->meses, &QAbstractSlider::sliderMoved, this, &DialogoResultadoConsulta::mostrar_resultado_mes);
    QObject::connect(this->ui->dias, &QAbstractSlider::sliderMoved, this, &DialogoResultadoConsulta::mostrar_resultado_dia);

    this->meses_con_treinta_dias = std::vector<unsigned int>{ 4, 6, 9, 11 };

    this->completar_arbol(medios, conceptos, resultados);

    this->mostrar_resultado((*resultados.begin())->getId()->numero());

    std::string string_fecha_minima = std::to_string((*resultados.begin())->getId()->numero());
    herramientas::utiles::Fecha fecha_minima = herramientas::utiles::Fecha::parsearFormatoAAAAMMDD(string_fecha_minima);
    this->fecha_actual = fecha_minima;

    std::string string_fecha_maxima = std::to_string((*(resultados.end() - 1))->getId()->numero());
    herramientas::utiles::Fecha fecha_maxima = herramientas::utiles::Fecha::parsearFormatoAAAAMMDD(string_fecha_maxima);

    this->ui->anios->setMinimum(fecha_minima.getAnio());
    this->ui->anios->setMaximum(fecha_maxima.getAnio());
    this->ui->anios->setSliderPosition(fecha_minima.getAnio());

    if (0 == fecha_maxima.getAnio() - fecha_minima.getAnio()) {
        this->ui->meses->setMinimum(fecha_minima.getMes());
        this->ui->meses->setMaximum(fecha_maxima.getMes());
        this->ui->meses->setSliderPosition(fecha_minima.getMes());
    }
    else {
        this->ui->meses->setMinimum(1);
        this->ui->meses->setMaximum(12);
        this->ui->meses->setSliderPosition(1);
    }

    if (0 == fecha_maxima.getMes() - fecha_minima.getMes()) {
        this->ui->dias->setMinimum(fecha_minima.getDia());
        this->ui->dias->setMaximum(fecha_maxima.getDia());
    }
    else {
        this->ui->dias->setMinimum(1);
        this->ui->dias->setMaximum(31);
        this->ui->dias->setSliderPosition(1);
    }

    this->ui->calendario->setDateRange(QDate::fromString(string_fecha_minima.c_str(), "yyyyMMdd"), QDate::fromString(string_fecha_maxima.c_str(), "yyyyMMdd"));
    this->ui->calendario->setDate(QDate::fromString(string_fecha_minima.c_str(), "yyyyMMdd"));

    this->mostrar_resultado(std::stoi(string_fecha_minima));
}

DialogoResultadoConsulta::~DialogoResultadoConsulta()
{
    std::for_each(this->sentimientos.begin(), this->sentimientos.end(), [](std::pair<unsigned long long int, QTreeWidget*> id_y_tabla) { delete id_y_tabla.second; });
    std::for_each(this->fuerzas_en_noticia.begin(), this->fuerzas_en_noticia.end(), [](std::pair<unsigned long long int, QTreeWidget*> id_y_tabla) { delete id_y_tabla.second; });

    delete ui;
}

void DialogoResultadoConsulta::completar_arbol(std::vector<modelo::Medio*> medios, std::vector<modelo::Concepto*> conceptos, std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados) {

    QStringList etiquetas_terminos;
    QStringList etiquetas_medios;

    // rescato los nombres de columnas(medios),
    etiquetas_medios.push_back("#");
    std::for_each(medios.begin(), medios.end(),
        [&etiquetas_medios](modelo::Medio * medio)
    {
        etiquetas_medios.push_back(QString(medio->getNombre().c_str()));
    });

    // y de filas (terminos)
    std::for_each(conceptos.begin(), conceptos.end(),
        [&etiquetas_terminos](modelo::Concepto * concepto)
    {
        etiquetas_terminos.push_back(QString(concepto->getEtiqueta().c_str()));

        std::vector<modelo::Termino*> terminos = concepto->getTerminos();

        std::for_each(terminos.begin(), terminos.end(),
            [&etiquetas_terminos](modelo::Termino * termino)
        { etiquetas_terminos.push_back(QString(termino->getValor().c_str())); });
    });

    // paso los resultados a la tabla.
    std::for_each(resultados.begin(), resultados.end(),
        [this, &conceptos, &etiquetas_medios, &medios](scraping::preparacion::ResultadoAnalisisDiario * resultado)
    {
        QTreeWidget * sentimiento = this->nuevo_arbol_sentimiento(resultado->getId()->numero());
        QTreeWidget * fuerza_en_noticia = this->nuevo_arbol_fuerza_en_noticia(resultado->getId()->numero());

        sentimiento->setHeaderLabels(etiquetas_medios);
        fuerza_en_noticia->setHeaderLabels(etiquetas_medios);

        this->sentimientos[resultado->getId()->numero()] = sentimiento;
        this->fuerzas_en_noticia[resultado->getId()->numero()] = fuerza_en_noticia;

        std::for_each(conceptos.begin(), conceptos.end(),
            [&resultado,
            &sentimiento,
            &fuerza_en_noticia,
            &medios]
        (modelo::Concepto * concepto)
        {
            QTreeWidgetItem * concepto_sentimiento = new QTreeWidgetItem(sentimiento);
            QTreeWidgetItem * concepto_fuerza_en_noticia = new QTreeWidgetItem(fuerza_en_noticia);

            QStringList valores_sentimiento_concepto_en_medio(concepto->getEtiqueta().c_str());
            QStringList valores_fuerza_en_noticia_concepto_en_medio(concepto->getEtiqueta().c_str());

            std::vector<modelo::Termino*> terminos = concepto->getTerminos();
            std::for_each(terminos.begin(), terminos.end(),
                [&resultado,
                &medios,
                &sentimiento,
                &fuerza_en_noticia,
                &valores_sentimiento_concepto_en_medio,
                &valores_fuerza_en_noticia_concepto_en_medio,
                &concepto_sentimiento,
                &concepto_fuerza_en_noticia]
            (modelo::Termino * termino)
            {
                std::string palabra = termino->getValor();

                QStringList valores_sentimiento_termino_en_medio(palabra.c_str());
                QStringList valores_fuerza_en_noticia_termino_en_medio(palabra.c_str());

                scraping::analisis::tecnicas::ResultadoSentimiento::sentimiento  valor_sentimiento_concepto_en_medio;
                double valor_fuerza_en_noticia_en_medio = 0.0f;
                std::for_each(medios.begin(), medios.end(),
                    [&resultado,
                    &sentimiento,
                    &fuerza_en_noticia,
                    &palabra,
                    &valores_sentimiento_termino_en_medio,
                    &valores_fuerza_en_noticia_termino_en_medio,
                    &valor_sentimiento_concepto_en_medio,
                    &valor_fuerza_en_noticia_en_medio]
                (modelo::Medio * medio)
                {
                    double resultado_fuerza = resultado->getResultadoMedio(medio->getMedioAScrapear()->getId()->numero())->getResultadoFuerzaEnNoticia()->getFuerza(palabra);
                    scraping::analisis::tecnicas::ResultadoSentimiento::sentimiento valoraciones = resultado->getResultadoMedio(medio->getMedioAScrapear()->getId()->numero())->getResultadoSentimiento()->valores(palabra);

                    valores_sentimiento_termino_en_medio.push_back(valoraciones.informar().c_str());
                    valores_fuerza_en_noticia_termino_en_medio.push_back(std::to_string(resultado_fuerza).c_str());

                    // acumulo el valor para el concepto
                    valor_sentimiento_concepto_en_medio += valoraciones;
                    valores_fuerza_en_noticia_termino_en_medio += valores_fuerza_en_noticia_termino_en_medio;
                });

                valores_sentimiento_concepto_en_medio.push_back(valor_sentimiento_concepto_en_medio.informar().c_str());
                valores_fuerza_en_noticia_concepto_en_medio.push_back(std::to_string(valor_fuerza_en_noticia_en_medio).c_str());

                QTreeWidgetItem * termino_sentimiento = new QTreeWidgetItem(concepto_sentimiento, valores_sentimiento_termino_en_medio);
                QTreeWidgetItem * termino_fuerza_en_noticia = new QTreeWidgetItem(concepto_fuerza_en_noticia, valores_fuerza_en_noticia_termino_en_medio);
            });

            // agrego los valores de sentimiento del concepto,
            unsigned int i = 0;
            std::for_each(valores_sentimiento_concepto_en_medio.begin(), valores_sentimiento_concepto_en_medio.end(),
                [&concepto_sentimiento, &i](QString valor)
            {
                concepto_sentimiento->setText(i, valor);
                i++;
            });

            // agrego los valores de fuerza en noticia.
            i = 0;
            std::for_each(valores_fuerza_en_noticia_concepto_en_medio.begin(), valores_fuerza_en_noticia_concepto_en_medio.end(),
                [&concepto_fuerza_en_noticia, &i](QString valor)
            {
                concepto_fuerza_en_noticia->setText(i, valor);
                i++;
            });
        });

        fuerza_en_noticia->setHeaderLabels(etiquetas_medios);
        fuerza_en_noticia->setFixedSize(this->ui->fuerza_en_noticia_vacio->size());
        fuerza_en_noticia->move(this->ui->fuerza_en_noticia_vacio->pos());
        fuerza_en_noticia->setColumnCount(etiquetas_medios.size());
        fuerza_en_noticia->show();

        sentimiento->setHeaderLabels(etiquetas_medios);
        sentimiento->setFixedSize(this->ui->sentimiento_vacio->size());
        sentimiento->move(this->ui->sentimiento_vacio->pos());
        sentimiento->setColumnCount(etiquetas_medios.size());
        sentimiento->show();
    });
}

QTreeWidget * DialogoResultadoConsulta::nuevo_arbol_sentimiento(const unsigned long long int & fecha)
{
    QTreeWidget * sentimiento = new QTreeWidget(this->ui->pestania_2);
    this->sentimientos[fecha] = sentimiento;
    return sentimiento;
}

QTreeWidget * DialogoResultadoConsulta::nuevo_arbol_fuerza_en_noticia(const unsigned long long int & fecha)
{
    QTreeWidget * fuerza_en_noticia = new QTreeWidget(this->ui->pestania_1);
    this->fuerzas_en_noticia[fecha] = fuerza_en_noticia;
    return fuerza_en_noticia;
}

void DialogoResultadoConsulta::mostrar_resultado(int fecha) {

    if (this->fuerzas_en_noticia.count(fecha)) {
        this->fuerzas_en_noticia[fecha]->raise();
    }
    else {
        this->ui->fuerza_en_noticia_vacio->raise();
    }

    if (this->sentimientos.count(fecha)) {
        this->sentimientos[fecha]->raise();
    }
    else {
        this->ui->sentimiento_vacio->raise();
    }
}

void DialogoResultadoConsulta::mostrar_resultado_anio(int anio) {

    std::string fecha = std::to_string(anio) + this->fecha_actual.getStringMes() + this->fecha_actual.getStringDia();

    this->mostrar_resultado(std::stoi(fecha));

    this->fecha_actual.setAnio(anio);
    this->ui->calendario->setDate(QDate::fromString(this->fecha_actual.getStringAAAAMMDD().c_str(), "yyyyMMdd"));
}

void DialogoResultadoConsulta::mostrar_resultado_mes(int mes) {

    std::string fecha = this->fecha_actual.getStringAnio() + std::to_string(mes) + this->fecha_actual.getStringDia();

    this->mostrar_resultado(std::stoi(fecha));

    this->fecha_actual.setMes(mes);
    this->ui->calendario->setDate(QDate::fromString(this->fecha_actual.getStringAAAAMMDD().c_str(), "yyyyMMdd"));

    
    if (std::count(this->meses_con_treinta_dias.begin(), this->meses_con_treinta_dias.end(), mes)) {
        this->ui->dias->setMaximum(30);

        if (2 == mes) {
            this->ui->dias->setMaximum(29);
        }
    }
    else {
        this->ui->dias->setMaximum(31);
    }
}

void DialogoResultadoConsulta::mostrar_resultado_dia(int dia) {

    std::string fecha = this->fecha_actual.getStringAnio() + this->fecha_actual.getStringMes() + std::to_string(dia);

    this->mostrar_resultado(std::stoi(fecha));

    this->fecha_actual.setDia(dia);
    this->ui->calendario->setDate(QDate::fromString(this->fecha_actual.getStringAAAAMMDD().c_str(), "yyyyMMdd"));
}