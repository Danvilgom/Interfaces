#include <QPainter>
#include <QColor>
#include <stdlib.h>
#include "math.h"
#include "MainWindow.h"
#include "Bola.h"

MainWindow::MainWindow ( QWidget * parent , Qt::WindowFlags flags) :
                  QMainWindow (parent, flags) {

          resize(800,600);

          temporizador = new QTimer();
          temporizador->setSingleShot(false);
          temporizador->setInterval(50);

          connect(temporizador,SIGNAL(timeout()),this, SLOT(slotRepintar()));
          temporizador->start();

          inicializarBolas();
}

void MainWindow::paintEvent( QPaintEvent * e ) {
  QPainter pintor(this);
  for (int i = 0; i < 10; i++) {
    pintor.setBrush(QColor("red"));
    pintor.drawEllipse(bolas[i]->posX,bolas[i]->posY, 40 ,40);
    bolas[i]->posX = bolas[i]->posX + bolas[i]->velX;
    bolas[i]->posY = bolas[i]->posY + bolas[i]->velY;

    if (bolas[i]->posX > width() -40 ) {
      bolas[i]->velX = -fabs(bolas[i]->velX);
    }
    if (bolas[i]->posY > height() -40) {
      bolas[i]->velY = -fabs(bolas[i]->velY);
    }

    if (bolas[i]->posX < 0) {
      bolas[i]->velX = fabs(bolas[i]->velX);
    }
    if (bolas[i]->posY < 0) {
      bolas[i]->velY = fabs(bolas[i]->velY);
    }
  }
}

void MainWindow::slotRepintar() {
  update();
}

void MainWindow::inicializarBolas() {
  for (int i = 0; i < 10; i++) {
    Bola *b = new Bola();
    b->posX = random()% width();
    b->posY = random()% height();
    b->velX = (random() % 100) / 100.1 - 0.49;
    b->velY = (random() % 100) / 100.1 - 0.49;
    bolas.append(b);
  }
}
