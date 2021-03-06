#include <QPainter>
#include <QColor>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <stdlib.h>
#include "math.h"
#include "MainWindow.h"
#include "Bola.h"
#include "DInformacion.h"

MainWindow::MainWindow ( QWidget * parent , Qt::WindowFlags flags) :
                  QMainWindow (parent, flags) {

          Bola::diametro=40;
          resize(800,600);

          temporizador = new QTimer();
          temporizador->setSingleShot(false);
          temporizador->setInterval(10);

          connect(temporizador,SIGNAL(timeout()),this, SLOT(slotRepintar()));
          temporizador->start();

          inicializarBolas();

          createActions();
          createMenus();
}

void MainWindow::createActions() {
  accionInformacion = new QAction(tr("&Ver Info"), this);
  accionPosInfo = new QAction(tr("&Información de las posiciones"))

  connect(accionInformacion,SIGNAL(triggered()),this, SLOT(slotMostrarDialogoInfo()));
  connect(accionPosInfo,SIGNAL(triggered()),this, SLOT(slotDInfoBolas()));
}

void MainWindow::createMenus() {
  menuArchivo = menuBar()->addMenu("Archivo");
  menuPosInfo = menuBar()->addMenu("Info");
  menuArchivo->addAction(accionInformacion);
  menuPosInfo->addAction(accionPosInfo);
}

void MainWindow::paintEvent( QPaintEvent *e ) {
  QPainter pintor(this);

  for (int i = 0; i < bolas.size(); i++) {
    bolas[i]->pintar(pintor);
    bolas[i]->mueve(width(), height());
  }

  bolaJugador->mueve(width(), height());
  pintor.setBrush(QBrush(Qt::black));
  pintor.drawEllipse(bolaJugador->posX,bolaJugador->posY, Bola::diametro, Bola::diametro);
}

void MainWindow::slotRepintar() {
  for (int i = 0; i < bolas.size(); i++) {
    for (int j = 0; j < bolas.size(); j++) {
      if (bolas[i]->choca(bolas[j])) {
          bolas[i]->vida--;
          bolas[j]->vida--;
      }//if
    }
  }

  update();
  //setFocus();
}

void MainWindow::inicializarBolas() {
  for (int i = 0; i < 10; i++) {
    float px = random()% width();
    float py = random()% height();
    float vx = (random() % 100) / 100.1 - 0.49;
    float vy = (random() % 100) / 100.1 - 0.49;
    bolas.append(new Bola(px, py, vx, vy));
  }

  float px = random()% width();
  float py = random()% height();
  float vx = 0; // (random() % 100) / 100.1 - 0.49;
  float vy = 0; // (random() % 100) / 100.1 - 0.49;
  bolaJugador = new Bola(px, py, vx, vy);
}

void MainWindow::keyPressEvent(QKeyEvent * event) {
  switch (event->key()) {
    case Qt::Key_Left : bolaJugador->velX -= 0.2 ; break;
    case Qt::Key_Up   : bolaJugador->velY -= 0.2 ; break;
    case Qt::Key_Down : bolaJugador->velY += 0.2 ; break;
    case Qt::Key_Right: bolaJugador->velX += 0.2 ; break;
  }
}

/* SLOTS */
void MainWindow::slotMostrarDialogoInfo() {
  DInformacion *dialogo = new DInformacion();
  dialogo->pasarInfo(bolas.size(),width(),height());
  dialogo->show();
}

void MainWindow::slotDInfoBolas() {
  if (dInfoBolas == NULL) {
    dInfoBolas = new DInfoBolas(bolas, this);
  }
}
