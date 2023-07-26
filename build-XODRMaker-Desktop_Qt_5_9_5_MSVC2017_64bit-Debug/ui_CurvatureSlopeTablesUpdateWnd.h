/********************************************************************************
** Form generated from reading UI file 'CurvatureSlopeTablesUpdateWnd.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURVATURESLOPETABLESUPDATEWND_H
#define UI_CURVATURESLOPETABLESUPDATEWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CurvatureSlopeTablesUpdateWnd
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *pathEdt;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QProgressBar *progressBar;
    QPlainTextEdit *logEdt;

    void setupUi(QWidget *CurvatureSlopeTablesUpdateWnd)
    {
        if (CurvatureSlopeTablesUpdateWnd->objectName().isEmpty())
            CurvatureSlopeTablesUpdateWnd->setObjectName(QStringLiteral("CurvatureSlopeTablesUpdateWnd"));
        CurvatureSlopeTablesUpdateWnd->resize(650, 560);
        verticalLayout_2 = new QVBoxLayout(CurvatureSlopeTablesUpdateWnd);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(CurvatureSlopeTablesUpdateWnd);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label);

        pathEdt = new QTextEdit(CurvatureSlopeTablesUpdateWnd);
        pathEdt->setObjectName(QStringLiteral("pathEdt"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pathEdt->sizePolicy().hasHeightForWidth());
        pathEdt->setSizePolicy(sizePolicy1);
        pathEdt->setMaximumSize(QSize(16777215, 20));
        pathEdt->setReadOnly(true);

        verticalLayout->addWidget(pathEdt);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(CurvatureSlopeTablesUpdateWnd);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        progressBar = new QProgressBar(CurvatureSlopeTablesUpdateWnd);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        horizontalLayout_5->addWidget(progressBar);


        verticalLayout_2->addLayout(horizontalLayout_5);

        logEdt = new QPlainTextEdit(CurvatureSlopeTablesUpdateWnd);
        logEdt->setObjectName(QStringLiteral("logEdt"));

        verticalLayout_2->addWidget(logEdt);


        retranslateUi(CurvatureSlopeTablesUpdateWnd);

        QMetaObject::connectSlotsByName(CurvatureSlopeTablesUpdateWnd);
    } // setupUi

    void retranslateUi(QWidget *CurvatureSlopeTablesUpdateWnd)
    {
        CurvatureSlopeTablesUpdateWnd->setWindowTitle(QApplication::translate("CurvatureSlopeTablesUpdateWnd", "Update Curvature & Slope", Q_NULLPTR));
        label->setText(QApplication::translate("CurvatureSlopeTablesUpdateWnd", "Curvature & Slope Data Path", Q_NULLPTR));
        label_6->setText(QApplication::translate("CurvatureSlopeTablesUpdateWnd", "Progress", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CurvatureSlopeTablesUpdateWnd: public Ui_CurvatureSlopeTablesUpdateWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVATURESLOPETABLESUPDATEWND_H
