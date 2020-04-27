#pragma once
#include <QThread>
#include <QMutex>
#include <opencv2/core.hpp>
//����Ƶ�ļ��̣߳�һ��ֻ�ܴ�һ����Ƶ������ģʽ��
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

	//������ƵԴ�ļ�
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


