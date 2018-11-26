/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <draw.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    Draw *Canvas;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_info;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_number;
    QLineEdit *number;
    QLabel *label_style;
    QComboBox *style;
    QPushButton *generate;
    QSpacerItem *verticalSpacer;
    QLabel *label_method;
    QComboBox *method_ch;
    QPushButton *create_ch;
    QPushButton *table;
    QLabel *label;
    QLabel *label_time;
    QSpacerItem *verticalSpacer_2;
    QPushButton *clear;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(904, 677);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Canvas = new Draw(Widget);
        Canvas->setObjectName(QStringLiteral("Canvas"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(Canvas->sizePolicy().hasHeightForWidth());
        Canvas->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(Canvas);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_info = new QLabel(Widget);
        label_info->setObjectName(QStringLiteral("label_info"));

        verticalLayout->addWidget(label_info);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label_number = new QLabel(Widget);
        label_number->setObjectName(QStringLiteral("label_number"));

        verticalLayout->addWidget(label_number);

        number = new QLineEdit(Widget);
        number->setObjectName(QStringLiteral("number"));

        verticalLayout->addWidget(number);

        label_style = new QLabel(Widget);
        label_style->setObjectName(QStringLiteral("label_style"));

        verticalLayout->addWidget(label_style);

        style = new QComboBox(Widget);
        style->setObjectName(QStringLiteral("style"));

        verticalLayout->addWidget(style);

        generate = new QPushButton(Widget);
        generate->setObjectName(QStringLiteral("generate"));

        verticalLayout->addWidget(generate);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_method = new QLabel(Widget);
        label_method->setObjectName(QStringLiteral("label_method"));

        verticalLayout->addWidget(label_method);

        method_ch = new QComboBox(Widget);
        method_ch->setObjectName(QStringLiteral("method_ch"));

        verticalLayout->addWidget(method_ch);

        create_ch = new QPushButton(Widget);
        create_ch->setObjectName(QStringLiteral("create_ch"));

        verticalLayout->addWidget(create_ch);

        table = new QPushButton(Widget);
        table->setObjectName(QStringLiteral("table"));

        verticalLayout->addWidget(table);

        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_time = new QLabel(Widget);
        label_time->setObjectName(QStringLiteral("label_time"));

        verticalLayout->addWidget(label_time);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        clear = new QPushButton(Widget);
        clear->setObjectName(QStringLiteral("clear"));

        verticalLayout->addWidget(clear);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "What to do:", Q_NULLPTR));
        label_info->setText(QApplication::translate("Widget", "Generate points or input points manually.", Q_NULLPTR));
        label_number->setText(QApplication::translate("Widget", "Number of points:", Q_NULLPTR));
        label_style->setText(QApplication::translate("Widget", "Style:", Q_NULLPTR));
        style->clear();
        style->insertItems(0, QStringList()
         << QApplication::translate("Widget", "Random", Q_NULLPTR)
         << QApplication::translate("Widget", "Circle", Q_NULLPTR)
         << QApplication::translate("Widget", "Grid", Q_NULLPTR)
         << QApplication::translate("Widget", "Ellipse", Q_NULLPTR)
         << QApplication::translate("Widget", "Rectangle", Q_NULLPTR)
         << QApplication::translate("Widget", "Square", Q_NULLPTR)
        );
        generate->setText(QApplication::translate("Widget", "Generate Points", Q_NULLPTR));
        label_method->setText(QApplication::translate("Widget", "Method:", Q_NULLPTR));
        method_ch->clear();
        method_ch->insertItems(0, QStringList()
         << QApplication::translate("Widget", "Jarvis Scan", Q_NULLPTR)
         << QApplication::translate("Widget", "QHull", Q_NULLPTR)
         << QApplication::translate("Widget", "Sweep Line", Q_NULLPTR)
        );
        create_ch->setText(QApplication::translate("Widget", "Create CH", Q_NULLPTR));
        table->setText(QApplication::translate("Widget", "Create Table (generate points+create CH)", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "Calculation time:", Q_NULLPTR));
        label_time->setText(QString());
        clear->setText(QApplication::translate("Widget", "Clear", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
