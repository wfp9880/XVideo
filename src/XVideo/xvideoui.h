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
private:
	Ui::XVideoUIClass ui;
};
