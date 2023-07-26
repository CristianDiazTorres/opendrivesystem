/********************************************************************************
** Form generated from reading UI file 'OSMNodeTablesUpdateWnd.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSMNODETABLESUPDATEWND_H
#define UI_OSMNODETABLESUPDATEWND_H

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

class Ui_OSMNodeTablesUpdateWnd
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QProgressBar *progressBar;
    QPlainTextEdit *logEdt;

    void setupUi(QWidget *OSMNodeTablesUpdateWnd)
    {
        if (OSMNodeTablesUpdateWnd->objectName().isEmpty())
            OSMNodeTablesUpdateWnd->setObjectName(QStringLiteral("OSMNodeTablesUpdateWnd"));
        OSMNodeTablesUpdateWnd->resize(731, 607);
        verticalLayout_2 = new QVBoxLayout(OSMNodeTablesUpdateWnd);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(OSMNodeTablesUpdateWnd);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        progressBar = new QProgressBar(OSMNodeTablesUpdateWnd);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        horizontalLayout_5->addWidget(progressBar);


        verticalLayout_2->addLayout(horizontalLayout_5);

        logEdt = new QPlainTextEdit(OSMNodeTablesUpdateWnd);
        logEdt->setObjectName(QStringLiteral("logEdt"));

        verticalLayout_2->addWidget(logEdt);


        retranslateUi(OSMNodeTablesUpdateWnd);

        QMetaObject::connectSlotsByName(OSMNodeTablesUpdateWnd);
    } // setupUi

    void retranslateUi(QWidget *OSMNodeTablesUpdateWnd)
    {
        OSMNodeTablesUpdateWnd->setWindowTitle(QApplication::translate("OSMNodeTablesUpdateWnd", "Update OSM Node", Q_NULLPTR));
        label_6->setText(QApplication::translate("OSMNodeTablesUpdateWnd", "Progress", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OSMNodeTablesUpdateWnd: public Ui_OSMNodeTablesUpdateWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSMNODETABLESUPDATEWND_H
