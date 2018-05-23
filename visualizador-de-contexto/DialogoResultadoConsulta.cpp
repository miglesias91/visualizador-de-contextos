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


        std::for_each(conceptos.begin(), conceptos.end(),
            [&resultado, &sentimiento, &fuerza_en_noticia, &medios](modelo::Concepto * concepto)
        {
            std::for_each(medios.begin(), medios.end(),
                [&resultado, &sentimiento, &fuerza_en_noticia, &concepto](modelo::Medio * medio)
            {
                QStringList valores_sentimiento_concepto_en_medio(concepto->getEtiqueta().c_str());
                QStringList valores_fuerza_en_noticia_concepto_en_medio(concepto->getEtiqueta().c_str());
                
                std::vector<modelo::Termino*> terminos = concepto->getTerminos();
                std::for_each(terminos.begin(), terminos.end(),
                    [&resultado, &medio, &valores_sentimiento_concepto_en_medio, &valores_fuerza_en_noticia_concepto_en_medio](modelo::Termino * termino)
                {
                    std::string palabra = termino->getValor();

                    double resultado_fuerza = resultado->getResultadoMedio(medio->getMedioAScrapear()->getId()->numero())->getResultadoFuerzaEnNoticia()->getFuerza(palabra);
                    std::string resultado_sentimiento = resultado->getResultadoMedio(medio->getMedioAScrapear()->getId()->numero())->getResultadoSentimiento()->valores(palabra).informar();

                    valores_sentimiento_concepto_en_medio.push_back(resultado_sentimiento.c_str());
                    valores_fuerza_en_noticia_concepto_en_medio.push_back(std::to_string(resultado_fuerza).c_str());
                });

            });

        });
        std::for_each(conceptos.begin(), conceptos.end(),
            [&sentimiento, &fuerza_en_noticia, &medios, &resultado](modelo::Concepto * concepto)
        {
            QStringList string_concepto;
            string_concepto.push_back(concepto->getEtiqueta().c_str());

            QTreeWidgetItem * concepto_sentimiento = new QTreeWidgetItem(sentimiento, string_concepto);
            QTreeWidgetItem * concepto_fuerza_en_noticia = new QTreeWidgetItem(fuerza_en_noticia, string_concepto);

            std::vector<modelo::Termino*> terminos = concepto->getTerminos();

            std::for_each(terminos.begin(), terminos.end(),
                [&concepto_sentimiento, &concepto_fuerza_en_noticia, &medios, &resultado](modelo::Termino * termino)
            {
                std::string string_termino = termino->getValor();

                QStringList resultados_sentimientos_termino(string_termino.c_str());
                QStringList resultados_fuerza_en_noticia_termino(string_termino.c_str());

                std::for_each(medios.begin(), medios.end(),
                    [&resultado, &resultados_sentimientos_termino, &resultados_fuerza_en_noticia_termino, string_termino](modelo::Medio * medio)
                {
                    double resultado_fuerza = resultado->getResultadoMedio(medio->getMedioAScrapear()->getId()->numero())->getResultadoFuerzaEnNoticia()->getFuerza(string_termino);
                    scraping::analisis::tecnicas::ResultadoSentimiento::sentimiento sentimiento = resultado->getResultadoMedio(medio->getMedioAScrapear()->getId()->numero())->getResultadoSentimiento()->valores(string_termino);
                    std::string resultado_sentimiento = sentimiento.informar();

                    resultados_fuerza_en_noticia_termino.push_back(std::to_string(resultado_fuerza).c_str());
                    resultados_sentimientos_termino.push_back(resultado_sentimiento.c_str());
                });

                string_termino.push_back(QString(termino->getValor().c_str()));

                QTreeWidgetItem * termino_sentimiento = new QTreeWidgetItem(concepto_sentimiento, string_termino);
                QTreeWidgetItem * termino_fuerza_en_noticia = new QTreeWidgetItem(concepto_fuerza_en_noticia, string_termino);
            });
        });

        //std::for_each(medios.begin(), medios.end(),
        //    [&etiquetas_terminos, &resultado, &sentimiento, &fuerza_en_noticia](modelo::Medio * medio)
        //{
        //    std::for_each(etiquetas_terminos.begin(), etiquetas_terminos.end(),
        //        [&resultado, &medio, &sentimiento, &fuerza_en_noticia](std::string termino)
        //    {
        //        double fuerza = resultado->getResultadoMedio(medio->getMedioAScrapear()->getId()->numero())->getResultadoFuerzaEnNoticia()->getFuerza(termino);

        //    });
        //});

        //QTreeWidgetItem * item = new QTreeWidgetItem(etiquetas_terminos);
        fuerza_en_noticia->setHeaderLabels(etiquetas_medios);
        //fuerza_en_noticia->setVerticalHeaderLabels(etiquetas_terminos);
        fuerza_en_noticia->setFixedSize(this->ui->sentimiento->size());
        fuerza_en_noticia->move(this->ui->sentimiento->pos());
        fuerza_en_noticia->setColumnCount(etiquetas_medios.size());
        //fuerza_en_noticia->insertTopLevelItem(0, item);

        //QTreeWidgetItem * item_2 = new QTreeWidgetItem(etiquetas_terminos);
        sentimiento->setHeaderLabels(etiquetas_medios);
        //sentimiento->setVerticalHeaderLabels(etiquetas_terminos);
        sentimiento->setFixedSize(this->ui->sentimiento->size());
        sentimiento->move(this->ui->sentimiento->pos());
        sentimiento->setColumnCount(etiquetas_medios.size());
        //sentimiento->insertTopLevelItem(0, item_2);
    });

    this->sentimientos.begin()->second->show();
    this->fuerzas_en_noticia.begin()->second->show();

    this->ui->fuerza_en_noticia->setVisible(false);

    this->ui->sentimiento->setVisible(false);
}

DialogoResultadoConsulta::~DialogoResultadoConsulta()
{
    std::for_each(this->sentimientos.begin(), this->sentimientos.end(), [](std::pair<unsigned long long int, QTreeWidget*> id_y_tabla) { delete id_y_tabla.second; });
    std::for_each(this->fuerzas_en_noticia.begin(), this->fuerzas_en_noticia.end(), [](std::pair<unsigned long long int, QTreeWidget*> id_y_tabla) { delete id_y_tabla.second; });

    delete ui;
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
