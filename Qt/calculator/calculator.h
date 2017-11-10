#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QDialog>

#include "ui_calculator.h"

class Calculator : public QDialog, public Ui::Calculator
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = 0);

private slots:
    void on_lineEdit_textChanged();
};

#endif
