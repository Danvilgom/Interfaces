#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTextEdit>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QLabel>
#include <QStatusBar>
#include <QString>

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    VentanaPrincipal(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    static const int MAX_RECENT_FILES = 5;

private:
  void createActions();
  void createMenus();
  void createToolBar();
  void createStatusBar();
  void closeEvent(QCloseEvent * event);
  void establecerFicheroActual(QString ruta);

  bool abrirFichero(QString fileName);
  bool documentoModificado;

  QTextEdit *editorCentral;
  QAction *accionSalir;
  QAction *accionAbrir;
  QAction *accionGuardar;
  QAction *accionNuevo;
  QAction *accionesFicherosRecientes[MAX_RECENT_FILES];
  QAction *accionBuscar;
  QAction *accionDeshacer;
  QMenu *fileMenu;
  QMenu *editMenu;
  QToolBar *barraSalir;
  QToolBar *barraArchivo;
  QLabel *etiquetaEstado;

  QStringList ficherosRecientes;

private slots:
  void slotActualizarBarraEstado();
  void slotNuevo();
  void slotAbrir();
  void slotBuscar();
  void slotDeshacer();
  void slotAbrirFicheroReciente();
  void slotBuscarNext(const QString &str, Qt::CaseSensitivity cs);
  void slotBuscarPrevious(const QString &str, Qt::CaseSensitivity cs);
};

#endif
