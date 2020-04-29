#include "XVideoThread.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <QDebug>
static cv::VideoCapture videoCapture_1;
static bool isExit = false;
XVideoThread* XVideoThread::mInstance = new XVideoThread();
XVideoThread::XVideoThread()
{
	start();
}


double XVideoThread::getPos()
{
	double pos = 0.0;
	mMutex.lock();
	if (videoCapture_1.isOpened())
	{
		const double count = videoCapture_1.get(cv::CAP_PROP_FRAME_COUNT);
		const double curCount = videoCapture_1.get(cv::CAP_PROP_POS_FRAMES);
		if (count>0.001)
		{
			pos = curCount / count;
		}
	}
	mMutex.unlock();
	return pos;
}

XVideoThread::~XVideoThread()
{
	mMutex.lock();
	isExit = false;
	mMutex.unlock();
}

bool XVideoThread::seek(const int& frame)
{
	mMutex.lock();
	if (!videoCapture_1.isOpened())
	{
		mMutex.unlock();
		return false;
	}
	bool re = videoCapture_1.set(cv::CAP_PROP_POS_FRAMES,frame);
	mMutex.unlock();
	return re;
}

bool XVideoThread::seek(const double& pos)
{
	const double count = videoCapture_1.get(cv::CAP_PROP_FRAME_COUNT);
	const int frame = pos*count;
	return seek(frame);
}

bool XVideoThread::open(const QString& fileName)
{
	
	qDebug() << "open file:" << fileName ;
	mMutex.lock();
	bool re = videoCapture_1.open(fileName.toUtf8().data());
	mMutex.unlock();
	qDebug() << re ;
	fps = videoCapture_1.get(cv::CAP_PROP_FPS);
	if (fps<0)
	{
		fps = 25;
	}
	return re;
}

void XVideoThread::run()
{
	cv::Mat mat1;
	while (true)
	{
		mMutex.lock();
		if (isExit)
		{
			mMutex.unlock();
			break;
		}

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
		//msleep(30);
		msleep(1000 / fps);
		mMutex.unlock();
	}
}
