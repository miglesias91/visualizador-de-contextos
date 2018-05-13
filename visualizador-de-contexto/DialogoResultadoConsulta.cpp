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
        [this, &etiquetas_terminos, &etiquetas_medios, &medios](scraping::preparacion::ResultadoAnalisisDiario * resultado)
    {
        //QTableWidget * sentimiento = new QTableWidget(etiquetas_terminos.size(), etiquetas_medios.size(), this->ui->pestania_2);
        //QTableWidget * fuerza_en_noticia = new QTableWidget(etiquetas_terminos.size(), etiquetas_medios.size(), this->ui->pestania_1);
        QTreeWidget * sentimiento = new QTreeWidget(this->ui->pestania_2);
        QTreeWidget * fuerza_en_noticia = new QTreeWidget(this->ui->pestania_1);


        this->sentimientos[resultado->getId()->numero()] = sentimiento;
        this->fuerzas_en_noticia[resultado->getId()->numero()] = fuerza_en_noticia;

        QSize tamanio_tabla = this->ui->sentimiento->size();
        QPoint posicion_tabla = this->ui->sentimiento->pos();

        //std::for_each(medios.begin(), medios.end(),
        //    [&etiquetas_terminos, &resultado, &sentimiento, &fuerza_en_noticia](modelo::Medio * medio)
        //{
        //    std::for_each(etiquetas_terminos.begin(), etiquetas_terminos.end(),
        //        [&resultado, &medio, &sentimiento, &fuerza_en_noticia](std::string termino)
        //    {
        //        double fuerza = resultado->getResultadoMedio(medio->getMedioAScrapear()->getId()->numero())->getResultadoFuerzaEnNoticia()->getFuerza(termino);

        //    });
        //});

        QTreeWidgetItem * item = new QTreeWidgetItem(etiquetas_terminos);
        fuerza_en_noticia->setHeaderLabels(etiquetas_medios);
        //fuerza_en_noticia->setVerticalHeaderLabels(etiquetas_terminos);
        fuerza_en_noticia->setFixedSize(tamanio_tabla);
        fuerza_en_noticia->move(posicion_tabla);
        fuerza_en_noticia->setColumnCount(etiquetas_medios.size());
        fuerza_en_noticia->insertTopLevelItem(0, item);

        QTreeWidgetItem * item_2 = new QTreeWidgetItem(etiquetas_terminos);
        sentimiento->setHeaderLabels(etiquetas_medios);
        //sentimiento->setVerticalHeaderLabels(etiquetas_terminos);
        sentimiento->setFixedSize(tamanio_tabla);
        sentimiento->move(posicion_tabla);
        sentimiento->setColumnCount(etiquetas_medios.size());
        sentimiento->insertTopLevelItem(0, item_2);
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
