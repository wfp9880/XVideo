#pragma once
#include <QThread>
#include <QMutex>
#include <opencv2/core.hpp>
//打开视频文件线程，一次只能打开一个视频（单例模式）
class XVideoThread:public QThread
{
	Q_OBJECT

signals:
	void viewImage_1(const cv::Mat& mat);
public:
	static XVideoThread* getInstance()
	{
		if (NULL==mInstance)
		{
			mInstance = new XVideoThread();
		}
		return mInstance;
	}
	
	virtual ~XVideoThread();

	//打开视视频源文件
	bool open(const QString& fileName);
	virtual void run()override;
private:
	
	XVideoThread();
	XVideoThread(const XVideoThread& l)
	{
	}
	static XVideoThread* mInstance;
	QMutex mMutex;
};


