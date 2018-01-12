#ifndef _MAINWINDOW_
#define _MAINWINDOW_

#include <QMainWindow>
#include <QPaintEvent>
#include <QTimer>
#include <QVector>
#include <QMenu>
#include <QAction>
#include <QKeyEvent>
#include "Bola.h"

class MainWindow : public QMainWindow {
  Q_OBJECT

public:

  MainWindow ( QWidget * parent = 0, Qt::WindowFlags flags = 0 ) ;
  virtual void paintEvent( QPaintEvent * e );
  virtual void keyPressEvent( QKeyEvent * e );
  QTimer * temporizador;
  QVector<Bola *> bolas;
  Bola * bolaJugador;
  QMenu * menuArchivo;
  QAction * accionInformacion;

  float posX;
  float posY;
  float velX;
  float velY;

  void createActions();
  void createMenus();
  void inicializarBolas();

public slots:

  void slotRepintar();
  void slotMostrarDialogoInfo();
};

#endif
