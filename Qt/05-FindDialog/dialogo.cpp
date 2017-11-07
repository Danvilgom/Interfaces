#include <QtGui>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QCheckBox>
#include "dialogo.h"

Dialogo::Dialogo(QWidget *parent) : QDialog(parent) {

  boton1 = new QPushButton("uno");
  boton2 = new QPushButton("dos");
  boton3 = new QPushButton("tres");

  topLeftLayout->addWidget(boton1);
  topLeftLayout->addWidget(boton2);
  topLeftLayout->addWidget(boton3);

  check1 = new QCheckBox("Juan");
  check2 = new QCheckBox("Perico");
  check3 = new QCheckBox("Andres");

  topCentralLayout = new QVBoxLayout;
  topCentralLayout->addWidget(check1);
  topCentralLayout->addWidget(check2);
  topCentralLayout->addWidget(check3);
  topCentralLayout->addStretch();

  leftLayout = new QHBoxLayout;
  leftLayout->addLayout(topLeftLayout);
  leftLayout->addLayout(topCentralLayout);

  bigLeftLayout = new QVBoxLayout;
  slider = new QSlider(Qt::Horizontal);

  bigLeftLayout->addLayout(leftLayout);
  bigLeftLayout->addWidget(slider);

  rightLayout = new QVBoxLayout;
  topLayout = new QHBoxLayout;
  bottomLayout = new QHBoxLayout
  mainLayout = new QVBoxLayout;

  topLayout->addLayout(rightLayout);
  topLayout->addLayout();

	setLayout(bigLeftLayout);

	setWindowTitle(tr("Find"));
	setFixedHeight(sizeHint().height());

}
