#ifndef FINDDIALOG_H
#define FINDDIALOG_H
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDialog>

class FindDialog : public QDialog
{
     Q_OBJECT

 public:
     FindDialog(QWidget *parent = 0);

     QLabel *label;
     QLineEdit *lineEdit;
     QCheckBox *caseCheckBox;
     QCheckBox *backwardCheckBox;
     QPushButton *findButton;
     QPushButton *closeButton;

 signals:
     void findNext(const QString &str, Qt::CaseSensitivity cs);
     void findPrevious(const QString &str, Qt::CaseSensitivity cs);

 private slots:
     void findClicked();
     void enableFindButton(const QString &text);

 };

#endif
