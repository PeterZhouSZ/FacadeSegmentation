#ifndef SEGMENTATIONDIALOG_H
#define SEGMENTATIONDIALOG_H

#include <QDialog>
#include "ui_SegmentationDialog.h"

class SegmentationDialog : public QDialog {
	Q_OBJECT

public:
	Ui::SegmentationDialog ui;

public:
	SegmentationDialog(QWidget *parent = 0);
	~SegmentationDialog();

public slots:
	void onOK();
	void onCancel();
};

#endif // SEGMENTATIONDIALOG_H
