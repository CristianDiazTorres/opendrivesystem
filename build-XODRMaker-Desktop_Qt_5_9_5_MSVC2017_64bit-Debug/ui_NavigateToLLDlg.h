/********************************************************************************
** Form generated from reading UI file 'NavigateToLLDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVIGATETOLLDLG_H
#define UI_NAVIGATETOLLDLG_H

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

class Ui_NavigateToLLDlg
{
public:
    QPushButton *closeBtn;
    QLineEdit *llEdt;
    QLineEdit *xyEdt;
    QLabel *label_2;
    QLabel *label;
    QPushButton *navigateBtn;

    void setupUi(QDialog *NavigateToLLDlg)
    {
        if (NavigateToLLDlg->objectName().isEmpty())
            NavigateToLLDlg->setObjectName(QStringLiteral("NavigateToLLDlg"));
        NavigateToLLDlg->setWindowModality(Qt::NonModal);
        NavigateToLLDlg->resize(400, 187);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NavigateToLLDlg->sizePolicy().hasHeightForWidth());
        NavigateToLLDlg->setSizePolicy(sizePolicy);
        NavigateToLLDlg->setModal(false);
        closeBtn = new QPushButton(NavigateToLLDlg);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setGeometry(QRect(280, 140, 75, 23));
        llEdt = new QLineEdit(NavigateToLLDlg);
        llEdt->setObjectName(QStringLiteral("llEdt"));
        llEdt->setGeometry(QRect(110, 40, 251, 21));
        xyEdt = new QLineEdit(NavigateToLLDlg);
        xyEdt->setObjectName(QStringLiteral("xyEdt"));
        xyEdt->setGeometry(QRect(110, 90, 251, 21));
        xyEdt->setReadOnly(true);
        label_2 = new QLabel(NavigateToLLDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 90, 47, 13));
        label = new QLabel(NavigateToLLDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 61, 21));
        navigateBtn = new QPushButton(NavigateToLLDlg);
        navigateBtn->setObjectName(QStringLiteral("navigateBtn"));
        navigateBtn->setGeometry(QRect(180, 140, 75, 23));

        retranslateUi(NavigateToLLDlg);

        QMetaObject::connectSlotsByName(NavigateToLLDlg);
    } // setupUi

    void retranslateUi(QDialog *NavigateToLLDlg)
    {
        NavigateToLLDlg->setWindowTitle(QApplication::translate("NavigateToLLDlg", "Navigate", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("NavigateToLLDlg", "Close", Q_NULLPTR));
        label_2->setText(QApplication::translate("NavigateToLLDlg", "X, Y", Q_NULLPTR));
        label->setText(QApplication::translate("NavigateToLLDlg", "Lat, Lon", Q_NULLPTR));
        navigateBtn->setText(QApplication::translate("NavigateToLLDlg", "Navigate", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NavigateToLLDlg: public Ui_NavigateToLLDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVIGATETOLLDLG_H
