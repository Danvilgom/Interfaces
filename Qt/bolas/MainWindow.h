#ifndef _MAINWINDOW_
#define _MAINWINDOW_

#include <QMainWindow>
#include <QPaintEvent>
#include <QTimer>
#include <QVector>
#include "Bola.h"

class MainWindow : public QMainWindow {
  Q_OBJECT

public:

  MainWindow ( QWidget * parent = 0, Qt::WindowFlags flags = 0 ) ;
  virtual void paintEvent( QPaintEvent * e );
  QTimer * temporizador;
  QVector<Bola *> bolas;

  float posX;
  float posY;
  float velX;
  float velY;

public slots:

  void slotRepintar();
  void inicializarBolas();
};

#endif
