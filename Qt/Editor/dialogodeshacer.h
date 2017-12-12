#ifndef DIALOGODESHACER_H
#define DIALOGODESHACER_H
#include <QDialog>
#include "ui_dialogodeshacer.h"

class Dialog : public QDialog, public Ui::DialogoDeshacer
{
     Q_OBJECT

 public:
     DialogoDeshacer(QWidget *parent = 0);
     void puntero(QTextEdit *editor);
     QTextEdit * Editor;

 private slots:
     void DeshacerSlot(QTextEdit *editor);

 };

#endif
