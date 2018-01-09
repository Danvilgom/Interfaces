#ifndef _MAINWINDOW_
#define _MAINWINDOW_

#include <QMainWindow>
#include <QPaintEvent>
#include <QTimer>

class MainWindow : public QMainWindow {
  Q_OBJECT

public:

  MainWindow ( QWidget * parent = 0, Qt::WindowFlags flags = 0 ) ;
  virtual void paintEvent( QPaintEvent * e );
  QTimer * temporizador;

  float posX;
  float posY;
  float velX;
  float velY;

public slots:

  void slotRepintar();
};

#endif
