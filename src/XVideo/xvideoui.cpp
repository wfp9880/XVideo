#include "xvideoui.h"
#include <QFileDialog>
#include <QMessageBox>
#include "XVideoThread.h"
#include <opencv2/core.hpp>
XVideoThread* XVideoThread::mInstance = new XVideoThread();
XVideoUI::XVideoUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle(QString("XPlayer"));
	//setWindowFlags(Qt::FramelessWindowHint);
	//connect(ui.openFileButton, SIGNAL(QPushButton::clicked()), this, SLOT(open()));
	qRegisterMetaType<cv::Mat>("cv::Mat");
	QObject::connect(XVideoThread::getInstance(),
		SIGNAL(viewImage_1(const cv::Mat&)),
		ui.srcVideo_1,
		SLOT(setImage(const cv::Mat&)));
}

void XVideoUI::open()
{
	QString fileName=QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("请选择视频文件"));
	if (fileName.isEmpty())
	{
		return;
	}
	//QMessageBox::information(this, "file", fileName);

	if (!XVideoThread::getInstance()->open(fileName))
	{
		QMessageBox::information(this, "", fileName + QString("打开失败").toUtf8().data());
		return;
	}
}


