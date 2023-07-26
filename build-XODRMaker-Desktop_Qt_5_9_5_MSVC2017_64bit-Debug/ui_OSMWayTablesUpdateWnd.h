/********************************************************************************
** Form generated from reading UI file 'OSMWayTablesUpdateWnd.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSMWAYTABLESUPDATEWND_H
#define UI_OSMWAYTABLESUPDATEWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OSMWayTablesUpdateWnd
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QProgressBar *progressBar;
    QPlainTextEdit *logEdt;

    void setupUi(QWidget *OSMWayTablesUpdateWnd)
    {
        if (OSMWayTablesUpdateWnd->objectName().isEmpty())
            OSMWayTablesUpdateWnd->setObjectName(QStringLiteral("OSMWayTablesUpdateWnd"));
        OSMWayTablesUpdateWnd->resize(731, 607);
        verticalLayout_2 = new QVBoxLayout(OSMWayTablesUpdateWnd);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(OSMWayTablesUpdateWnd);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        progressBar = new QProgressBar(OSMWayTablesUpdateWnd);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        horizontalLayout_5->addWidget(progressBar);


        verticalLayout_2->addLayout(horizontalLayout_5);

        logEdt = new QPlainTextEdit(OSMWayTablesUpdateWnd);
        logEdt->setObjectName(QStringLiteral("logEdt"));

        verticalLayout_2->addWidget(logEdt);


        retranslateUi(OSMWayTablesUpdateWnd);

        QMetaObject::connectSlotsByName(OSMWayTablesUpdateWnd);
    } // setupUi

    void retranslateUi(QWidget *OSMWayTablesUpdateWnd)
    {
        OSMWayTablesUpdateWnd->setWindowTitle(QApplication::translate("OSMWayTablesUpdateWnd", "Update OSM Way", Q_NULLPTR));
        label_6->setText(QApplication::translate("OSMWayTablesUpdateWnd", "Progress", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OSMWayTablesUpdateWnd: public Ui_OSMWayTablesUpdateWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSMWAYTABLESUPDATEWND_H
