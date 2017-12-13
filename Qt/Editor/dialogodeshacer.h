#ifndef DIALOGODESHACER_H
#define DIALOGODESHACER_H
#include <QDialog>
#include <QTextEdit>
#include "ui_dialogodeshacer.h"

class DialogoDeshacer : public QDialog, public Ui::DialogoDeshacer
{
     Q_OBJECT

 public:
     DialogoDeshacer(QWidget *parent = 0);
     void puntero(QTextEdit *);
     QTextEdit *editor;

 private slots:
     void DeshacerSlot();
     void slotDisabledDeshacer(bool);
     void slotDisabledRehacer(bool);
 };

#endif
