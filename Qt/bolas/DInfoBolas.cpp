#include "DInfoBolas.h"

DInfoBolas::DInfoBolas(QVector<Bola*> bolasPasadas, QWidget *parent) : QDialog(parent) {
    setupUi(this);
    bolas = bolasPasadas;
    temporizador = new QTimer();
    temporizador->setSingleShot(false);
    temporizador->setInterval(500);
    connect(temporizador,SIGNAL(timeout()),this,SLOT(mostrar()));

    temporizador->start();
    mostrar();
}

void DInfoBolas::mostrar() {
  listaBolas->clear();

  for (int i = 0; i < listaBolas.size(); i++) {
    listaBolas->addItem(QString("posX:") + QString::number(bolas.at(i)->posX)+
    QString("posY= ") + QString::number(bolas.at(i)->posY) );
  }
}
