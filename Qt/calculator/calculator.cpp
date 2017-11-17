#include "calculator.h"

Calculator::Calculator(QWidget * parent) : QWidget(parent){

  setupUi(this);
      connect(btn_1,SIGNAL(clicked()),this,SLOT(ponCero()));
      connect(btn_2,SIGNAL(clicked()),this,SLOT(ponUno()));
      connect(btn_3,SIGNAL(clicked()),this,SLOT()
  }

  void Calculator::ponCero(){
      display->setText(display->text() + "0");
  }

  void Calculator::ponUno(){
      display->setText(display->text() + "1");
  }
