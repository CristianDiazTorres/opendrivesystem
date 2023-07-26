/********************************************************************************
** Form generated from reading UI file 'NewCurvatureSlopeDataChooseDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWCURVATURESLOPEDATACHOOSEDLG_H
#define UI_NEWCURVATURESLOPEDATACHOOSEDLG_H

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

class Ui_NewCurvatureSlopeDataChooseDlg
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *pathEdt;
    QPushButton *browseBtn;

    void setupUi(QDialog *NewCurvatureSlopeDataChooseDlg)
    {
        if (NewCurvatureSlopeDataChooseDlg->objectName().isEmpty())
            NewCurvatureSlopeDataChooseDlg->setObjectName(QStringLiteral("NewCurvatureSlopeDataChooseDlg"));
        NewCurvatureSlopeDataChooseDlg->resize(661, 142);
        buttonBox = new QDialogButtonBox(NewCurvatureSlopeDataChooseDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(290, 90, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(NewCurvatureSlopeDataChooseDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 181, 16));
        pathEdt = new QLineEdit(NewCurvatureSlopeDataChooseDlg);
        pathEdt->setObjectName(QStringLiteral("pathEdt"));
        pathEdt->setGeometry(QRect(30, 50, 551, 21));
        pathEdt->setReadOnly(true);
        browseBtn = new QPushButton(NewCurvatureSlopeDataChooseDlg);
        browseBtn->setObjectName(QStringLiteral("browseBtn"));
        browseBtn->setGeometry(QRect(590, 50, 41, 21));

        retranslateUi(NewCurvatureSlopeDataChooseDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewCurvatureSlopeDataChooseDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewCurvatureSlopeDataChooseDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewCurvatureSlopeDataChooseDlg);
    } // setupUi

    void retranslateUi(QDialog *NewCurvatureSlopeDataChooseDlg)
    {
        NewCurvatureSlopeDataChooseDlg->setWindowTitle(QApplication::translate("NewCurvatureSlopeDataChooseDlg", "Choose New Curvature & Slope Folder", Q_NULLPTR));
        label->setText(QApplication::translate("NewCurvatureSlopeDataChooseDlg", "Curvature & Slope Data Path", Q_NULLPTR));
        browseBtn->setText(QApplication::translate("NewCurvatureSlopeDataChooseDlg", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewCurvatureSlopeDataChooseDlg: public Ui_NewCurvatureSlopeDataChooseDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCURVATURESLOPEDATACHOOSEDLG_H
