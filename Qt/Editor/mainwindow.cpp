#include "mainwindow.h"

VentanaPrincipal::VentanaPrincipal(
  QWidget *parent,
  Qt::WindowFlags flags) : QMainWindow(parent, flags)
{

  editorCentral = new QTextEdit;

  setCentralWidget(editorCentral);
  setWindowIcon(QIcon("icon.png"));

  accionSalir = new QAction(tr("&Salir"), this);

  connect(accionSalir,SIGNAL(triggered()),this, SLOT(close()));

  fileMenu = menuBar()->addMenu(tr("&Archivo"));
  fileMenu->addAction(accionSalir);

  editorCentral->addAction(accionSalir);
  editorCentral->setContextMenuPolicy(Qt::ActionsContextMenu);
}
