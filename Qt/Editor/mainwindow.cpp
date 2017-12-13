#include "mainwindow.h"
#include "finddialog.h"
#include "dialogodeshacer.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QCloseEvent>
#include <QTextStream>
#include <QStringListIterator>

VentanaPrincipal::VentanaPrincipal(
  QWidget *parent,
  Qt::WindowFlags flags) : QMainWindow(parent, flags)
{

  editorCentral = new QTextEdit;
  documentoModificado = false;

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

  accionBuscar = new QAction(tr("&Buscar"), this);
  accionBuscar->setIcon(QIcon("find.png"));
  accionBuscar->setShortcut(tr("Ctrl+F"));

  accionDeshacer = new QAction(tr("&Deshacer"), this);

  for (int i = 0; i < MAX_RECENT_FILES; i++) {
    accionesFicherosRecientes[i] = new QAction(
                                        QString("action") +
                                        QString::number(i),
                                        this);


    accionesFicherosRecientes[i]->setVisible(false);
    connect(accionesFicherosRecientes[i],
      SIGNAL(triggered()),this,
      SLOT(slotAbrirFicheroReciente()));
  }

  connect(accionSalir,SIGNAL(triggered()),this, SLOT(close()));
  connect(accionAbrir,SIGNAL(triggered()),this, SLOT(slotAbrir()));
  connect(accionGuardar,SIGNAL(triggered()),this, SLOT(close()));
  connect(accionNuevo,SIGNAL(triggered()),this, SLOT(slotNuevo()));
  connect(accionBuscar,SIGNAL(triggered()),this, SLOT(slotBuscar()));
  connect(accionDeshacer,SIGNAL(triggered()),this, SLOT(slotDeshacer()));
}

void VentanaPrincipal::createMenus() {
  fileMenu = menuBar()->addMenu(tr("&Archivo"));
  fileMenu->addAction(accionSalir);
  fileMenu->addAction(accionAbrir);
  fileMenu->addAction(accionGuardar);
  fileMenu->addAction(accionNuevo);

  editMenu = menuBar()->addMenu(tr("&Editar"));
  editMenu->addAction(accionBuscar);
  editMenu->addAction(accionDeshacer);

  for (int i = 0; i < MAX_RECENT_FILES; i++) {
    fileMenu->addAction(accionesFicherosRecientes[i]);
  }

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

void VentanaPrincipal::createStatusBar() {
  etiquetaEstado = new QLabel("Hola");
  statusBar()->addWidget(etiquetaEstado);
}

void VentanaPrincipal::slotNuevo() {
  if (!documentoModificado) {
      editorCentral->document()->clear();
      return;
  }

  int respuesta = QMessageBox::warning(this, tr("nuevo doc"),
  tr("Borro el documento ?"), QMessageBox::Yes | QMessageBox::No);


  if (respuesta == QMessageBox::Yes) {
    editorCentral->document()->clear();
    documentoModificado = false;
  }
}

void VentanaPrincipal::slotActualizarBarraEstado() {
  QTextDocument * documento;
  documento = editorCentral->document();

  documentoModificado = true;
  int numLineas;
  numLineas = documento->lineCount();

  QString texto("Modificado\tLineas: " + QString::number(numLineas));
  etiquetaEstado->setText(texto);
}

void VentanaPrincipal::slotAbrir() {
  QString fileName = QFileDialog::getOpenFileName(this,
                                   tr("Abrir un documentillo"), ".",
                                   tr("Fisheros de tejto (*.txt)"));

  if (!fileName.isEmpty()){
      abrirFichero(fileName);
  }
}

bool VentanaPrincipal::abrirFichero(QString nombreFichero) {
  editorCentral->document()->clear();
  QFile fichero(nombreFichero);

  if (!fichero.open(QIODevice::ReadOnly)) {
                QMessageBox::warning(this, tr("Editor"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fichero.fileName())
                             .arg(fichero.errorString()));
     return false;
  }

  QTextStream stream(&fichero);

  while (!stream.atEnd()){
    editorCentral->append(stream.readLine());
  }

  documentoModificado = false;
  establecerFicheroActual(nombreFichero);

  return true;
}

void VentanaPrincipal::closeEvent (QCloseEvent * event) {
  QTextDocument * documento;
  documento = editorCentral->document();
  int numLineas;
  numLineas = documento->lineCount();

  if (documentoModificado) {
    int respuesta = QMessageBox::warning(this, tr("Editor"),
                            tr("The document has been modified.\n"
                                "Do you want to save your changes?"),
                            QMessageBox::Yes | QMessageBox::No
                            | QMessageBox::Cancel);

    if (respuesta == QMessageBox::No) {
      event->accept();
    } else if (respuesta == QMessageBox::Cancel) {
      event->ignore();
    } else {
      //editorCentral->append(QString("Guardado"));
      QString texto("Guardado\tLineas: " + QString::number(numLineas));
      etiquetaEstado->setText(texto);
      documentoModificado = false;
      event->ignore();
    }
  }
}

void VentanaPrincipal::establecerFicheroActual(QString ruta) {
  ficherosRecientes.removeAll(ruta);
  ficherosRecientes.prepend(ruta);

  QMutableStringListIterator i(ficherosRecientes);

  while (i.hasNext()) {
    if (!QFile::exists(i.next()))
      i.remove();
  }

  if (ficherosRecientes.size() > MAX_RECENT_FILES) {
    ficherosRecientes.removeAt(MAX_RECENT_FILES);
  }

  for (int i = 0; i < MAX_RECENT_FILES; i++) {
    accionesFicherosRecientes[i]->setVisible(false);
  }

  QStringListIterator ii(ficherosRecientes);
  int indice = 0;

  while (ii.hasNext()) {
    QString ruta = ii.next();
    QString nombreCorto = QFileInfo(ruta).fileName();
    accionesFicherosRecientes[indice]->setText(nombreCorto);
    accionesFicherosRecientes[indice]->setVisible(true);
    editorCentral->append(ruta);
    indice++;
  }
}

void VentanaPrincipal::slotAbrirFicheroReciente() {
  QAction *culpable = qobject_cast<QAction *> (sender());
  editorCentral->append(QString("Abierto fichero reciente."));
}

void VentanaPrincipal::slotBuscar() {
  FindDialog *dialog = new FindDialog(this);

  connect(dialog,SIGNAL(findNext(const QString &, Qt::CaseSensitivity)),
          this, SLOT(slotBuscarNext(const QString &, Qt::CaseSensitivity)));
  connect(dialog,SIGNAL(findPrevious(const QString &, Qt::CaseSensitivity)),
          this, SLOT(slotBuscarPrevious(const QString &, Qt::CaseSensitivity)));

  dialog->show();
}

void VentanaPrincipal::slotBuscarNext(const QString &str, Qt::CaseSensitivity cs) {
  //FindDialog *nextDialog = new FindDialog(this);
  //connect(nextDialog.SIGNAL(findNext(const QString&, )))
  #ifdef NOCOMPILA
  editorCentral->append(str);
  QTextDocument::FindFlags flags = 0;

  if (cs == Qt::CaseSensitive) {
    flags = flags | QTextDocument::FindCaseSensitively;
  }

  editorCentral->find(str, flags);
  #endif
}

void VentanaPrincipal::slotBuscarPrevious(const QString &str, Qt::CaseSensitivity cs) {
  editorCentral->find(str,QTextDocument::FindBackward);
}

void VentanaPrincipal::slotDeshacer() {
  DialogoDeshacer *dialog = new DialogoDeshacer(this);
  dialog->puntero(editorCentral);
  dialog->show();
}
