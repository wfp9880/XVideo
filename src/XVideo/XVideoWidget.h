#pragma once
#include <QOpenGLWidget>
#include <opencv2/core.hpp>
#include <QImage>

class XVideoWidget:public QOpenGLWidget
{
	Q_OBJECT

public:
	XVideoWidget(QWidget* parent=Q_NULLPTR);
	virtual ~XVideoWidget();
public slots:
	void setImage(const cv::Mat& mat);
	
protected:
	virtual void paintEvent(QPaintEvent *e) override;
private:
	QImage mImage;
};


