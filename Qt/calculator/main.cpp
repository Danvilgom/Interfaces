#include <QApplication>

#include "calculator.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Calculator *dialog = new Calculator;
    dialog->show();
    return app.exec();
}
