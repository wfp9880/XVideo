#pragma once
#include <QOpenGLWidget>
class XVideoWidget:public QOpenGLWidget
{
public:
	XVideoWidget(QWidget* parent=Q_NULLPTR);
	virtual ~XVideoWidget();
protected:
	virtual void paintEvent(QPaintEvent *e) override;
};


