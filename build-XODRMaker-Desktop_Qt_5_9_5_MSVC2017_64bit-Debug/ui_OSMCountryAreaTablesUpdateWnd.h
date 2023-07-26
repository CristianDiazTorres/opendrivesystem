/********************************************************************************
** Form generated from reading UI file 'OSMCountryAreaTablesUpdateWnd.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSMCOUNTRYAREATABLESUPDATEWND_H
#define UI_OSMCOUNTRYAREATABLESUPDATEWND_H

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

class Ui_OSMCountryAreaTablesUpdateWnd
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QProgressBar *progressBar;
    QPlainTextEdit *logEdt;

    void setupUi(QWidget *OSMCountryAreaTablesUpdateWnd)
    {
        if (OSMCountryAreaTablesUpdateWnd->objectName().isEmpty())
            OSMCountryAreaTablesUpdateWnd->setObjectName(QStringLiteral("OSMCountryAreaTablesUpdateWnd"));
        OSMCountryAreaTablesUpdateWnd->resize(731, 607);
        verticalLayout_2 = new QVBoxLayout(OSMCountryAreaTablesUpdateWnd);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(OSMCountryAreaTablesUpdateWnd);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        progressBar = new QProgressBar(OSMCountryAreaTablesUpdateWnd);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        horizontalLayout_5->addWidget(progressBar);


        verticalLayout_2->addLayout(horizontalLayout_5);

        logEdt = new QPlainTextEdit(OSMCountryAreaTablesUpdateWnd);
        logEdt->setObjectName(QStringLiteral("logEdt"));

        verticalLayout_2->addWidget(logEdt);


        retranslateUi(OSMCountryAreaTablesUpdateWnd);

        QMetaObject::connectSlotsByName(OSMCountryAreaTablesUpdateWnd);
    } // setupUi

    void retranslateUi(QWidget *OSMCountryAreaTablesUpdateWnd)
    {
        OSMCountryAreaTablesUpdateWnd->setWindowTitle(QApplication::translate("OSMCountryAreaTablesUpdateWnd", "Update OSM Country Area", Q_NULLPTR));
        label_6->setText(QApplication::translate("OSMCountryAreaTablesUpdateWnd", "Progress", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OSMCountryAreaTablesUpdateWnd: public Ui_OSMCountryAreaTablesUpdateWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSMCOUNTRYAREATABLESUPDATEWND_H
