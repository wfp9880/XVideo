#include "XVideoWidget.h"
#include <QPainter>
#include <opencv2/imgproc.hpp>

XVideoWidget::XVideoWidget(QWidget* parent/*=Q_NULLPTR*/):QOpenGLWidget(parent)
{
}


XVideoWidget::~XVideoWidget()
{

}

void XVideoWidget::setImage(const cv::Mat& mat)
{
	if (mImage.isNull())
	{
		uchar* buff = new uchar[width()*height() * 3];
		mImage = QImage(buff,width(),height(),QImage::Format_RGB888);
	}
	cv::Mat dest;
	cv::resize(mat, dest, cv::Size(mImage.size().width(), mImage.size().height()));
	cv::cvtColor(dest, dest, cv::COLOR_BGR2RGB);
	memcpy(mImage.bits(), dest.data, dest.cols*dest.rows * dest.elemSize());
	update();
}

void XVideoWidget::paintEvent(QPaintEvent *e)
{
	QPainter p;
	p.begin(this);
	p.drawImage(QPoint(0, 0), mImage);
	p.end();
}
