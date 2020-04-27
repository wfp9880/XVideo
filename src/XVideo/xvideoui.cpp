#include "xvideoui.h"
#include <QFileDialog>
#include <QMessageBox>
#include "XVideoThread.h"
XVideoThread* XVideoThread::mInstance = new XVideoThread();
XVideoUI::XVideoUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle(QString("XPlayer"));
	//setWindowFlags(Qt::FramelessWindowHint);
	//connect(ui.openFileButton, SIGNAL(QPushButton::clicked()), this, SLOT(open()));
}

void XVideoUI::open()
{
	QString fileName=QFileDialog::getOpenFileName(this, QString("请选择视频文件").toUtf8().data());
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


