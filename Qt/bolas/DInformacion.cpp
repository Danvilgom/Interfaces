#include  "DInformacion.h"

DInformacion::DInformacion(QWidget *parent) : QDialog(parent) {
    setupUi(this);
}

void DInformacion::pasarInfo(int numBolas, int anchura, int altura) {
  etiquetaNumBolas->setText(QString::number(numBolas));
  etiquetaTamanyo->setText(QString::number(anchura) + " x " + QString::number(altura));
}
