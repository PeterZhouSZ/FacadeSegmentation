#include "MainWindow.h"
#include <QFileDialog>
#include "SegmentationDialog.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);

	connect(ui.actionExit, SIGNAL(triggered()), this, SLOT(close()));
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(onOpen()));
	connect(ui.actionSegmentation, SIGNAL(triggered()), this, SLOT(onSegmentation()));

	setCentralWidget(&canvas);
}

MainWindow::~MainWindow() {
}

void MainWindow::onOpen() {
	QString filename = QFileDialog::getOpenFileName(this, tr("Open image file..."), "", tr("Image Files (*.png *.jpg)"));
	if (filename.isEmpty()) return;

	canvas.load(filename);
}

void MainWindow::onSegmentation() {
	SegmentationDialog dlg;

	if (dlg.exec()) {
		int num_floors = dlg.ui.lineEditNumFloors->text().toInt();
		int num_columns = dlg.ui.lineEditNumColumns->text().toInt();

		canvas.segmentation(num_floors, num_columns);
	}
}