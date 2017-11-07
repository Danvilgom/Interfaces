#ifndef DIALOGO_H
#define DIALOGO_H
#include <QCheckBox>
#include <QPushButton>
#include <QDialog>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>

class Dialogo : public QDialog {

  public:
     Dialogo(QWidget *parent = 0);

     QPushButton * boton1, *boton2, *boton3;
     QVBoxLayout * topLeftLayout;

     QCheckBox * check1, *check2, *check3;
     QVBoxLayout * topCentralLayout;
     QHBoxLayout * leftLayout;

     QSlider * slider;
     QVBoxLayout * bigLeftLayout;

     QVBoxLayout * rightLayout;

     QHBoxLayout * topLayout;
     QHBoxLayout * bottomLayout;
     QVBoxLayout * mainLayout;
};
#endif
