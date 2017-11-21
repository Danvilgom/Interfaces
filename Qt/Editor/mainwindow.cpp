#include "mainwindow.h"
#include <QMessageBox>

VentanaPrincipal::VentanaPrincipal(
  QWidget *parent,
  Qt::WindowFlags flags) : QMainWindow(parent, flags)
{

  editorCentral = new QTextEdit;

  setCentralWidget(editorCentral);
  setWindowIcon(QIcon("icon.png"));

  createActions();
  createMenus();
  createToolBar();
  createStatusBar();

  connect(editorCentral, SIGNAL(textChanged()),
          this, SLOT(slotActualizarBarraEstado()));
}

void VentanaPrincipal::createActions() {
  accionSalir = new QAction(tr("&Salir"), this);
  accionSalir->setIcon(QIcon("close.png"));
  accionSalir->setShortcut(tr("Ctrl+Q"));

  accionAbrir = new QAction(tr("&Abrir"), this);
  accionAbrir->setIcon(QIcon("open.png"));
  accionAbrir->setShortcut(tr("Ctrl+O"));

  accionGuardar = new QAction(tr("&Guardar"), this);
  accionGuardar->setIcon(QIcon("save.png"));
  accionGuardar->setShortcut(tr("Ctrl+G"));

  accionNuevo = new QAction(tr("&Nuevo"), this);
  accionNuevo->setIcon(QIcon("new.png"));
  accionNuevo->setShortcut(tr("Ctrl+N"));

  connect(accionSalir,SIGNAL(triggered()),this, SLOT(close()));
  connect(accionAbrir,SIGNAL(triggered()),this, SLOT(close()));
  connect(accionGuardar,SIGNAL(triggered()),this, SLOT(close()));
  connect(accionNuevo,SIGNAL(triggered()),this, SLOT(close()));
}

void VentanaPrincipal::createMenus() {
  fileMenu = menuBar()->addMenu(tr("&Archivo"));
  fileMenu->addAction(accionSalir);
  fileMenu->addAction(accionAbrir);
  fileMenu->addAction(accionGuardar);
  fileMenu->addAction(accionNuevo);

  editorCentral->addAction(accionSalir);
  editorCentral->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void VentanaPrincipal::createToolBar() {
  barraArchivo = addToolBar("archivo");
  barraSalir = addToolBar("salir");

  barraArchivo->addAction(accionAbrir);
  barraArchivo->addAction(accionGuardar);
  barraArchivo->addAction(accionNuevo);
  barraSalir->addAction(accionSalir);
}

void VentanaPrincipal::createStatusBar(){
  etiquetaEstado = new QLabel("Hola");
  statusBar()->addWidget(etiquetaEstado);
}

void VentanaPrincipal::slotNuevo() {
  //editorCentral->document()->clear();

  int respuesta = QMessageBox::warning(this, tr("nuevo doc"),
  tr("Borro el documento ?"), QMessageBox::Yes | QMessageBox::No);

  if (respuesta == QMessageBox::Yes)
    editorCentral->document()->clear();
}

void VentanaPrincipal::slotActualizarBarraEstado(){
  QTextDocument * documento;
  documento = editorCentral->document();

  int numLineas;
  numLineas = documento->lineCount();

  QString texto("Modificado\tLineas: " + QString::number(numLineas));
  etiquetaEstado->setText(texto);
}
