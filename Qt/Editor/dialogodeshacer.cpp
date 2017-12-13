#include <QtGui>
#include "dialogodeshacer.h"

DialogoDeshacer::DialogoDeshacer(QWidget *parent) : QDialog(parent){
  setupUi(this);

  connect(Deshacer, SIGNAL(clicked()), this, SLOT(DeshacerSlot()));
  connect(Rehacer, SIGNAL(clicked()), this, SLOT(DeshacerSlot()));
}

void DialogoDeshacer::puntero(QTextEdit *edit) {
  editor = edit;
  connect(editor, SIGNAL(undoAvailable(bool)), this, SLOT(slotDisabledDeshacer(bool)));
  connect(editor, SIGNAL(redoAvailable(bool)), this, SLOT(slotDisabledRehacer(bool)));
}

void DialogoDeshacer::DeshacerSlot() {
  QPushButton *culpable = qobject_cast<QPushButton *> (sender());

  if (culpable == Deshacer) {
    editor->undo();
  } else if (culpable == Rehacer) {
    editor->redo();
  }
}

void DialogoDeshacer::slotDisabledDeshacer(bool available) {
  if (available == true) {
    Deshacer->setEnabled(true);
  } else {
    Deshacer->setEnabled(false);
  }
}

void DialogoDeshacer::slotDisabledRehacer(bool available) {
  if (available == true) {
    Rehacer->setEnabled(true);
  } else {
    Rehacer->setEnabled(false);
  }
}
