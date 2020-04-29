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
		//�ж���Ƶ�Ƿ��
		if (!videoCapture_1.isOpened())
		{
			mMutex.unlock();
			msleep(5);
			continue;
		}
		//��ȡһ֡��Ƶ�����벢����ɫת��
		if (!videoCapture_1.read(mat1)||mat1.empty())
		{
			mMutex.unlock();
			msleep(5);
			continue;
		}
		//��ʾͼ��(���ź���ʽ����)
		emit viewImage_1(mat1);
		
		mMutex.unlock();
		msleep(40);
	}
}
