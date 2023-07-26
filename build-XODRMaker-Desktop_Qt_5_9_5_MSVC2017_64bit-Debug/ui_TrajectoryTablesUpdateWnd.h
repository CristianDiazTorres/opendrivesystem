/********************************************************************************
** Form generated from reading UI file 'TrajectoryTablesUpdateWnd.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAJECTORYTABLESUPDATEWND_H
#define UI_TRAJECTORYTABLESUPDATEWND_H

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

class Ui_TrajectoryTablesUpdateWnd
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QProgressBar *progressBar;
    QPlainTextEdit *logEdt;

    void setupUi(QWidget *TrajectoryTablesUpdateWnd)
    {
        if (TrajectoryTablesUpdateWnd->objectName().isEmpty())
            TrajectoryTablesUpdateWnd->setObjectName(QStringLiteral("TrajectoryTablesUpdateWnd"));
        TrajectoryTablesUpdateWnd->resize(650, 560);
        verticalLayout_2 = new QVBoxLayout(TrajectoryTablesUpdateWnd);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(TrajectoryTablesUpdateWnd);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(TrajectoryTablesUpdateWnd);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        progressBar = new QProgressBar(TrajectoryTablesUpdateWnd);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        horizontalLayout_5->addWidget(progressBar);


        verticalLayout_2->addLayout(horizontalLayout_5);

        logEdt = new QPlainTextEdit(TrajectoryTablesUpdateWnd);
        logEdt->setObjectName(QStringLiteral("logEdt"));

        verticalLayout_2->addWidget(logEdt);


        retranslateUi(TrajectoryTablesUpdateWnd);

        QMetaObject::connectSlotsByName(TrajectoryTablesUpdateWnd);
    } // setupUi

    void retranslateUi(QWidget *TrajectoryTablesUpdateWnd)
    {
        TrajectoryTablesUpdateWnd->setWindowTitle(QApplication::translate("TrajectoryTablesUpdateWnd", "Update Trajectory", Q_NULLPTR));
        label->setText(QString());
        label_6->setText(QApplication::translate("TrajectoryTablesUpdateWnd", "Progress", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TrajectoryTablesUpdateWnd: public Ui_TrajectoryTablesUpdateWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAJECTORYTABLESUPDATEWND_H
