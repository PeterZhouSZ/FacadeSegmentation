#include "SegmentationDialog.h"

SegmentationDialog::SegmentationDialog(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	ui.lineEditNumFloors->setText("6");
	ui.lineEditNumColumns->setText("6");

	connect(ui.pushButtonOK, SIGNAL(clicked()), this, SLOT(onOK()));
	connect(ui.pushButtonCancel, SIGNAL(clicked()), this, SLOT(onCancel()));
}

SegmentationDialog::~SegmentationDialog() {
}

void SegmentationDialog::onOK() {
	accept();
}

void SegmentationDialog::onCancel() {
	reject();
}
