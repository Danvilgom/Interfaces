/********************************************************************************
** Form generated from reading UI file 'dialogodeshacer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGODESHACER_H
#define UI_DIALOGODESHACER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogoDeshacer
{
public:
    QPushButton *Deshacer;
    QPushButton *Rehacer;
    QTextEdit *textEdit;

    void setupUi(QDialog *DialogoDeshacer)
    {
        if (DialogoDeshacer->objectName().isEmpty())
            DialogoDeshacer->setObjectName(QStringLiteral("DialogoDeshacer"));
        DialogoDeshacer->resize(400, 99);
        Deshacer = new QPushButton(DialogoDeshacer);
        Deshacer->setObjectName(QStringLiteral("Deshacer"));
        Deshacer->setGeometry(QRect(70, 50, 99, 27));
        Rehacer = new QPushButton(DialogoDeshacer);
        Rehacer->setObjectName(QStringLiteral("Rehacer"));
        Rehacer->setGeometry(QRect(210, 50, 99, 27));
        textEdit = new QTextEdit(DialogoDeshacer);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(70, 10, 241, 31));

        retranslateUi(DialogoDeshacer);

        QMetaObject::connectSlotsByName(DialogoDeshacer);
    } // setupUi

    void retranslateUi(QDialog *DialogoDeshacer)
    {
        DialogoDeshacer->setWindowTitle(QApplication::translate("DialogoDeshacer", "Dialog", Q_NULLPTR));
        Deshacer->setText(QApplication::translate("DialogoDeshacer", "Deshacer", Q_NULLPTR));
        Rehacer->setText(QApplication::translate("DialogoDeshacer", "Rehacer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoDeshacer: public Ui_DialogoDeshacer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGODESHACER_H
