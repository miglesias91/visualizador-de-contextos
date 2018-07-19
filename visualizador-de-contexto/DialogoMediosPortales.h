#pragma once

#include <QWidget>

// qt
#include <qmessagebox.h>

// scraping::extraccion
#include <extraccion/include/Medio.h>

// aplicacion
#include <aplicacion/include/GestorEntidades.h>

// modelo
#include <modelo/include/MedioPortalNoticias.h>

// visualizador
#include <declaraciones_metatipos.h>

namespace Ui { class DialogoMediosPortales; };

class DialogoMediosPortales : public QWidget
{
    Q_OBJECT

public:
    DialogoMediosPortales(QWidget* parent = Q_NULLPTR);
    ~DialogoMediosPortales();

    virtual void hideEvent(QHideEvent * evento);
    virtual void showEvent(QShowEvent * evento);

signals:

    void se_cerro();
    void se_abrio();

    private slots:

    void guardar();
    void cerrar();

private:
    Ui::DialogoMediosPortales *ui;

    void conectar_componentes();

    void cargarListaMediosPortales();
    void descargarListaMediosPortales();
    void agregarPortalALista(modelo::MedioPortalNoticias * medio_portal_noticias);
    void agregarSubseccionALista(modelo::subseccion * subseccion_portal_noticias);

    void registrar_abm();

    visualizador::aplicacion::GestorEntidades gestor_medios;
};
