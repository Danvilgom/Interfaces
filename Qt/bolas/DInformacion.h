#ifndef DINFORMACION_H
#define DINFORMACION_H
#include <QDialog>
#include "ui_DInformacion.h"

class DInformacion : public QDialog,  public Ui::DInformacion {
  Q_OBJECT

public:
    DInformacion(QWidget *parent=0);
    void pasarInfo(int, int, int);
};

#endif  //DINFORMACION_H
