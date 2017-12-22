#include "Canvas.h"
#include <QPainter>
#include <iostream>
//#include "Utils.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
	ctrlPressed = false;
	shiftPressed = false;
}

Canvas::~Canvas() {
}

void Canvas::paintEvent(QPaintEvent *event) {
	if (!orig_image.isNull()) {
		QPainter painter(this);
		painter.drawImage(0, 0, image);

		painter.setPen(QPen(QColor(255, 255, 0), 3));
		for (int i = 0; i < y_splits.size(); i++) {
			painter.drawLine(0, y_splits[i], image.width(), y_splits[i]);
		}
		for (int i = 0; i < x_splits.size(); i++) {
			painter.drawLine(x_splits[i], 0, x_splits[i], image.height());
		}
	}
}

void Canvas::resizeEvent(QResizeEvent *e) {
	if (!orig_image.isNull()) {
		double scale = std::min((double)width() / orig_image.width(), (double)height() / orig_image.height());
		image = orig_image.scaled(orig_image.width() * scale, orig_image.height() * scale);
	}
}

void Canvas::load(const QString& filename) {
	orig_image = QImage(filename);
	double scale = std::min((double)width() / orig_image.width(), (double)height() / orig_image.height());
	image = orig_image.scaled(orig_image.width() * scale, orig_image.height() * scale);
}

void Canvas::segmentation(int num_floors, int num_columns) {
	cv::Mat facade_img = cv::Mat(orig_image.height(), orig_image.width(), CV_8UC3, orig_image.bits(), orig_image.bytesPerLine()).clone();
	//cv::Mat facade_img = cv::Mat(orig_image.height(), orig_image.width(), QImage::Format_ARGB32, orig_image.bits(), orig_image.bytesPerLine()).clone();
	//cv::cvtColor(facade_img, facade_img, cv::COLOR_BGRA2BGR);

	double floor_height = (double)facade_img.rows / num_floors;
	double column_width = (double)facade_img.cols / num_columns;

	fs::subdivideFacade(facade_img, floor_height, column_width, y_splits, x_splits, win_rects);
}

/*void Canvas::set(const QString& filename, const std::vector<float>& y_splits, const std::vector<float>& x_splits, const std::vector<std::vector<fs::WindowPos>>& win_rects) {
	orig_image = QImage(filename);
	float scale = std::min((float)width() / orig_image.width(), (float)height() / orig_image.height());
	image = orig_image.scaled(orig_image.width() * scale, orig_image.height() * scale);

	this->y_splits = y_splits;
	this->x_splits = x_splits;
	this->win_rects = win_rects;

	update();
}*/

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

