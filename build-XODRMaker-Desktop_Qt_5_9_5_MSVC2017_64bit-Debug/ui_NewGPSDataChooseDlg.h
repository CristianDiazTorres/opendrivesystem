/********************************************************************************
** Form generated from reading UI file 'NewGPSDataChooseDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWGPSDATACHOOSEDLG_H
#define UI_NEWGPSDATACHOOSEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_NewGPSDataChooseDlg
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *gpsPathEdt;
    QPushButton *browseBtn;

    void setupUi(QDialog *NewGPSDataChooseDlg)
    {
        if (NewGPSDataChooseDlg->objectName().isEmpty())
            NewGPSDataChooseDlg->setObjectName(QStringLiteral("NewGPSDataChooseDlg"));
        NewGPSDataChooseDlg->resize(661, 166);
        buttonBox = new QDialogButtonBox(NewGPSDataChooseDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(290, 110, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(NewGPSDataChooseDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 91, 16));
        gpsPathEdt = new QLineEdit(NewGPSDataChooseDlg);
        gpsPathEdt->setObjectName(QStringLiteral("gpsPathEdt"));
        gpsPathEdt->setGeometry(QRect(30, 50, 551, 21));
        gpsPathEdt->setReadOnly(true);
        browseBtn = new QPushButton(NewGPSDataChooseDlg);
        browseBtn->setObjectName(QStringLiteral("browseBtn"));
        browseBtn->setGeometry(QRect(590, 50, 41, 21));

        retranslateUi(NewGPSDataChooseDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewGPSDataChooseDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewGPSDataChooseDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewGPSDataChooseDlg);
    } // setupUi

    void retranslateUi(QDialog *NewGPSDataChooseDlg)
    {
        NewGPSDataChooseDlg->setWindowTitle(QApplication::translate("NewGPSDataChooseDlg", "Choose New GPS File", Q_NULLPTR));
        label->setText(QApplication::translate("NewGPSDataChooseDlg", "GPS File Path", Q_NULLPTR));
        browseBtn->setText(QApplication::translate("NewGPSDataChooseDlg", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewGPSDataChooseDlg: public Ui_NewGPSDataChooseDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGPSDATACHOOSEDLG_H
