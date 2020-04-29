#include "XVideoThread.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <QDebug>
static cv::VideoCapture videoCapture_1;

XVideoThread::XVideoThread()
{
	start();
}


XVideoThread::~XVideoThread()
{
}

bool XVideoThread::open(const QString& fileName)
{
	
	qDebug() << "open file:" << fileName ;
	mMutex.lock();
	bool re = videoCapture_1.open(fileName.toUtf8().data());
	mMutex.unlock();
	qDebug() << re ;
	return re;
}

void XVideoThread::run()
{
	cv::Mat mat1;
	while (true)
	{
		mMutex.lock();
		//判断视频是否打开
		if (!videoCapture_1.isOpened())
		{
			mMutex.unlock();
			msleep(5);
			continue;
		}
		//读取一帧视频，解码并且颜色转换
		if (!videoCapture_1.read(mat1)||mat1.empty())
		{
			mMutex.unlock();
			msleep(5);
			continue;
		}
		//显示图像(以信号形式发出)
		emit viewImage_1(mat1);
		
		mMutex.unlock();
		msleep(40);
	}
}
