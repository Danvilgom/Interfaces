/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPlainTextEdit *plainText;
    QPushButton *btn_plus;
    QPushButton *btn_enter;
    QPushButton *btn_0;
    QPushButton *btn_dot;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *btn_7;
    QPushButton *btn_8;
    QPushButton *pushButton_3;
    QPushButton *btn_4;
    QPushButton *btn_5;
    QPushButton *btn_6;
    QPushButton *btn_1;
    QPushButton *btn_2;
    QPushButton *btn_3;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(353, 190);
        plainText = new QPlainTextEdit(Dialog);
        plainText->setObjectName(QStringLiteral("plainText"));
        plainText->setEnabled(false);
        plainText->setGeometry(QRect(12, 10, 331, 31));
        btn_plus = new QPushButton(Dialog);
        btn_plus->setObjectName(QStringLiteral("btn_plus"));
        btn_plus->setGeometry(QRect(292, 50, 51, 61));
        btn_enter = new QPushButton(Dialog);
        btn_enter->setObjectName(QStringLiteral("btn_enter"));
        btn_enter->setGeometry(QRect(292, 120, 51, 61));
        btn_0 = new QPushButton(Dialog);
        btn_0->setObjectName(QStringLiteral("btn_0"));
        btn_0->setGeometry(QRect(12, 150, 181, 27));
        btn_dot = new QPushButton(Dialog);
        btn_dot->setObjectName(QStringLiteral("btn_dot"));
        btn_dot->setGeometry(QRect(200, 150, 81, 27));
        widget = new QWidget(Dialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(12, 50, 269, 95));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btn_7 = new QPushButton(widget);
        btn_7->setObjectName(QStringLiteral("btn_7"));

        gridLayout->addWidget(btn_7, 0, 0, 1, 1);

        btn_8 = new QPushButton(widget);
        btn_8->setObjectName(QStringLiteral("btn_8"));

        gridLayout->addWidget(btn_8, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        btn_4 = new QPushButton(widget);
        btn_4->setObjectName(QStringLiteral("btn_4"));

        gridLayout->addWidget(btn_4, 1, 0, 1, 1);

        btn_5 = new QPushButton(widget);
        btn_5->setObjectName(QStringLiteral("btn_5"));

        gridLayout->addWidget(btn_5, 1, 1, 1, 1);

        btn_6 = new QPushButton(widget);
        btn_6->setObjectName(QStringLiteral("btn_6"));

        gridLayout->addWidget(btn_6, 1, 2, 1, 1);

        btn_1 = new QPushButton(widget);
        btn_1->setObjectName(QStringLiteral("btn_1"));

        gridLayout->addWidget(btn_1, 2, 0, 1, 1);

        btn_2 = new QPushButton(widget);
        btn_2->setObjectName(QStringLiteral("btn_2"));

        gridLayout->addWidget(btn_2, 2, 1, 1, 1);

        btn_3 = new QPushButton(widget);
        btn_3->setObjectName(QStringLiteral("btn_3"));

        gridLayout->addWidget(btn_3, 2, 2, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        btn_plus->setText(QApplication::translate("Dialog", "+", Q_NULLPTR));
        btn_enter->setText(QApplication::translate("Dialog", "Enter", Q_NULLPTR));
        btn_0->setText(QApplication::translate("Dialog", "0", Q_NULLPTR));
        btn_dot->setText(QApplication::translate("Dialog", ".", Q_NULLPTR));
        btn_7->setText(QApplication::translate("Dialog", "7", Q_NULLPTR));
        btn_8->setText(QApplication::translate("Dialog", "8", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Dialog", "9", Q_NULLPTR));
        btn_4->setText(QApplication::translate("Dialog", "4", Q_NULLPTR));
        btn_5->setText(QApplication::translate("Dialog", "5", Q_NULLPTR));
        btn_6->setText(QApplication::translate("Dialog", "6", Q_NULLPTR));
        btn_1->setText(QApplication::translate("Dialog", "1", Q_NULLPTR));
        btn_2->setText(QApplication::translate("Dialog", "2", Q_NULLPTR));
        btn_3->setText(QApplication::translate("Dialog", "3", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
