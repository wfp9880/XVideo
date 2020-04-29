/********************************************************************************
** Form generated from reading UI file 'xvideoui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XVIDEOUI_H
#define UI_XVIDEOUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include <xvideowidget.h>

QT_BEGIN_NAMESPACE

class Ui_XVideoUIClass
{
public:
    XVideoWidget *srcVideo_1;
    QPushButton *closeWindowButton;
    QPushButton *openFileButton;
    QSlider *playSlider;

    void setupUi(QWidget *XVideoUIClass)
    {
        if (XVideoUIClass->objectName().isEmpty())
            XVideoUIClass->setObjectName(QStringLiteral("XVideoUIClass"));
        XVideoUIClass->resize(800, 600);
        XVideoUIClass->setStyleSheet(QLatin1String("#XVideoUIClass\n"
"{\n"
"	background-color:rgb(50,50,50);\n"
"	border-color:rgb(50,50,50);\n"
"}\n"
"\n"
""));
        srcVideo_1 = new XVideoWidget(XVideoUIClass);
        srcVideo_1->setObjectName(QStringLiteral("srcVideo_1"));
        srcVideo_1->setGeometry(QRect(10, 40, 600, 400));
        closeWindowButton = new QPushButton(XVideoUIClass);
        closeWindowButton->setObjectName(QStringLiteral("closeWindowButton"));
        closeWindowButton->setGeometry(QRect(730, 0, 75, 23));
        closeWindowButton->setStyleSheet(QString::fromUtf8("font: 11pt \"\347\255\211\347\272\277\";\n"
"color:rgb(255,255,255);\n"
"background-color:rgb(50,50,50)"));
        closeWindowButton->setFlat(true);
        openFileButton = new QPushButton(XVideoUIClass);
        openFileButton->setObjectName(QStringLiteral("openFileButton"));
        openFileButton->setGeometry(QRect(530, 470, 75, 25));
        openFileButton->setStyleSheet(QString::fromUtf8("QPushButton:!hover\n"
"{\n"
"	background-color:rgb(50,50,50);\n"
"    font: 12pt \"\347\255\211\347\272\277\";\n"
"    color:rgb(255,255,255);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgb(0,50,100);\n"
"    font: 12pt \"\347\255\211\347\272\277\";\n"
"    color:rgb(255,255,255);\n"
"}"));
        openFileButton->setFlat(true);
        playSlider = new QSlider(XVideoUIClass);
        playSlider->setObjectName(QStringLiteral("playSlider"));
        playSlider->setGeometry(QRect(10, 420, 601, 22));
        playSlider->setMaximum(1000);
        playSlider->setOrientation(Qt::Horizontal);

        retranslateUi(XVideoUIClass);
        QObject::connect(closeWindowButton, SIGNAL(clicked()), XVideoUIClass, SLOT(close()));
        QObject::connect(openFileButton, SIGNAL(clicked()), XVideoUIClass, SLOT(open()));

        QMetaObject::connectSlotsByName(XVideoUIClass);
    } // setupUi

    void retranslateUi(QWidget *XVideoUIClass)
    {
        XVideoUIClass->setWindowTitle(QApplication::translate("XVideoUIClass", "XVideoUI", Q_NULLPTR));
        closeWindowButton->setText(QApplication::translate("XVideoUIClass", "X", Q_NULLPTR));
        openFileButton->setText(QApplication::translate("XVideoUIClass", "\346\211\223\345\274\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class XVideoUIClass: public Ui_XVideoUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XVIDEOUI_H
