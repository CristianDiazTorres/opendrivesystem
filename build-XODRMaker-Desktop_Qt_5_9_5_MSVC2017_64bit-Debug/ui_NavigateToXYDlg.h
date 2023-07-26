/********************************************************************************
** Form generated from reading UI file 'NavigateToXYDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVIGATETOXYDLG_H
#define UI_NAVIGATETOXYDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_NavigateToXYDlg
{
public:
    QLabel *label;
    QLineEdit *xyEdt;
    QLabel *label_2;
    QLineEdit *llEdt;
    QPushButton *navigateBtn;
    QPushButton *closeBtn;

    void setupUi(QDialog *NavigateToXYDlg)
    {
        if (NavigateToXYDlg->objectName().isEmpty())
            NavigateToXYDlg->setObjectName(QStringLiteral("NavigateToXYDlg"));
        NavigateToXYDlg->setWindowModality(Qt::NonModal);
        NavigateToXYDlg->resize(400, 183);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NavigateToXYDlg->sizePolicy().hasHeightForWidth());
        NavigateToXYDlg->setSizePolicy(sizePolicy);
        NavigateToXYDlg->setModal(false);
        label = new QLabel(NavigateToXYDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 61, 21));
        xyEdt = new QLineEdit(NavigateToXYDlg);
        xyEdt->setObjectName(QStringLiteral("xyEdt"));
        xyEdt->setGeometry(QRect(100, 30, 251, 21));
        label_2 = new QLabel(NavigateToXYDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 80, 47, 13));
        llEdt = new QLineEdit(NavigateToXYDlg);
        llEdt->setObjectName(QStringLiteral("llEdt"));
        llEdt->setGeometry(QRect(100, 80, 251, 21));
        llEdt->setReadOnly(true);
        navigateBtn = new QPushButton(NavigateToXYDlg);
        navigateBtn->setObjectName(QStringLiteral("navigateBtn"));
        navigateBtn->setGeometry(QRect(170, 130, 75, 23));
        closeBtn = new QPushButton(NavigateToXYDlg);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setGeometry(QRect(270, 130, 75, 23));

        retranslateUi(NavigateToXYDlg);

        QMetaObject::connectSlotsByName(NavigateToXYDlg);
    } // setupUi

    void retranslateUi(QDialog *NavigateToXYDlg)
    {
        NavigateToXYDlg->setWindowTitle(QApplication::translate("NavigateToXYDlg", "Navigate", Q_NULLPTR));
        label->setText(QApplication::translate("NavigateToXYDlg", "X, Y", Q_NULLPTR));
        label_2->setText(QApplication::translate("NavigateToXYDlg", "Lat, Lon", Q_NULLPTR));
        navigateBtn->setText(QApplication::translate("NavigateToXYDlg", "Navigate", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("NavigateToXYDlg", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NavigateToXYDlg: public Ui_NavigateToXYDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVIGATETOXYDLG_H
