#pragma once

#include <QWidget>
#include <QPixmap>
#include <QPainter>

namespace Ui { class QIconWidget; };

class QIconWidget : public QWidget
{
	Q_OBJECT

public:
	QIconWidget(QWidget *parent = Q_NULLPTR);
	~QIconWidget();
	void setPix(QPixmap pix);
	QPixmap getPix();

private:
	Ui::QIconWidget *ui;
	QPixmap pix;
protected:
	void paintEvent(QPaintEvent* event);
	void resizeEvent(QResizeEvent* event);
};
