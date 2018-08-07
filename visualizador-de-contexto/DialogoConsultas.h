#pragma once

#include <QWidget>

// qt
#include <qlistwidget.h>
#include <qstringlist.h>
#include <qmessagebox.h>

#include <QtCharts/qchartview.h>
#include <QtCharts/qbarseries.h>
#include <QtCharts/qbarset.h>
#include <QtCharts/qlegend.h>
#include <QtCharts/qbarcategoryaxis.h>
#include <QtCharts/qvalueaxis.h>

// aplicacion
#include <aplicacion/include/GestorEntidades.h>
#include <aplicacion/include/Informacion.h>

// modelo
#include <modelo/include/Consulta.h>

// visualizador
#include <visualizador-de-contexto/DialogoResultadoConsulta.h>
#include <visualizador-de-contexto/include/GraficoDeBarras.h>
#include <visualizador-de-contexto/include/FabricaMensajes.h>
#include <visualizador-de-contexto/include/waitingspinnerwidget.h>

#include <declaraciones_metatipos.h>

namespace Ui { class DialogoConsultas; };

class DialogoConsultas : public QWidget
{
    Q_OBJECT

public:
    DialogoConsultas(QWidget *parent = Q_NULLPTR);
    ~DialogoConsultas();

    virtual void closeEvent(QCloseEvent * evento);
    virtual void showEvent(QShowEvent * evento);

    void actualizar_listas();
signals:

    void se_cerro();
    void se_abrio();

private slots:
    void agregar_conceptos();

    void sacar_conceptos();

    void agregar_medios();

    void sacar_medios();

    void recuperar_resultados();

    void resetear_periodo();

    void mostrar_resultados();

    void guardar();

    void cerrar();

    void habilitar_consulta();
    void habilitar_conceptos();
    void habilitar_tendencias();

private:
    Ui::DialogoConsultas *ui;

    graficos::GraficoDeBarras * grafico_fuerza_en_noticia;

    DialogoResultadoConsulta * dialogo_resultados;

    WaitingSpinnerWidget spinner;
    QFutureWatcher<void> observador_realizar_consulta;

    std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados_filtrados;

    // metodos privados

    void conectar_componentes();

    void habilitar_opciones();
    void deshabilitar_opciones();

    // carga listas

    void cargarListaConceptos();
    void agregarConceptoALista(visualizador::modelo::Concepto* concepto, QListWidget * lista);

    void cargarListaMedios();
    void agregarMedioALista(visualizador::modelo::Medio* medio, QListWidget * lista);

    // obtener seleccionados de listas

    template <class ENTIDAD>
    std::vector<ENTIDAD*> itemsSeleccionados(QListWidget * lista);

    void sacarItemsSeleccionados(QListWidget * lista);

    std::vector<modelo::Concepto*> conceptosSeleccionados();

    modelo::Periodo* periodoSeleccionado();

    std::vector<modelo::Medio*> mediosSeleccionados();

    // descargar listas

    template <class ENTIDAD>
    void descargarLista(QListWidget * lista);

    // mensaje

    QMessageBox * crearInformacionSinResultados();
    QMessageBox * crearInformacionNoHayMediosSeleccionados();
    QMessageBox * crearInformacionNoHayConceptosSeleccionados();
};

template <class ENTIDAD>
std::vector<ENTIDAD*> DialogoConsultas::itemsSeleccionados(QListWidget * lista)
{
    std::vector<ENTIDAD*> items_seleccionados;
    QList<QListWidgetItem*> items = lista->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        QVariant data = item->data(Qt::UserRole);
        ENTIDAD* termino = data.value<ENTIDAD*>();

        items_seleccionados.push_back(termino);
    }

    return items_seleccionados;
}

template <class ENTIDAD>
void DialogoConsultas::descargarLista(QListWidget * lista)
{
    QListWidgetItem* item = nullptr;

    // elimino las entidades de la lista
    ENTIDAD* entidad_lista = nullptr;
    unsigned int count = lista->count();
    while (0 != lista->count())
    {
        count = lista->count();

        entidad_lista = lista->item(0)->data(Qt::UserRole).value<ENTIDAD*>();

        if (entidad_lista != NULL && 0 == entidad_lista->restarReferencia())
        {
            delete entidad_lista;
        }

        item = lista->takeItem(0);
        delete item;
    }
}
