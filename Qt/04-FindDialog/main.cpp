 #include <QApplication>

#include "finddialog.h"

int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     FindDialog *midialog = new FindDialog;
     midialog->show();


     return app.exec();
 }
