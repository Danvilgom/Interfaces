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

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    VentanaPrincipal(QWidget *parent = 0, Qt::WindowFlags flags = 0);

private:
  void createActions();
  void createMenus();
  void createToolBar();
  void createStatusBar();
  bool documentoModificado;
  QTextEdit *editorCentral;
  QAction *accionSalir;
  QAction *accionAbrir;
  QAction *accionGuardar;
  QAction *accionNuevo;
  QMenu *fileMenu;
  QToolBar *barraSalir;
  QToolBar *barraArchivo;
  QLabel *etiquetaEstado;

private slots:
  void slotActualizarBarraEstado();
  void slotNuevo();
  void slotAbrir();
};

#endif
