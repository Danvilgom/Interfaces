#include <QtGui>
#include "dialogodeshacer.h"

DialogoDeshacer::DialogoDeshacer(QWidget *parent) : QDialog(parent){
  setupUi(this);

  connect(Deshacer, SIGNAL(clicked()), this, SLOT(DeshacerSlot()));
  connect(Rehacer, SIGNAL(clicked()), this, SLOT(DeshacerSlot()));
}

void DialogoDeshacer::puntero(QTextEdit *edit) {
<<<<<<< HEAD
  editor = edit;
  connect(editor, SIGNAL(undoAvailable(bool)), this, SLOT(slotDisabledDeshacer(bool)));
  connect(editor, SIGNAL(redoAvailable(bool)), this, SLOT(slotDisabledRehacer(bool)));
=======
  Editor = edit;
  connect(Editor, SIGNAL(undoAvailable(bool)), this, SLOT(slotDisableDeshacer(bool)));
  connect(Editor, SIGNAL(redoAvailable(bool)), this, SLOT(slotDisableRehacer(bool)));
>>>>>>> Aplicacion bolas
}

void DialogoDeshacer::DeshacerSlot() {
  QPushButton *culpable = qobject_cast<QPushButton *> (sender());

  if (culpable == Deshacer) {
<<<<<<< HEAD
    editor->undo();
  } else if (culpable == Rehacer) {
    editor->redo();
  }
}

void DialogoDeshacer::slotDisabledDeshacer(bool available) {
=======
    Editor->undo();
  } else if (culpable == Rehacer) {
    Editor->redo();
  }
}

void DialogoDeshacer::slotDisableDeshacer(bool available) {
>>>>>>> Aplicacion bolas
  if (available == true) {
    Deshacer->setEnabled(true);
  } else {
    Deshacer->setEnabled(false);
  }
}

<<<<<<< HEAD
void DialogoDeshacer::slotDisabledRehacer(bool available) {
=======
void DialogoDeshacer::slotDisableRehacer(bool available) {
>>>>>>> Aplicacion bolas
  if (available == true) {
    Rehacer->setEnabled(true);
  } else {
    Rehacer->setEnabled(false);
  }
}
