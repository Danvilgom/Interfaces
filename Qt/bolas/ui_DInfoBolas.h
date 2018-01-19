/********************************************************************************
** Form generated from reading UI file 'DInfoBolas.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DINFOBOLAS_H
#define UI_DINFOBOLAS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>

QT_BEGIN_NAMESPACE

class Ui_QInfoBox
{
public:
    QDialogButtonBox *buttonBox;
    QListView *listaBolas;
    QComboBox *comboBox;
    QLabel *labelFrecuencia;

    void setupUi(QDialog *QInfoBox)
    {
        if (QInfoBox->objectName().isEmpty())
            QInfoBox->setObjectName(QString::fromUtf8("QInfoBox"));
        QInfoBox->resize(400, 302);
        buttonBox = new QDialogButtonBox(QInfoBox);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(20, 250, 361, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        listaBolas = new QListView(QInfoBox);
        listaBolas->setObjectName(QString::fromUtf8("listaBolas"));
        listaBolas->setGeometry(QRect(20, 20, 361, 161));
        comboBox = new QComboBox(QInfoBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(210, 200, 171, 30));
        labelFrecuencia = new QLabel(QInfoBox);
        labelFrecuencia->setObjectName(QString::fromUtf8("labelFrecuencia"));
        labelFrecuencia->setGeometry(QRect(20, 210, 181, 20));

        retranslateUi(QInfoBox);
        QObject::connect(buttonBox, SIGNAL(accepted()), QInfoBox, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QInfoBox, SLOT(reject()));

        QMetaObject::connectSlotsByName(QInfoBox);
    } // setupUi

    void retranslateUi(QDialog *QInfoBox)
    {
        QInfoBox->setWindowTitle(QApplication::translate("QInfoBox", "Dialog", 0, QApplication::UnicodeUTF8));
        labelFrecuencia->setText(QApplication::translate("QInfoBox", "Frecuencia de actualizaci\303\263n:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QInfoBox: public Ui_QInfoBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DINFOBOLAS_H
