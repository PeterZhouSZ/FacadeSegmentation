/********************************************************************************
** Form generated from reading UI file 'SegmentationDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEGMENTATIONDIALOG_H
#define UI_SEGMENTATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SegmentationDialog
{
public:
    QLabel *label;
    QLineEdit *lineEditNumFloors;
    QLabel *label_2;
    QLineEdit *lineEditNumColumns;
    QPushButton *pushButtonOK;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *SegmentationDialog)
    {
        if (SegmentationDialog->objectName().isEmpty())
            SegmentationDialog->setObjectName(QStringLiteral("SegmentationDialog"));
        SegmentationDialog->resize(211, 111);
        label = new QLabel(SegmentationDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 61, 16));
        lineEditNumFloors = new QLineEdit(SegmentationDialog);
        lineEditNumFloors->setObjectName(QStringLiteral("lineEditNumFloors"));
        lineEditNumFloors->setGeometry(QRect(110, 20, 81, 20));
        label_2 = new QLabel(SegmentationDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 40, 61, 16));
        lineEditNumColumns = new QLineEdit(SegmentationDialog);
        lineEditNumColumns->setObjectName(QStringLiteral("lineEditNumColumns"));
        lineEditNumColumns->setGeometry(QRect(110, 40, 81, 20));
        pushButtonOK = new QPushButton(SegmentationDialog);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));
        pushButtonOK->setGeometry(QRect(10, 70, 91, 31));
        pushButtonCancel = new QPushButton(SegmentationDialog);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(110, 70, 91, 31));

        retranslateUi(SegmentationDialog);

        QMetaObject::connectSlotsByName(SegmentationDialog);
    } // setupUi

    void retranslateUi(QDialog *SegmentationDialog)
    {
        SegmentationDialog->setWindowTitle(QApplication::translate("SegmentationDialog", "SegmentationDialog", 0));
        label->setText(QApplication::translate("SegmentationDialog", "#floors:", 0));
        label_2->setText(QApplication::translate("SegmentationDialog", "#columns:", 0));
        pushButtonOK->setText(QApplication::translate("SegmentationDialog", "OK", 0));
        pushButtonCancel->setText(QApplication::translate("SegmentationDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class SegmentationDialog: public Ui_SegmentationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEGMENTATIONDIALOG_H
