# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = visualizador-de-contexto
DESTDIR = ../Win32/Debug
QT += core gui widgets
CONFIG += debug
DEFINES += QT_WIDGETS_LIB
INCLUDEPATH += . \
    ./GeneratedFiles \
    $(qt-dir)5.9.1/msvc2015/include \
    ./GeneratedFiles/$(ConfigurationName) \
    $(qt-dir)5.9.1/msvc2015/include/QtCore \
    $(qt-dir)5.9.1/msvc2015/include/QtGui \
    $(qt-dir)5.9.1/msvc2015/include/QtWidgets \
    $(SolutionDir) \
    $(repos-git)almacenamiento \
    $(repos-git)herramientas_desarrollo \
    $(repos-git)medios-digitales \
    $(repos-git)scraping \
    $(repos)rapidjson/include \
    $(repos)spdlog/include
LIBS += -L"$(SolutionDir)Debug" \
    -L"$(qt-dir)5.9.1/msvc2015/lib" \
    -L"$(repos-git)almacenamiento/Debug" \
    -L"$(repos-git)herramientas_desarrollo/Debug" \
    -L"$(repos-git)scraping/Debug" \
    -L"$(repos-git)ia/Debug" \
    -L"$(repos-git)medios-digitales/Debug" \
    -L"$(repos)rocksdb/build_x86/Debug" \
    -L"$(repos)cpprestsdk/Binaries/Win32/Debug" \
    -L"$(repos)pugixml/build/Debug" \
    -lmodelo \
    -laplicacion \
    -lscraping \
    -ldepuracion \
    -lpreparacion \
    -lanalisis \
    -lextraccion \
    -ltwitter \
    -lfacebook \
    -lnoticias \
    -lfeed \
    -lutiles \
    -lclasificacion-de-texto \
    -llog \
    -lprotocolos \
    -lcasablanca_wrapper \
    -lcpprest141d_2_10 \
    -lpugixml \
    -lalmacenamiento \
    -lWrapperRocksDB \
    -lrocksdb \
    -lShlwapi \
    -lRpcrt4 \
    -lwininet
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/$(ConfigurationName)
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(visualizador-de-contexto.pri)
win32:RC_FILE = visualizador-de-contexto.rc
