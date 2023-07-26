/********************************************************************************
** Form generated from reading UI file 'GPSTablesUpdateWnd.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GPSTABLESUPDATEWND_H
#define UI_GPSTABLESUPDATEWND_H

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

class Ui_GPSTablesUpdateWnd
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *gpsPathEdt;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QProgressBar *progressBar;
    QPlainTextEdit *logEdt;

    void setupUi(QWidget *GPSTablesUpdateWnd)
    {
        if (GPSTablesUpdateWnd->objectName().isEmpty())
            GPSTablesUpdateWnd->setObjectName(QStringLiteral("GPSTablesUpdateWnd"));
        GPSTablesUpdateWnd->resize(650, 560);
        verticalLayout_2 = new QVBoxLayout(GPSTablesUpdateWnd);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(GPSTablesUpdateWnd);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label);

        gpsPathEdt = new QTextEdit(GPSTablesUpdateWnd);
        gpsPathEdt->setObjectName(QStringLiteral("gpsPathEdt"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(gpsPathEdt->sizePolicy().hasHeightForWidth());
        gpsPathEdt->setSizePolicy(sizePolicy1);
        gpsPathEdt->setMaximumSize(QSize(16777215, 20));
        gpsPathEdt->setReadOnly(true);

        verticalLayout->addWidget(gpsPathEdt);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(GPSTablesUpdateWnd);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        progressBar = new QProgressBar(GPSTablesUpdateWnd);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        horizontalLayout_5->addWidget(progressBar);


        verticalLayout_2->addLayout(horizontalLayout_5);

        logEdt = new QPlainTextEdit(GPSTablesUpdateWnd);
        logEdt->setObjectName(QStringLiteral("logEdt"));

        verticalLayout_2->addWidget(logEdt);


        retranslateUi(GPSTablesUpdateWnd);

        QMetaObject::connectSlotsByName(GPSTablesUpdateWnd);
    } // setupUi

    void retranslateUi(QWidget *GPSTablesUpdateWnd)
    {
        GPSTablesUpdateWnd->setWindowTitle(QApplication::translate("GPSTablesUpdateWnd", "Update GPS", Q_NULLPTR));
        label->setText(QApplication::translate("GPSTablesUpdateWnd", "GPS File Path", Q_NULLPTR));
        label_6->setText(QApplication::translate("GPSTablesUpdateWnd", "Progress", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GPSTablesUpdateWnd: public Ui_GPSTablesUpdateWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GPSTABLESUPDATEWND_H
