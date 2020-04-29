#include "xvideoui.h"
#include <QFileDialog>
#include <QMessageBox>
#include "XVideoThread.h"
#include <opencv2/core.hpp>

static bool pressSlider = false;


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
	QObject::connect(ui.playSlider,
		SIGNAL(sliderPressed()),
		this,
		SLOT(sliderPressed()));
	QObject::connect(ui.playSlider,
		SIGNAL(sliderMoved(int)),
		this,
		SLOT(sliderSetPos(int)));
	QObject::connect(ui.playSlider,
		SIGNAL(sliderReleased()),
		this,
		SLOT(sliderReleased()));
	startTimer(40);
}

void XVideoUI::open()
{
	QString fileName=QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("��ѡ����Ƶ�ļ�"));
	if (fileName.isEmpty())
	{
		return;
	}
	//QMessageBox::information(this, "file", fileName);

	if (!XVideoThread::getInstance()->open(fileName))
	{
		QMessageBox::information(this, "", fileName + QString("��ʧ��").toUtf8().data());
		return;
	}
}

void XVideoUI::sliderPressed()
{
	pressSlider = true;
}

void XVideoUI::sliderSetPos(int pos)
{
	XVideoThread::getInstance()->seek((double)pos/ui.playSlider->maximum());
}

void XVideoUI::sliderReleased()
{
	pressSlider = false;
}

void XVideoUI::timerEvent(QTimerEvent *event)
{
	if (pressSlider)
	{
		return;
	}
	double pos = XVideoThread::getInstance()->getPos();
	ui.playSlider->setValue(pos*ui.playSlider->maximum());
}

