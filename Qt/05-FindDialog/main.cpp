 #include <QApplication>

#include "dialogo.h"

int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     Dialogo *midialog = new Dialogo;
     midialog->show();


     return app.exec();
 }
