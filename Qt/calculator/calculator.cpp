#include "calculator.h"

Calculator::Calculator(QWidget * parent) : QWidget(parent){

  setupUi(this);
      connect(b0,SIGNAL(clicked()),this,SLOT(ponCero()));
      connect(b1,SIGNAL(clicked()),this,SLOT(ponUno()));
  }

  void Calculator::ponCero(){
      display->setText(display->text() + "0");
  }

  void Calculator::ponUno(){
      display->setText(display->text() + "1");
  }
