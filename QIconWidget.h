#pragma once

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QWidget>
#include <QPixmap>
#include <QPainter>

namespace Ui { class QIconWidget; };

class QIconWidget : public QWidget
{
	Q_OBJECT

public:
	QIconWidget(QWidget* parent = Q_NULLPTR);
	~QIconWidget();
	void setPix(QPixmap pix);
	QPixmap getPix();

private:
	Ui::QIconWidget* ui;
	QPixmap pix;
protected:
	void paintEvent(QPaintEvent* event);
	void resizeEvent(QResizeEvent* event);
};
