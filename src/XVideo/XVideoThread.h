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
	int fps = 0;

	static XVideoThread* getInstance()
	{
		if (NULL==mInstance)
		{
			mInstance = new XVideoThread();
		}
		return mInstance;
	}
	//���ص�ǰ���ŵ�λ��
	double getPos();
	virtual ~XVideoThread();
	bool seek(const int& frame);
	bool seek(const double& pos);
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


