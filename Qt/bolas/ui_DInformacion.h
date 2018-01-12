/********************************************************************************
** Form generated from reading UI file 'DInformacion.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DINFORMACION_H
#define UI_DINFORMACION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DInformacion
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *etiquetaNumBolas;
    QLabel *etiquetaTamanyo;

    void setupUi(QDialog *DInformacion)
    {
        if (DInformacion->objectName().isEmpty())
            DInformacion->setObjectName(QString::fromUtf8("DInformacion"));
        DInformacion->resize(400, 291);
        label = new QLabel(DInformacion);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 40, 111, 20));
        label_2 = new QLabel(DInformacion);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 100, 141, 20));
        etiquetaNumBolas = new QLabel(DInformacion);
        etiquetaNumBolas->setObjectName(QString::fromUtf8("etiquetaNumBolas"));
        etiquetaNumBolas->setGeometry(QRect(240, 40, 141, 20));
        etiquetaTamanyo = new QLabel(DInformacion);
        etiquetaTamanyo->setObjectName(QString::fromUtf8("etiquetaTamanyo"));
        etiquetaTamanyo->setGeometry(QRect(240, 100, 141, 20));

        retranslateUi(DInformacion);

        QMetaObject::connectSlotsByName(DInformacion);
    } // setupUi

    void retranslateUi(QDialog *DInformacion)
    {
        DInformacion->setWindowTitle(QApplication::translate("DInformacion", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DInformacion", "N\303\272mero de bolas", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DInformacion", "Tama\303\261o de la ventana", 0, QApplication::UnicodeUTF8));
        etiquetaNumBolas->setText(QApplication::translate("DInformacion", "TextLabel", 0, QApplication::UnicodeUTF8));
        etiquetaTamanyo->setText(QApplication::translate("DInformacion", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DInformacion: public Ui_DInformacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DINFORMACION_H
