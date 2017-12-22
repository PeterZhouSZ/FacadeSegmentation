#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QKeyEvent>
#include <opencv2/opencv.hpp>
#include "FacadeSegmentation.h"
//#include <boost/shared_ptr.hpp>
//#include <vector>

class Canvas : public QWidget {
private:
	QImage image;
	QImage orig_image;
	std::vector<float> y_splits;
	std::vector<float> x_splits;
	std::vector<std::vector<fs::WindowPos>> win_rects;

	bool ctrlPressed;
	bool shiftPressed;
	
public:
	Canvas(QWidget *parent = NULL);
    ~Canvas();
	
protected:
	void paintEvent(QPaintEvent *event);
	void resizeEvent(QResizeEvent *e);

public:
	void load(const QString& filename);
	void segmentation(int num_floors, int num_columns);
	//void set(const QString& filename, const std::vector<float>& y_splits, const std::vector<float>& x_splits, const std::vector<std::vector<fs::WindowPos>>& win_rects);
	void keyPressEvent(QKeyEvent* e);
	void keyReleaseEvent(QKeyEvent* e);
};

#endif // CANVAS_H
