#pragma once

#include <QtWidgets/QWidget>
#include "ui_xvideoui.h"

class XVideoUI : public QWidget
{
	Q_OBJECT

public:
	XVideoUI(QWidget *parent = Q_NULLPTR);

public slots:
	void open();
	void sliderPressed();
	void sliderSetPos(int);
	void sliderReleased();
protected:
	virtual void timerEvent(QTimerEvent *event);
private:
	Ui::XVideoUIClass ui;
};
