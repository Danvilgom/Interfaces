#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QDialog>
#include "ui_calculator.h"

class Calculator : public QDialog, public Ui::Dialog {
    Q_OBJECT

public:
    Calculator(QWidget *parent = 0);

private slots:
    void ponCero();
    void ponUno();
};

#endif
