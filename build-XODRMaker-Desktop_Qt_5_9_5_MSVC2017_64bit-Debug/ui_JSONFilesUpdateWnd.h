/********************************************************************************
** Form generated from reading UI file 'JSONFilesUpdateWnd.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JSONFILESUPDATEWND_H
#define UI_JSONFILESUPDATEWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JSONFilesUpdateWnd
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QTextEdit *dbPathEdt;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *gpsPathEdt;
    QHBoxLayout *horizontalLayout;
    QCheckBox *continueChkBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *countEdt;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *startEdt;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *endEdt;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QProgressBar *progressBar;
    QPlainTextEdit *logEdt;

    void setupUi(QWidget *JSONFilesUpdateWnd)
    {
        if (JSONFilesUpdateWnd->objectName().isEmpty())
            JSONFilesUpdateWnd->setObjectName(QStringLiteral("JSONFilesUpdateWnd"));
        JSONFilesUpdateWnd->resize(650, 560);
        verticalLayout_2 = new QVBoxLayout(JSONFilesUpdateWnd);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_2 = new QLabel(JSONFilesUpdateWnd);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        dbPathEdt = new QTextEdit(JSONFilesUpdateWnd);
        dbPathEdt->setObjectName(QStringLiteral("dbPathEdt"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dbPathEdt->sizePolicy().hasHeightForWidth());
        dbPathEdt->setSizePolicy(sizePolicy);
        dbPathEdt->setMaximumSize(QSize(16777215, 20));
        dbPathEdt->setReadOnly(true);

        verticalLayout_3->addWidget(dbPathEdt);


        verticalLayout_2->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(JSONFilesUpdateWnd);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label);

        gpsPathEdt = new QTextEdit(JSONFilesUpdateWnd);
        gpsPathEdt->setObjectName(QStringLiteral("gpsPathEdt"));
        sizePolicy.setHeightForWidth(gpsPathEdt->sizePolicy().hasHeightForWidth());
        gpsPathEdt->setSizePolicy(sizePolicy);
        gpsPathEdt->setMaximumSize(QSize(16777215, 20));
        gpsPathEdt->setReadOnly(true);

        verticalLayout->addWidget(gpsPathEdt);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        continueChkBox = new QCheckBox(JSONFilesUpdateWnd);
        continueChkBox->setObjectName(QStringLiteral("continueChkBox"));
        continueChkBox->setEnabled(false);
        continueChkBox->setCheckable(true);

        horizontalLayout->addWidget(continueChkBox);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(JSONFilesUpdateWnd);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setMinimumSize(QSize(50, 0));
        label_3->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(label_3);

        countEdt = new QLineEdit(JSONFilesUpdateWnd);
        countEdt->setObjectName(QStringLiteral("countEdt"));
        countEdt->setReadOnly(true);

        horizontalLayout_2->addWidget(countEdt);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(JSONFilesUpdateWnd);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setMinimumSize(QSize(50, 0));
        label_4->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(label_4);

        startEdt = new QLineEdit(JSONFilesUpdateWnd);
        startEdt->setObjectName(QStringLiteral("startEdt"));
        startEdt->setReadOnly(true);

        horizontalLayout_3->addWidget(startEdt);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(JSONFilesUpdateWnd);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setMinimumSize(QSize(50, 0));
        label_5->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_4->addWidget(label_5);

        endEdt = new QLineEdit(JSONFilesUpdateWnd);
        endEdt->setObjectName(QStringLiteral("endEdt"));
        endEdt->setReadOnly(true);

        horizontalLayout_4->addWidget(endEdt);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(JSONFilesUpdateWnd);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        progressBar = new QProgressBar(JSONFilesUpdateWnd);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        horizontalLayout_5->addWidget(progressBar);


        verticalLayout_2->addLayout(horizontalLayout_5);

        logEdt = new QPlainTextEdit(JSONFilesUpdateWnd);
        logEdt->setObjectName(QStringLiteral("logEdt"));

        verticalLayout_2->addWidget(logEdt);


        retranslateUi(JSONFilesUpdateWnd);

        QMetaObject::connectSlotsByName(JSONFilesUpdateWnd);
    } // setupUi

    void retranslateUi(QWidget *JSONFilesUpdateWnd)
    {
        JSONFilesUpdateWnd->setWindowTitle(QApplication::translate("JSONFilesUpdateWnd", "Update JSON", Q_NULLPTR));
        label_2->setText(QApplication::translate("JSONFilesUpdateWnd", "Database Path", Q_NULLPTR));
        label->setText(QApplication::translate("JSONFilesUpdateWnd", "GPS File Path", Q_NULLPTR));
        continueChkBox->setText(QApplication::translate("JSONFilesUpdateWnd", "Continue", Q_NULLPTR));
        label_3->setText(QApplication::translate("JSONFilesUpdateWnd", "Count", Q_NULLPTR));
        label_4->setText(QApplication::translate("JSONFilesUpdateWnd", "Start", Q_NULLPTR));
        label_5->setText(QApplication::translate("JSONFilesUpdateWnd", "End", Q_NULLPTR));
        label_6->setText(QApplication::translate("JSONFilesUpdateWnd", "Progress", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class JSONFilesUpdateWnd: public Ui_JSONFilesUpdateWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JSONFILESUPDATEWND_H