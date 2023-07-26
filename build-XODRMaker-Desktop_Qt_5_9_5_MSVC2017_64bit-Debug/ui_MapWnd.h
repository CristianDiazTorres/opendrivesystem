/********************************************************************************
** Form generated from reading UI file 'MapWnd.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPWND_H
#define UI_MAPWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapWnd
{
public:

    void setupUi(QWidget *MapWnd)
    {
        if (MapWnd->objectName().isEmpty())
            MapWnd->setObjectName(QStringLiteral("MapWnd"));
        MapWnd->resize(400, 300);

        retranslateUi(MapWnd);

        QMetaObject::connectSlotsByName(MapWnd);
    } // setupUi

    void retranslateUi(QWidget *MapWnd)
    {
        MapWnd->setWindowTitle(QApplication::translate("MapWnd", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MapWnd: public Ui_MapWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPWND_H
