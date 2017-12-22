#include "Canvas.h"
#include <QPainter>
#include <iostream>
#include "CVUtils.h"
//#include "Utils.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
	ctrlPressed = false;
	shiftPressed = false;
}

Canvas::~Canvas() {
}

void Canvas::paintEvent(QPaintEvent *event) {
	if (!orig_image.isNull()) {
		double scale = std::min((double)width() / (orig_image.width() + 100), (double)height() / (orig_image.height() + 100));

		QPainter painter(this);
		painter.drawImage(0, 0, image);

		// draw subdivision lines
		painter.setPen(QPen(QColor(255, 255, 0), 3));
		for (int i = 0; i < y_splits.size(); i++) {
			painter.drawLine(0, y_splits[i] * scale, image.width(), y_splits[i] * scale);
		}
		for (int i = 0; i < x_splits.size(); i++) {
			painter.drawLine(x_splits[i] * scale, 0, x_splits[i] * scale, image.height());
		}

		// draw Ver
		if (Ver.rows > 0) {
			float max_val = cvutils::max(Ver);
			painter.setPen(QColor(0, 0, 0));
			for (int i = 0; i < (int)Ver.rows - 1; i++) {
				painter.drawLine(image.width() + Ver(i, 0) / max_val * 100 * scale, i * scale, image.width() + Ver(i + 1, 0) / max_val * 100 * scale, (i + 1) * scale);
			}
		}

		// draw Hor
		if (Hor.rows > 0) {
			float max_val = cvutils::max(Hor);
			painter.setPen(QColor(0, 0, 0));
			for (int i = 0; i < (int)Hor.rows - 1; i++) {
				painter.drawLine(i * scale, height() - Hor(i, 0) / max_val * 100 * scale, (i + 1) * scale, height() - Hor(i + 1, 0) / max_val * 100 * scale);
			}
		}

	}
}

void Canvas::resizeEvent(QResizeEvent *e) {
	if (!orig_image.isNull()) {
		double scale = std::min((double)width() / (orig_image.width() + 100), (double)height() / (orig_image.height() + 100));
		image = orig_image.scaled(orig_image.width() * scale, orig_image.height() * scale);
	}
}

void Canvas::load(const QString& filename) {
	orig_image = QImage(filename);
	double scale = std::min((double)width() / (orig_image.width() + 100), (double)height() / (orig_image.height() + 100));
	image = orig_image.scaled(orig_image.width() * scale, orig_image.height() * scale);

	y_splits.clear();
	x_splits.clear();
	Ver = cv::Mat_<float>();
	Hor = cv::Mat_<float>();
}

void Canvas::segmentation(int num_floors, int num_columns) {
	cv::Mat facade_img = cv::Mat(orig_image.height(), orig_image.width(), CV_8UC3, orig_image.bits(), orig_image.bytesPerLine()).clone();

	double floor_height = (double)facade_img.rows / num_floors;
	double column_width = (double)facade_img.cols / num_columns;

	fs::subdivideFacade(facade_img, floor_height, column_width, y_splits, x_splits, win_rects, Ver, Hor);
}

void Canvas::keyPressEvent(QKeyEvent* e) {
	ctrlPressed = false;
	shiftPressed = false;

	if (e->modifiers() & Qt::ControlModifier) {
		ctrlPressed = true;
	}
	if (e->modifiers() & Qt::ShiftModifier) {
		shiftPressed = true;
	}

	switch (e->key()) {
	case Qt::Key_Space:
		break;
	}

	update();
}

void Canvas::keyReleaseEvent(QKeyEvent* e) {
	switch (e->key()) {
	case Qt::Key_Control:
		ctrlPressed = false;
		break;
	case Qt::Key_Shift:
		shiftPressed = false;
		break;
	default:
		break;
	}
}

