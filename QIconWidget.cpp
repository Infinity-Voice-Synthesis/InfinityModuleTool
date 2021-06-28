#include "QIconWidget.h"
#include "ui_QIconWidget.h"

QIconWidget::QIconWidget(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::QIconWidget();
	ui->setupUi(this);
}

QIconWidget::~QIconWidget()
{
	delete ui;
}

void QIconWidget::paintEvent(QPaintEvent* event)
{
	if (pix.width() != 0 && pix.height() != 0) {
		QPainter painter(this);

		double scalex = (double)((double)this->width() / (double)pix.width());
		double scaley = (double)((double)this->height() / (double)pix.height());
		double scalet = qMin(scalex, scaley);

		int posx = this->width() / 2 - pix.width() * scalet / 2;
		int posy = this->height() / 2 - pix.height() * scalet / 2;

		painter.drawPixmap(QRect(posx, posy, pix.width() * scalet, pix.height() * scalet), pix);
	}
}

void QIconWidget::resizeEvent(QResizeEvent* event)
{
	repaint();
}

void QIconWidget::setPix(QPixmap pix)
{
	this->pix = pix;
	repaint();
}

QPixmap QIconWidget::getPix()
{
	return this->pix;
}