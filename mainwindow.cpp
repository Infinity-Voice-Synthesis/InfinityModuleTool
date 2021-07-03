#include "mainwindow.h"
#include "ui_mainwindow.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	charmenu = new QMenu(ui->charactertable);
	transmenu = new QMenu(ui->translatetable);
	this->getDeve();
	QDir::setCurrent(QDir::homePath());
	QAction* act_char_new = new QAction("添加", this);
	connect(act_char_new, &QAction::triggered, this, &MainWindow::oncn);
	charmenu->addAction(act_char_new);
	QAction* act_char_edit = new QAction("编辑", this);
	connect(act_char_edit, &QAction::triggered, this, &MainWindow::once);
	charmenu->addAction(act_char_edit);
	QAction* act_char_del = new QAction("删除", this);
	connect(act_char_del, &QAction::triggered, this, &MainWindow::oncd);
	charmenu->addAction(act_char_del);
	QAction* act_trans_new = new QAction("添加", this);
	connect(act_trans_new, &QAction::triggered, this, &MainWindow::ontn);
	transmenu->addAction(act_trans_new);
	QAction* act_trans_edit = new QAction("编辑", this);
	connect(act_trans_edit, &QAction::triggered, this, &MainWindow::onte);
	transmenu->addAction(act_trans_edit);
	QAction* act_trans_del = new QAction("删除", this);
	connect(act_trans_del, &QAction::triggered, this, &MainWindow::ontd);
	transmenu->addAction(act_trans_del);

	ui->enginewarrantdate->setMinimumDate(QDate::currentDate().addDays(1));
	ui->librarywarrantdate->setMinimumDate(QDate::currentDate().addDays(1));
	ui->enginewarrantdate->setSelectedDate(QDate::currentDate().addDays(1));
	ui->librarywarrantdate->setSelectedDate(QDate::currentDate().addDays(1));
	ui->enginewarranttime->setTime(QTime::fromString("00:00:00", "hh:mm:ss"));
	ui->librarywarranttime->setTime(QTime::fromString("00:00:00", "hh:mm:ss"));
}

MainWindow::~MainWindow()
{
	delete charmenu;
	delete transmenu;
	delete ui;
}

void MainWindow::getDeve()
{
	QFile file(":/other/developer.json");
	if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		QJsonDocument jd = QJsonDocument::fromJson(file.readAll());
		file.close();
		if (jd.isArray()) {
			developer = jd.array();
		}
	}
}

void MainWindow::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	QPalette pal = this->palette();
	QBrush brush = pal.window();
	QColor col = brush.color();
	QPen pen;
	pen.setStyle(Qt::SolidLine);
	pen.setCapStyle(Qt::RoundCap);
	pen.setJoinStyle(Qt::RoundJoin);
	pen.setColor(QColor(col.red() + 2, col.green() + 2, col.blue() + 2));
	painter.setPen(pen);
	QFont font;
	font.setPixelSize(height() / 50);
	painter.setFont(font);
	QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	for (int i = 0; i < 50; i++) {
		if (i % 2) {
			painter.drawText(QPointF(0.05 * width(), i * (double)((double)height() / (double)50)), "name:" + Developername);
		}
		else {
			painter.drawText(QPointF(0.05 * width(), i * (double)((double)height() / (double)50)), "time:" + times);
		}
	}
	for (int i = 0; i < 50; i++) {
		if (i % 2) {
			painter.drawText(QPointF(0.55 * width(), i * (double)((double)height() / (double)50)), "name:" + Developername);
		}
		else {
			painter.drawText(QPointF(0.55 * width(), i * (double)((double)height() / (double)50)), "time:" + times);
		}
	}
	QWidget::paintEvent(event);
}

void MainWindow::devetrue()
{
	ui->actionSign->setEnabled(true);
	ui->actionDeveloper->setEnabled(false);
}
void MainWindow::on_actionDeveloper_triggered()
{
	DeveloperDialog dd(this);
	dd.setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
	dd.setlist(this->developer);
	dd.exec();
	if (!dd.result().isEmpty()) {
		this->Developername = dd.result();
		repaint();
		this->devetrue();
	}
	else {
		this->Developername = "No Developer Name";
		repaint();
	}
}

void MainWindow::on_charactertable_customContextMenuRequested(const QPoint& pos)
{
	Q_UNUSED(pos);
	if (ui->charactertable->currentRow() == -1) {
		this->charmenu->actions().at(0)->setEnabled(true);
		this->charmenu->actions().at(1)->setEnabled(false);
		this->charmenu->actions().at(2)->setEnabled(false);
	}
	else {
		this->charmenu->actions().at(0)->setEnabled(true);
		this->charmenu->actions().at(1)->setEnabled(true);
		this->charmenu->actions().at(2)->setEnabled(true);
	}
	this->charmenu->exec(QCursor::pos());
}

void MainWindow::on_translatetable_customContextMenuRequested(const QPoint& pos)
{
	Q_UNUSED(pos);
	if (ui->translatetable->currentRow() == -1) {
		this->transmenu->actions().at(0)->setEnabled(true);
		this->transmenu->actions().at(1)->setEnabled(false);
		this->transmenu->actions().at(2)->setEnabled(false);
	}
	else {
		this->transmenu->actions().at(0)->setEnabled(true);
		this->transmenu->actions().at(1)->setEnabled(true);
		this->transmenu->actions().at(2)->setEnabled(true);
	}
	this->transmenu->exec(QCursor::pos());
}

void MainWindow::oncn()
{
	CharEditDialog ced(this);
	ced.setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
	ced.exec();
	if (!ced.name.isEmpty()) {
		bool ok = true;
		for (int i = 0; i < ui->charactertable->rowCount(); i++) {
			if (ui->charactertable->item(i, 0)->text() == ced.name) {
				ok = false;
				break;
			}
		}
		if (ok) {
			ui->charactertable->insertRow(0);
			this->setcharrow(0, ced.name, ced.CP, ced.PP, ced.VSP, ced.VEP);
		}
		else {
			QMessageBox::warning(this, "出错", "重复的项目！");
		}
	}
}

void MainWindow::once()
{
	CharEditDialog ced(this);
	ced.setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
	ced.setchar(
		ui->charactertable->item(ui->charactertable->currentRow(), 0)->text(),
		ui->charactertable->item(ui->charactertable->currentRow(), 1)->text().toDouble(),
		ui->charactertable->item(ui->charactertable->currentRow(), 2)->text().toDouble(),
		ui->charactertable->item(ui->charactertable->currentRow(), 3)->text().toDouble(),
		ui->charactertable->item(ui->charactertable->currentRow(), 4)->text().toDouble()
	);
	ced.exec();
	if (!ced.name.isEmpty()) {
		bool ok = true;
		for (int i = 0; i < ui->charactertable->rowCount(); i++) {
			if (ui->charactertable->item(i, 0)->text() == ced.name) {
				if (i != ui->charactertable->currentRow()) {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			this->setcharrow(ui->charactertable->currentRow(), ced.name, ced.CP, ced.PP, ced.VSP, ced.VEP);
		}
		else {
			QMessageBox::warning(this, "出错", "重复的项目！");
		}
	}
}

void MainWindow::oncd()
{
	ui->charactertable->removeRow(ui->charactertable->currentRow());
}

void MainWindow::ontn()
{
	TransEditDialog ted(this);
	ted.setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
	ted.exec();
	if (!ted.name.isEmpty() && !ted.phoneme.isEmpty()) {
		bool ok = true;
		for (int i = 0; i < ui->translatetable->rowCount(); i++) {
			if (ui->translatetable->item(i, 0)->text() == ted.name) {
				ok = false;
				break;
			}
		}
		if (ok) {
			ui->translatetable->insertRow(0);
			this->settransrow(0, ted.name, ted.phoneme);
		}
		else {
			QMessageBox::warning(this, "出错", "重复的项目！");
		}
	}
}

void MainWindow::onte()
{
	TransEditDialog ted(this);
	ted.setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
	ted.settrans(
		ui->translatetable->item(ui->translatetable->currentRow(), 0)->text(),
		ui->translatetable->item(ui->translatetable->currentRow(), 1)->text()
	);
	ted.exec();
	if (!ted.name.isEmpty() && !ted.phoneme.isEmpty()) {
		bool ok = true;
		for (int i = 0; i < ui->translatetable->rowCount(); i++) {
			if (ui->translatetable->item(i, 0)->text() == ted.name) {
				if (i != ui->translatetable->currentRow()) {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			this->settransrow(ui->translatetable->currentRow(), ted.name, ted.phoneme);
		}
		else {
			QMessageBox::warning(this, "出错", "重复的项目！");
		}
	}
}

void MainWindow::ontd()
{
	ui->translatetable->removeRow(ui->translatetable->currentRow());
}

void MainWindow::setcharrow(int row, QString name, double CP, double PP, double VSP, double VEP)
{
	QTableWidgetItem* item;

	item = new QTableWidgetItem(name);
	ui->charactertable->setItem(row, 0, item);

	item = new QTableWidgetItem(QString::number(CP));
	ui->charactertable->setItem(row, 1, item);

	item = new QTableWidgetItem(QString::number(PP));
	ui->charactertable->setItem(row, 2, item);

	item = new QTableWidgetItem(QString::number(VSP));
	ui->charactertable->setItem(row, 3, item);

	item = new QTableWidgetItem(QString::number(VEP));
	ui->charactertable->setItem(row, 4, item);
}

void MainWindow::settransrow(int row, QString name, QString phoneme)
{
	QTableWidgetItem* item;

	item = new QTableWidgetItem(name);
	ui->translatetable->setItem(row, 0, item);

	item = new QTableWidgetItem(phoneme);
	ui->translatetable->setItem(row, 1, item);
}

void MainWindow::setllrow(int row, QString pitch, QString sdb)
{
	QTableWidgetItem* item;

	item = new QTableWidgetItem(pitch);
	ui->lsdlink->setItem(row, 0, item);

	item = new QTableWidgetItem(sdb);
	ui->lsdlink->setItem(row, 1, item);
}

void MainWindow::setewprow(int row, QString name, double max, double min, double def)
{
	QTableWidgetItem* item;

	item = new QTableWidgetItem(name);
	ui->ewplist->setItem(row, 0, item);

	item = new QTableWidgetItem(QString::number(max));
	ui->ewplist->setItem(row, 1, item);

	item = new QTableWidgetItem(QString::number(min));
	ui->ewplist->setItem(row, 2, item);

	item = new QTableWidgetItem(QString::number(def));
	ui->ewplist->setItem(row, 3, item);
}

void MainWindow::setenprow(int row, QString name, double max, double min, double def)
{
	QTableWidgetItem* item;

	item = new QTableWidgetItem(name);
	ui->enplist->setItem(row, 0, item);

	item = new QTableWidgetItem(QString::number(max));
	ui->enplist->setItem(row, 1, item);

	item = new QTableWidgetItem(QString::number(min));
	ui->enplist->setItem(row, 2, item);

	item = new QTableWidgetItem(QString::number(def));
	ui->enplist->setItem(row, 3, item);
}


void MainWindow::on_actionNew_dic_triggered()
{
	QString name = QInputDialog::getText(this, "新字典", "输入字典名称", QLineEdit::Normal, "", nullptr, Qt::Dialog | Qt::WindowCloseButtonHint);
	ui->dicname->setText(name);
	while (ui->charactertable->rowCount() > 0) {
		ui->charactertable->removeRow(0);
	}
	while (ui->translatetable->rowCount() > 0) {
		ui->translatetable->removeRow(0);
	}
	ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::on_actionOpen_dic_triggered()
{
	QString filen = QFileDialog::getExistingDirectory(this, "读取字典", QDir::currentPath());
	if (!filen.isEmpty()) {
		QDir::setCurrent(filen);
		QFile file(filen + "/dictionary.json");
		if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QJsonDocument jd = QJsonDocument::fromJson(file.readAll());
			file.close();
			if (jd.isObject()) {
				QJsonObject jo = jd.object();

				if (jo.find("version")->toDouble() <= ::_IMT_Version) {
					ui->dicname->setText(jo.find("name")->toString());

					QFile filec(filen + "/character.raw");
					QFile filet(filen + "/translate.raw");

					if (filec.open(QIODevice::ReadOnly | QIODevice::Text)) {
						QString cdata = filec.readAll();
						filec.close();

						QStringList clist = cdata.split("\n", QString::SkipEmptyParts);

						while (ui->charactertable->rowCount() > 0) {
							ui->charactertable->removeRow(0);
						}

						for (int i = 0; i < clist.size(); i++) {
							QString sdata = clist.at(i);
							QStringList slist = sdata.split(" ", QString::SkipEmptyParts);
							if (slist.size() == 5) {
								ui->charactertable->insertRow(0);
								this->setcharrow(0,
									slist.at(0),
									slist.at(1).toDouble(),
									slist.at(2).toDouble(),
									slist.at(3).toDouble(),
									slist.at(4).toDouble());

							}
						}
					}
					else {
						QMessageBox::warning(this, "出错", "无法打开文件：" + filen + "/charater.raw");
					}

					if (filet.open(QIODevice::ReadOnly | QIODevice::Text)) {
						QString tdata = filet.readAll();
						filet.close();

						QStringList tlist = tdata.split("\n", QString::SkipEmptyParts);

						while (ui->translatetable->rowCount() > 0) {
							ui->translatetable->removeRow(0);
						}

						for (int i = 0; i < tlist.size(); i++) {
							QString sdata = tlist.at(i);
							QStringList slist = sdata.split(" ", QString::SkipEmptyParts);
							if (slist.size() == 2) {
								ui->translatetable->insertRow(0);
								this->settransrow(0,
									slist.at(0),
									slist.at(1));

							}
						}
					}
					else {
						QMessageBox::warning(this, "出错", "无法打开文件：" + filen + "/translate.raw");
					}


				}
				else {
					QMessageBox::warning(this, "出错", "不支持的文件版本：" + filen + "/dictionary.json");
				}

			}
			else {
				QMessageBox::warning(this, "出错", "文件格式损坏：" + filen + "/dictionary.json");
			}
		}
		else {
			QMessageBox::warning(this, "出错", "无法打开文件：" + filen + "/dictionary.json");
		}
	}
	ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::on_actionSave_dic_triggered()
{
	if (!ui->dicname->text().isEmpty()) {
		QString filen = QFileDialog::getExistingDirectory(this, "保存字典", QDir::currentPath() + "/" + ui->dicname->text());
		if (!filen.isEmpty()) {
			QDir::setCurrent(filen);

			QJsonObject jo;
			jo.insert("name", ui->dicname->text());
			jo.insert("version", ::_IMT_Version);

			QJsonDocument jd;
			jd.setObject(jo);

			QByteArray data = jd.toJson(QJsonDocument::Indented);
			QFile file(filen + "/dictionary.json");
			if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
				file.write(data);
				file.close();
			}
			else {
				QMessageBox::warning(this, "出错", "无法打开文件：" + filen + "/dictionary.json");
			}

			QString datac, datat;
			QStringList datacl, datatl;

			for (int i = 0; i < ui->charactertable->rowCount(); i++) {
				if (!datacl.contains(ui->charactertable->item(i, 0)->text())) {
					datacl.append(ui->charactertable->item(i, 0)->text());
					datac += ui->charactertable->item(i, 0)->text();
					datac += " ";
					datac += ui->charactertable->item(i, 1)->text();
					datac += " ";
					datac += ui->charactertable->item(i, 2)->text();
					datac += " ";
					datac += ui->charactertable->item(i, 3)->text();
					datac += " ";
					datac += ui->charactertable->item(i, 4)->text();
					datac += "\n";
				}
			}
			for (int i = 0; i < ui->translatetable->rowCount(); i++) {
				if (!datatl.contains(ui->translatetable->item(i, 0)->text())) {
					datatl.append(ui->translatetable->item(i, 0)->text());
					datat += ui->translatetable->item(i, 0)->text();
					datat += " ";
					datat += ui->translatetable->item(i, 1)->text();
					datat += "\n";
				}
			}
			QFile filec(filen + "/character.raw");
			if (filec.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
				filec.write(datac.toUtf8());
				filec.close();
			}
			else {
				QMessageBox::warning(this, "出错", "无法打开文件：" + filen + "/character.raw");
			}
			QFile filet(filen + "/translate.raw");
			if (filet.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
				filet.write(datat.toUtf8());
				filet.close();
				QMessageBox::information(this, "保存", "已保存字典：" + filen);
			}
			else {
				QMessageBox::warning(this, "出错", "无法打开文件：" + filen + "/translate.raw");
			}
		}
	}
	else {
		QMessageBox::warning(this, "出错", "未设置字典名称");
	}
	ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::on_actionFrom_cedict_triggered()
{
	QString filen = QFileDialog::getOpenFileName(this, "读取cedict字典", QDir::currentPath(), "cedict字典(*.txt);;所有文件(*)");
	if (!filen.isEmpty()) {
		QFileInfo filei(filen);
		QDir::setCurrent(filei.absolutePath());

		QFile file(filen);
		if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QString data = file.readAll();
			file.close();

			QMap<QString, QString> trans = getTransFromCedict(data);
			QStringList charl = getCharListfromTrans(trans);

			while (ui->charactertable->rowCount() > 0) {
				ui->charactertable->removeRow(0);
			}
			while (ui->translatetable->rowCount() > 0) {
				ui->translatetable->removeRow(0);
			}

			for (int i = 0; i < charl.size(); i++) {
				ui->charactertable->insertRow(0);
				this->setcharrow(0, charl.at(i));
			}
			for (int i = 0; i < trans.size(); i++) {
				ui->translatetable->insertRow(0);
				this->settransrow(0, trans.keys().at(i), trans.values().at(i));
			}

		}
		else {
			QMessageBox::warning(this, "出错", "无法打开文件：" + filen);
		}
	}
	ui->tabWidget->setCurrentIndex(2);
}

QMap<QString, QString> MainWindow::getTransFromCedict(QString data)
{
	QMap<QString, QString> out;
	QStringList lines = data.split("\n", QString::SkipEmptyParts);
	int _line_count = 0;
	while (_line_count < lines.size()) {
		if (lines.at(_line_count).isEmpty()) {
			lines.removeAt(_line_count);
			continue;
		}
		if (lines.at(_line_count).at(0) == '#') {
			lines.removeAt(_line_count);
			continue;
		}
		_line_count++;
	}
	for (int i = 0; i < lines.size(); i++) {
		QString subs = lines.at(i);
		QStringList subsl = subs.split(" ", QString::SkipEmptyParts);
		if (subsl.size() == 3) {
			if (subsl.at(0).size() == 1 && subsl.at(1).size() == 1) {
				QString subs3 = subsl.at(2);
				if (subs3.size() >= 4) {
					subs3.remove(0, 1);
					subs3.remove(subs3.size() - 1, 1);
					if (subs3.split(" ", QString::SkipEmptyParts).size() == 1) {
						subs3.remove(subs3.size() - 1, 1);
						out.insert(subsl.at(0), subs3);
						out.insert(subsl.at(1), subs3);
					}
				}
			}
		}
	}
	return out;
}

QStringList MainWindow::getCharListfromTrans(QMap<QString, QString> trans)
{
	QStringList out;
	for (int i = 0; i < trans.size(); i++) {
		if (!out.contains(trans.values().at(i))) {
			out.append(trans.values().at(i));
		}
	}
	return out;
}

void MainWindow::on_actionAutoC_triggered()
{
	QString cdata = QInputDialog::getText(this, "输入辅音", "用空格分隔辅音");
	QStringList cdatalist = cdata.split(" ", QString::SkipEmptyParts);
	for (int j = 0; j < ui->charactertable->rowCount(); j++) {
		ui->charactertable->item(j, 1)->setText(ui->charactertable->item(j, 2)->text());
		for (int i = 0; i < cdatalist.size(); i++) {
			if (ui->charactertable->item(j, 0)->text().startsWith(cdatalist.at(i))) {
				qDebug() << cdatalist.at(i) << ":" << ui->charactertable->item(j, 0)->text();
				if (ui->charactertable->item(j, 2)->text().toDouble() > -0.3) {
					ui->charactertable->item(j, 1)->setText("0.3");
				}
				else {
					ui->charactertable->item(j, 1)->setText(QString::number(-ui->charactertable->item(j, 2)->text().toDouble() + 0.3));
				}
				break;
			}
		}
	}
	ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::on_loadenginemain_clicked()
{
	QString name = QFileDialog::getOpenFileName(this, "选择引擎主模块", QDir::currentPath(), "Infinity合成引擎(*.dll)");
	if (!name.isEmpty()) {
		QFileInfo filei(name);
		QDir::setCurrent(filei.absolutePath());
		ui->enginemain->setText(filei.fileName());
	}
}

void MainWindow::on_openengineicon_clicked()
{
	QString name = QFileDialog::getOpenFileName(this, "选择引擎图标", QDir::currentPath(), "图像文件(*.jpg *.jpeg *.png *.bmp)");
	if (!name.isEmpty()) {
		QFileInfo filei(name);
		QDir::setCurrent(filei.absolutePath());
		ui->engineiconname->setText(name);
		QPixmap pix(name);
		ui->engineicon->setPix(pix);
	}
}

void MainWindow::on_ewplist_currentItemChanged(QTableWidgetItem* item1, QTableWidgetItem* item2)
{
	Q_UNUSED(item1);
	Q_UNUSED(item2);
	int index = ui->ewplist->currentRow();
	if (index >= 0 && index < ui->ewplist->rowCount()) {
		ui->ewpadd->setEnabled(true);
		ui->ewpedit->setEnabled(true);
		ui->ewpdel->setEnabled(true);
		if (index > 0) {
			ui->ewpup->setEnabled(true);
		}
		else {
			ui->ewpup->setEnabled(false);
		}
		if (index < ui->ewplist->rowCount() - 1) {
			ui->ewpdown->setEnabled(true);
		}
		else {
			ui->ewpdown->setEnabled(false);
		}
	}
	else {
		ui->ewpadd->setEnabled(true);
		ui->ewpedit->setEnabled(false);
		ui->ewpdel->setEnabled(false);
		ui->ewpup->setEnabled(false);
		ui->ewpdown->setEnabled(false);
	}
}

void MainWindow::on_ewpadd_clicked()
{
	ParamDialog pd(this);
	pd.setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
	pd.exec();
	if (!pd.name.isEmpty()) {
		bool ok = true;
		for (int i = 0; i < ui->ewplist->rowCount(); i++) {
			if (ui->ewplist->item(i, 0)->text() == pd.name) {
				ok = false;
				break;
			}
		}
		if (ok) {
			ui->ewplist->insertRow(0);
			this->setewprow(0, pd.name, pd.max, pd.min, pd.def);
		}
		else {
			QMessageBox::warning(this, "出错", "参数已存在");
		}
	}
}

void MainWindow::on_ewpedit_clicked()
{
	int index = ui->ewplist->currentRow();
	ParamDialog pd(this);
	pd.setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
	pd.setparam(
		ui->ewplist->item(index, 0)->text(),
		ui->ewplist->item(index, 1)->text().toDouble(),
		ui->ewplist->item(index, 2)->text().toDouble(),
		ui->ewplist->item(index, 3)->text().toDouble()
	);
	pd.exec();
	if (!pd.name.isEmpty()) {
		bool ok = true;
		for (int i = 0; i < ui->ewplist->rowCount(); i++) {
			if (i != index) {
				if (ui->ewplist->item(i, 0)->text() == pd.name) {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			this->setewprow(index, pd.name, pd.max, pd.min, pd.def);
		}
		else {
			QMessageBox::warning(this, "出错", "参数已存在");
		}
	}
}

void MainWindow::on_ewpdel_clicked()
{
	int index = ui->ewplist->currentRow();
	ui->ewplist->removeRow(index);
}

void MainWindow::on_ewpup_clicked()
{
	int index = ui->ewplist->currentRow();
	QString namet = ui->ewplist->item(index - 1, 0)->text();
	double maxt = ui->ewplist->item(index - 1, 1)->text().toDouble();
	double mint = ui->ewplist->item(index - 1, 2)->text().toDouble();
	double deft = ui->ewplist->item(index - 1, 3)->text().toDouble();
	this->setewprow(
		index - 1,
		ui->ewplist->item(index, 0)->text(),
		ui->ewplist->item(index, 1)->text().toDouble(),
		ui->ewplist->item(index, 2)->text().toDouble(),
		ui->ewplist->item(index, 3)->text().toDouble()
	);
	this->setewprow(index, namet, maxt, mint, deft);
	ui->ewplist->setCurrentCell(index - 1, 0);
}

void MainWindow::on_ewpdown_clicked()
{
	int index = ui->ewplist->currentRow();
	QString namet = ui->ewplist->item(index + 1, 0)->text();
	double maxt = ui->ewplist->item(index + 1, 1)->text().toDouble();
	double mint = ui->ewplist->item(index + 1, 2)->text().toDouble();
	double deft = ui->ewplist->item(index + 1, 3)->text().toDouble();
	this->setewprow(
		index + 1,
		ui->ewplist->item(index, 0)->text(),
		ui->ewplist->item(index, 1)->text().toDouble(),
		ui->ewplist->item(index, 2)->text().toDouble(),
		ui->ewplist->item(index, 3)->text().toDouble()
	);
	this->setewprow(index, namet, maxt, mint, deft);
	ui->ewplist->setCurrentCell(index + 1, 0);
}

void MainWindow::on_enplist_currentItemChanged(QTableWidgetItem* item1, QTableWidgetItem* item2)
{
	Q_UNUSED(item1);
	Q_UNUSED(item2);
	int index = ui->enplist->currentRow();
	if (index >= 0 && index < ui->enplist->rowCount()) {
		ui->enpadd->setEnabled(true);
		ui->enpedit->setEnabled(true);
		ui->enpdel->setEnabled(true);
		if (index > 0) {
			ui->enpup->setEnabled(true);
		}
		else {
			ui->enpup->setEnabled(false);
		}
		if (index < ui->enplist->rowCount() - 1) {
			ui->enpdown->setEnabled(true);
		}
		else {
			ui->enpdown->setEnabled(false);
		}
	}
	else {
		ui->enpadd->setEnabled(true);
		ui->enpedit->setEnabled(false);
		ui->enpdel->setEnabled(false);
		ui->enpup->setEnabled(false);
		ui->enpdown->setEnabled(false);
	}
}

void MainWindow::on_enpadd_clicked()
{
	ParamDialog pd(this);
	pd.setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
	pd.exec();
	if (!pd.name.isEmpty()) {
		bool ok = true;
		for (int i = 0; i < ui->enplist->rowCount(); i++) {
			if (ui->enplist->item(i, 0)->text() == pd.name) {
				ok = false;
				break;
			}
		}
		if (ok) {
			ui->enplist->insertRow(0);
			this->setenprow(0, pd.name, pd.max, pd.min, pd.def);
		}
		else {
			QMessageBox::warning(this, "出错", "参数已存在");
		}
	}
}

void MainWindow::on_enpedit_clicked()
{
	int index = ui->enplist->currentRow();
	ParamDialog pd(this);
	pd.setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
	pd.setparam(
		ui->enplist->item(index, 0)->text(),
		ui->enplist->item(index, 1)->text().toDouble(),
		ui->enplist->item(index, 2)->text().toDouble(),
		ui->enplist->item(index, 3)->text().toDouble()
	);
	pd.exec();
	if (!pd.name.isEmpty()) {
		bool ok = true;
		for (int i = 0; i < ui->enplist->rowCount(); i++) {
			if (i != index) {
				if (ui->enplist->item(i, 0)->text() == pd.name) {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			this->setenprow(index, pd.name, pd.max, pd.min, pd.def);
		}
		else {
			QMessageBox::warning(this, "出错", "参数已存在");
		}
	}
}

void MainWindow::on_enpdel_clicked()
{
	int index = ui->enplist->currentRow();
	ui->enplist->removeRow(index);
}

void MainWindow::on_enpup_clicked()
{
	int index = ui->enplist->currentRow();
	QString namet = ui->enplist->item(index - 1, 0)->text();
	double maxt = ui->enplist->item(index - 1, 1)->text().toDouble();
	double mint = ui->enplist->item(index - 1, 2)->text().toDouble();
	double deft = ui->enplist->item(index - 1, 3)->text().toDouble();
	this->setenprow(
		index - 1,
		ui->enplist->item(index, 0)->text(),
		ui->enplist->item(index, 1)->text().toDouble(),
		ui->enplist->item(index, 2)->text().toDouble(),
		ui->enplist->item(index, 3)->text().toDouble()
	);
	this->setenprow(index, namet, maxt, mint, deft);
	ui->enplist->setCurrentCell(index - 1, 0);
}

void MainWindow::on_enpdown_clicked()
{
	int index = ui->enplist->currentRow();
	QString namet = ui->enplist->item(index + 1, 0)->text();
	double maxt = ui->enplist->item(index + 1, 1)->text().toDouble();
	double mint = ui->enplist->item(index + 1, 2)->text().toDouble();
	double deft = ui->enplist->item(index + 1, 3)->text().toDouble();
	this->setenprow(
		index + 1,
		ui->enplist->item(index, 0)->text(),
		ui->enplist->item(index, 1)->text().toDouble(),
		ui->enplist->item(index, 2)->text().toDouble(),
		ui->enplist->item(index, 3)->text().toDouble()
	);
	this->setenprow(index, namet, maxt, mint, deft);
	ui->enplist->setCurrentCell(index + 1, 0);
}

void MainWindow::on_actionNew_triggered()
{
	ui->enginename->clear();
	ui->enginemain->clear();
	ui->engineiconname->clear();
	ui->engineicon->setPix(QPixmap());
	ui->engineauthor->clear();
	ui->engineversion->setValue(0.1);
	ui->engineinfor->clear();
	while (ui->ewplist->rowCount() > 0) {
		ui->ewplist->removeRow(0);
	}
	while (ui->enplist->rowCount() > 0) {
		ui->enplist->removeRow(0);
	}
	ui->enginecheckmethod->setCurrentIndex(0);
	ui->engineautocheck->setChecked(true);
	ui->engineeula->clear();
	ui->enginewarrantdate->setSelectedDate(QDate::currentDate().addDays(1));
	ui->enginewarranttime->setTime(QTime::fromString("00:00:00", "hh:mm:ss"));
	ui->tabWidget->setCurrentIndex(0);
	ui->toolBox->setCurrentIndex(0);
}

void MainWindow::on_actionOpen_triggered()
{
	QString filen = QFileDialog::getOpenFileName(this, "读取引擎信息表", QDir::currentPath(), "Infinity引擎信息表(*.ifteinfor)");
	if (!filen.isEmpty()) {
		QFileInfo filei(filen);
		QDir::setCurrent(filei.absolutePath());

		QFile file(filen);
		if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QJsonDocument jd = QJsonDocument::fromJson(file.readAll());
			file.close();
			if (jd.isObject()) {
				QJsonObject jo = jd.object();

				if (jo.find("IMT_Version")->toDouble() <= ::_IMT_Version) {
					ui->enginename->setText(jo.find("name")->toString());
					ui->enginemain->setText(jo.find("main")->toString());
					ui->engineiconname->setText("From information form");
					QPixmap pix;
					pix.loadFromData(QByteArray::fromBase64(jo.find("icon")->toString().toLocal8Bit()));
					ui->engineicon->setPix(pix);
					ui->engineauthor->setText(jo.find("author")->toString());
					ui->engineversion->setValue(jo.find("version")->toDouble());
					ui->engineinfor->setPlainText(jo.find("infor")->toString());

					QJsonArray ewpa = jo.find("ewp")->toArray();
					QJsonArray enpa = jo.find("enp")->toArray();

					while (ui->ewplist->rowCount() > 0) {
						ui->ewplist->removeRow(0);
					}
					while (ui->enplist->rowCount() > 0) {
						ui->enplist->removeRow(0);
					}

					for (int i = 0; i < ewpa.size(); i++) {
						QJsonObject sjo = ewpa.at(i).toObject();
						int index = ui->ewplist->rowCount();
						ui->ewplist->insertRow(index);
						this->setewprow(
							index,
							sjo.find("name")->toString(),
							sjo.find("max")->toDouble(),
							sjo.find("min")->toDouble(),
							sjo.find("default")->toDouble()
						);
					}

					for (int i = 0; i < enpa.size(); i++) {
						QJsonObject sjo = enpa.at(i).toObject();
						int index = ui->enplist->rowCount();
						ui->enplist->insertRow(index);
						this->setenprow(
							index,
							sjo.find("name")->toString(),
							sjo.find("max")->toDouble(),
							sjo.find("min")->toDouble(),
							sjo.find("default")->toDouble()
						);
					}

					ui->enginecheckmethod->setCurrentIndex(jo.find("checkmethod")->toInt());
					ui->engineautocheck->setChecked(jo.find("autocheck")->toBool());
					ui->engineeula->setPlainText(jo.find("eula")->toString());
					ui->enginewarrantdate->setSelectedDate(QDate::fromString(jo.find("warrantdate")->toString(), "yyyy-MM-dd"));
					ui->enginewarranttime->setTime(QTime::fromString(jo.find("warranttime")->toString(), "hh:mm:ss"));
				}
				else {
					QMessageBox::warning(this, "出错", "不支持的文件版本：" + filen);
				}
			}
			else {
				QMessageBox::warning(this, "出错", "文件格式损坏：" + filen);
			}
		}
		else {
			QMessageBox::warning(this, "出错", "无法打开文件：" + filen);
		}
	}
	ui->tabWidget->setCurrentIndex(0);
	ui->toolBox->setCurrentIndex(0);
}

void MainWindow::on_actionSave_as_triggered()
{
	if (!ui->enginename->text().isEmpty()) {
		QString filen = QFileDialog::getSaveFileName(this, "保存引擎信息表", QDir::currentPath(), "Infinity引擎信息表(*.ifteinfor)");
		if (!filen.isEmpty()) {
			QFileInfo filei(filen);
			QDir::setCurrent(filei.absolutePath());

			QJsonObject jo;
			jo.insert("IMT_Version", ::_IMT_Version);
			jo.insert("name", ui->enginename->text());
			jo.insert("main", ui->enginemain->text());
			QByteArray icondata;
			QBuffer iconbuffer(&icondata);
			ui->engineicon->getPix().save(&iconbuffer, "PNG");
			jo.insert("icon", QString::fromLocal8Bit(icondata.toBase64()));
			jo.insert("author", ui->engineauthor->text());
			jo.insert("version", ui->engineversion->value());
			jo.insert("infor", ui->engineinfor->toPlainText());

			QJsonArray ewpa, enpa;

			for (int i = 0; i < ui->ewplist->rowCount(); i++) {
				QJsonObject sjo;
				sjo.insert("name", ui->ewplist->item(i, 0)->text());
				sjo.insert("max", ui->ewplist->item(i, 1)->text().toDouble());
				sjo.insert("min", ui->ewplist->item(i, 2)->text().toDouble());
				sjo.insert("default", ui->ewplist->item(i, 3)->text().toDouble());
				ewpa.append(sjo);
			}
			for (int i = 0; i < ui->enplist->rowCount(); i++) {
				QJsonObject sjo;
				sjo.insert("name", ui->enplist->item(i, 0)->text());
				sjo.insert("max", ui->enplist->item(i, 1)->text().toDouble());
				sjo.insert("min", ui->enplist->item(i, 2)->text().toDouble());
				sjo.insert("default", ui->enplist->item(i, 3)->text().toDouble());
				enpa.append(sjo);
			}

			jo.insert("ewp", ewpa);
			jo.insert("enp", enpa);

			jo.insert("checkmethod", ui->enginecheckmethod->currentIndex());
			jo.insert("autocheck", ui->engineautocheck->isChecked());
			jo.insert("eula", ui->engineeula->toPlainText());
			jo.insert("warrantdate", ui->enginewarrantdate->selectedDate().toString("yyyy-MM-dd"));
			jo.insert("warranttime", ui->enginewarranttime->time().toString("hh:mm:ss"));

			QJsonDocument jd;
			jd.setObject(jo);

			QByteArray data = jd.toJson(QJsonDocument::Indented);

			QFile file(filen);
			if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
				file.write(data);
				file.close();
				QMessageBox::information(this, "保存", "已保存引擎信息表：" + filen);
			}
			else {
				QMessageBox::warning(this, "出错", "无法打开文件：" + filen);
			}
		}
	}
	else {
		QMessageBox::warning(this, "出错", "未设置引擎名称");
	}
	ui->tabWidget->setCurrentIndex(0);
	ui->toolBox->setCurrentIndex(0);
}

void MainWindow::on_loadlibraryengine_clicked()
{
	QString filen = QFileDialog::getOpenFileName(this, "选择引擎信息表", QDir::currentPath(), "Infinity引擎信息表(*.ifteinfor)");
	if (!filen.isEmpty()) {
		QFileInfo filei(filen);
		QDir::setCurrent(filei.absolutePath());

		QFile file(filen);
		if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QJsonDocument jd = QJsonDocument::fromJson(file.readAll());
			file.close();
			if (jd.isObject()) {
				QJsonObject jo = jd.object();

				if (jo.find("IMT_Version")->toDouble() <= ::_IMT_Version) {
					ui->libraryengine->setText(jo.find("name")->toString());
				}
				else {
					QMessageBox::warning(this, "出错", "不支持的文件版本：" + filen);
				}
			}
			else {
				QMessageBox::warning(this, "出错", "文件格式损坏：" + filen);
			}
		}
		else {
			QMessageBox::warning(this, "出错", "无法打开文件：" + filen);
		}
	}
}

void MainWindow::on_loadlibrarydictionary_clicked()
{
	QString filen = QFileDialog::getExistingDirectory(this, "选择字典", QDir::currentPath());
	if (!filen.isEmpty()) {
		QDir::setCurrent(filen);
		QFile file(filen + "/dictionary.json");
		if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QJsonDocument jd = QJsonDocument::fromJson(file.readAll());
			file.close();
			if (jd.isObject()) {
				QJsonObject jo = jd.object();

				if (jo.find("version")->toDouble() <= ::_IMT_Version) {
					ui->librarydictionary->setText(jo.find("name")->toString());
				}
				else {
					QMessageBox::warning(this, "出错", "不支持的文件版本：" + filen + "/dictionary.json");
				}

			}
			else {
				QMessageBox::warning(this, "出错", "文件格式损坏：" + filen + "/dictionary.json");
			}
		}
		else {
			QMessageBox::warning(this, "出错", "无法打开文件：" + filen + "/dictionary.json");
		}
	}
}

void MainWindow::on_loadlibraryicon_clicked()
{
	QString name = QFileDialog::getOpenFileName(this, "选择声库立绘", QDir::currentPath(), "图像文件(*.jpg *.jpeg *.png *.bmp)");
	if (!name.isEmpty()) {
		QFileInfo filei(name);
		QDir::setCurrent(filei.absolutePath());
		ui->libraryiconname->setText(name);
		QPixmap pix(name);
		ui->libraryicon->setPix(pix);
	}
}

void MainWindow::on_lsdlist_currentItemChanged(QListWidgetItem* item1, QListWidgetItem* item2)
{
	Q_UNUSED(item1);
	Q_UNUSED(item2);
	int index = ui->lsdlist->currentRow();
	if (index >= 0 && index < ui->lsdlist->count()) {
		ui->lsdadd->setEnabled(true);
		ui->lsdedit->setEnabled(true);
		ui->lsddel->setEnabled(true);
		if (index > 0) {
			ui->lsdup->setEnabled(true);
		}
		else {
			ui->lsdup->setEnabled(false);
		}
		if (index < ui->lsdlist->count() - 1) {
			ui->lsddown->setEnabled(true);
		}
		else {
			ui->lsddown->setEnabled(false);
		}
	}
	else {
		ui->lsdadd->setEnabled(true);
		ui->lsdedit->setEnabled(false);
		ui->lsddel->setEnabled(false);
		ui->lsdup->setEnabled(false);
		ui->lsddown->setEnabled(false);
	}
}

void MainWindow::on_lsdadd_clicked()
{
	QString sname = QInputDialog::getText(this, "新音阶", "输入音阶名称");
	if (!sname.isEmpty()) {
		bool ok = true;
		for (int i = 0; i < ui->lsdlist->count(); i++) {
			if (ui->lsdlist->item(i)->text() == sname) {
				ok = false;
				break;
			}
		}
		if (ok) {
			ui->lsdlist->insertItem(0, sname);
			ui->lsddefault->insertItem(0, sname);
		}
		else {
			QMessageBox::warning(this, "出错", "重复的项目！");
		}
	}
}

void MainWindow::on_lsdedit_clicked()
{
	int index = ui->lsdlist->currentRow();
	QString sdt = ui->lsdlist->item(index)->text();
	QString sname = QInputDialog::getText(this, "编辑音阶", "输入音阶名称", QLineEdit::Normal, ui->lsdlist->item(index)->text());
	if (!sname.isEmpty()) {
		bool ok = true;
		for (int i = 0; i < ui->lsdlist->count(); i++) {
			if (i != index) {
				if (ui->lsdlist->item(i)->text() == sname) {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			ui->lsdlist->item(index)->setText(sname);
			ui->lsddefault->setItemText(index, sname);
			for (int i = 0; i < ui->lsdlink->rowCount(); i++) {
				if (ui->lsdlink->item(i, 1)->text() == sdt) {
					ui->lsdlink->item(i, 1)->setText(sname);
				}
			}
		}
		else {
			QMessageBox::warning(this, "出错", "重复的项目！");
		}
	}
}

void MainWindow::on_lsddel_clicked()
{
	int index = ui->lsdlist->currentRow();
	QString sdt = ui->lsdlist->item(index)->text();
	delete ui->lsdlist->takeItem(index);
	ui->lsddefault->removeItem(index);
	for (int i = 0; i < ui->lsdlink->rowCount(); i++) {
		if (ui->lsdlink->item(i, 1)->text() == sdt) {
			ui->lsdlink->item(i, 1)->setText(ui->lsddefault->currentText());
		}
	}
}

void MainWindow::on_lsdup_clicked()
{
	int index = ui->lsdlist->currentRow();
	QString strt = ui->lsdlist->item(index - 1)->text();
	ui->lsdlist->item(index - 1)->setText(ui->lsdlist->item(index)->text());
	ui->lsddefault->setItemText(index - 1, ui->lsdlist->item(index)->text());
	ui->lsdlist->item(index)->setText(strt);
	ui->lsddefault->setItemText(index, strt);
	ui->lsdlist->setCurrentRow(index - 1);
}

void MainWindow::on_lsddown_clicked()
{
	int index = ui->lsdlist->currentRow();
	QString strt = ui->lsdlist->item(index + 1)->text();
	ui->lsdlist->item(index + 1)->setText(ui->lsdlist->item(index)->text());
	ui->lsddefault->setItemText(index + 1, ui->lsdlist->item(index)->text());
	ui->lsdlist->item(index)->setText(strt);
	ui->lsddefault->setItemText(index, strt);
	ui->lsdlist->setCurrentRow(index + 1);
}

void MainWindow::on_lsdlink_currentItemChanged(QTableWidgetItem* item1, QTableWidgetItem* item2)
{
	Q_UNUSED(item1);
	Q_UNUSED(item2);
	int index = ui->lsdlink->currentRow();
	if (index >= 0 && index < ui->lsdlink->rowCount()) {
		ui->lladd->setEnabled(true);
		ui->lledit->setEnabled(true);
		ui->lldel->setEnabled(true);
		if (index > 0) {
			ui->llup->setEnabled(true);
		}
		else {
			ui->llup->setEnabled(false);
		}
		if (index < ui->lsdlink->rowCount() - 1) {
			ui->lldown->setEnabled(true);
		}
		else {
			ui->lldown->setEnabled(false);
		}
	}
	else {
		ui->lladd->setEnabled(true);
		ui->lledit->setEnabled(false);
		ui->lldel->setEnabled(false);
		ui->llup->setEnabled(false);
		ui->lldown->setEnabled(false);
	}
}

void MainWindow::on_lladd_clicked()
{
	SLDialog sld(this);
	sld.setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
	QStringList sdblist;
	for (int i = 0; i < ui->lsdlist->count(); i++) {
		sdblist.append(ui->lsdlist->item(i)->text());
	}
	sld.setlist(sdblist);
	sld.exec();
	if (!sld.pitch.isEmpty() && !sld.sdb.isEmpty()) {
		bool ok = true;
		for (int i = 0; i < ui->lsdlink->rowCount(); i++) {
			if (ui->lsdlink->item(i, 0)->text() == sld.pitch) {
				ok = false;
				break;
			}
		}
		if (ok) {
			ui->lsdlink->insertRow(0);
			this->setllrow(0, sld.pitch, sld.sdb);
		}
		else {
			QMessageBox::warning(this, "出错", "重复的项目！");
		}
	}
}

void MainWindow::on_lledit_clicked()
{
	int index = ui->lsdlink->currentRow();
	SLDialog sld(this);
	sld.setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
	QStringList sdblist;
	for (int i = 0; i < ui->lsdlist->count(); i++) {
		sdblist.append(ui->lsdlist->item(i)->text());
	}
	sld.setlist(sdblist);
	sld.setlink(
		ui->lsdlink->item(index, 0)->text(),
		ui->lsdlink->item(index, 1)->text()
	);
	sld.exec();
	if (!sld.pitch.isEmpty() && !sld.sdb.isEmpty()) {
		bool ok = true;
		for (int i = 0; i < ui->lsdlink->rowCount(); i++) {
			if (i != index) {
				if (ui->lsdlink->item(i, 0)->text() == sld.pitch) {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			this->setllrow(index, sld.pitch, sld.sdb);
		}
		else {
			QMessageBox::warning(this, "出错", "重复的项目！");
		}
	}
}

void MainWindow::on_lldel_clicked()
{
	int index = ui->lsdlink->currentRow();
	ui->lsdlink->removeRow(index);
}

void MainWindow::on_llup_clicked()
{
	int index = ui->lsdlink->currentRow();
	QString pitcht = ui->lsdlink->item(index - 1, 0)->text();
	QString sdbt = ui->lsdlink->item(index - 1, 1)->text();
	this->setllrow(
		index - 1,
		ui->lsdlink->item(index, 0)->text(),
		ui->lsdlink->item(index, 1)->text()
	);
	this->setllrow(index, pitcht, sdbt);
	ui->lsdlink->setCurrentCell(index - 1, 0);
}

void MainWindow::on_lldown_clicked()
{
	int index = ui->lsdlink->currentRow();
	QString pitcht = ui->lsdlink->item(index + 1, 0)->text();
	QString sdbt = ui->lsdlink->item(index + 1, 1)->text();
	this->setllrow(
		index + 1,
		ui->lsdlink->item(index, 0)->text(),
		ui->lsdlink->item(index, 1)->text()
	);
	this->setllrow(index, pitcht, sdbt);
	ui->lsdlink->setCurrentCell(index + 1, 0);
}

void MainWindow::on_actionNew_2_triggered()
{
	ui->libraryname->clear();
	ui->libraryengine->clear();
	ui->librarydictionary->clear();
	ui->libraryiconname->clear();
	ui->libraryicon->setPix(QPixmap());
	ui->libraryauthor->clear();
	ui->libraryversion->setValue(0.1);
	ui->libraryinfor->clear();
	while (ui->lsdlist->count() > 0) {
		delete ui->lsdlist->takeItem(0);
	}
	ui->lsddefault->clear();
	while (ui->lsdlink->rowCount() > 0) {
		ui->lsdlink->removeRow(0);
	}
	ui->librarycheckmethod->setCurrentIndex(0);
	ui->libraryautocheck->setChecked(true);
	ui->libraryeula->clear();
	ui->librarywarrantdate->setSelectedDate(QDate::currentDate().addDays(1));
	ui->librarywarranttime->setTime(QTime::fromString("00:00:00", "hh:mm:ss"));
	ui->tabWidget->setCurrentIndex(1);
	ui->toolBox_2->setCurrentIndex(0);
}

void MainWindow::on_actionOpen_2_triggered()
{
	QString filen = QFileDialog::getOpenFileName(this, "读取声库信息表", QDir::currentPath(), "Infinity声库信息表(*.iftlinfor)");
	if (!filen.isEmpty()) {
		QFileInfo filei(filen);
		QDir::setCurrent(filei.absolutePath());

		QFile file(filen);
		if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QJsonDocument jd = QJsonDocument::fromJson(file.readAll());
			file.close();
			if (jd.isObject()) {
				QJsonObject jo = jd.object();

				if (jo.find("IMT_Version")->toDouble() <= ::_IMT_Version) {
					ui->libraryname->setText(jo.find("name")->toString());
					ui->libraryengine->setText(jo.find("engine")->toString());
					ui->librarydictionary->setText(jo.find("dictionary")->toString());
					ui->libraryiconname->setText("From information form");
					QPixmap pix;
					pix.loadFromData(QByteArray::fromBase64(jo.find("icon")->toString().toLocal8Bit()));
					ui->libraryicon->setPix(pix);
					ui->libraryauthor->setText(jo.find("author")->toString());
					ui->libraryversion->setValue(jo.find("version")->toDouble());
					ui->libraryinfor->setPlainText(jo.find("infor")->toString());

					QJsonArray sdblista = jo.find("sdblist")->toArray();
					QJsonArray sdblinka = jo.find("sdblink")->toArray();

					while (ui->lsdlist->count() > 0) {
						delete ui->lsdlist->takeItem(0);
					}
					ui->lsddefault->clear();
					while (ui->lsdlink->rowCount() > 0) {
						ui->lsdlink->removeRow(0);
					}

					for (int i = 0; i < sdblista.size(); i++) {
						QString sname = sdblista.at(i).toString();
						int count = ui->lsdlist->count();
						ui->lsdlist->insertItem(count, sname);
						ui->lsddefault->insertItem(count, sname);
					}
					ui->lsddefault->setCurrentText(jo.find("sdbdefault")->toString());

					for (int i = 0; i < sdblinka.size(); i++) {
						QJsonObject sjo = sdblinka.at(i).toObject();
						int index = ui->lsdlink->rowCount();
						ui->lsdlink->insertRow(index);
						this->setllrow(
							index,
							sjo.find("pitch")->toString(),
							sjo.find("sdb")->toString()
						);
					}

					ui->librarycheckmethod->setCurrentIndex(jo.find("checkmethod")->toInt());
					ui->libraryautocheck->setChecked(jo.find("autocheck")->toBool());
					ui->libraryeula->setPlainText(jo.find("eula")->toString());
					ui->librarywarrantdate->setSelectedDate(QDate::fromString(jo.find("warrantdate")->toString(), "yyyy-MM-dd"));
					ui->librarywarranttime->setTime(QTime::fromString(jo.find("warranttime")->toString(), "hh:mm:ss"));
				}
				else {
					QMessageBox::warning(this, "出错", "不支持的文件版本：" + filen);
				}
			}
			else {
				QMessageBox::warning(this, "出错", "文件格式损坏：" + filen);
			}
		}
		else {
			QMessageBox::warning(this, "出错", "无法打开文件：" + filen);
		}
	}
	ui->tabWidget->setCurrentIndex(1);
	ui->toolBox->setCurrentIndex(0);
}

void MainWindow::on_actionSave_as_2_triggered()
{
	if (!ui->libraryname->text().isEmpty()) {
		if (ui->lsddefault->count() > 0) {
			QString filen = QFileDialog::getSaveFileName(this, "保存声库信息表", QDir::currentPath(), "Infinity声库信息表(*.iftlinfor)");
			if (!filen.isEmpty()) {
				QFileInfo filei(filen);
				QDir::setCurrent(filei.absolutePath());

				QJsonObject jo;
				jo.insert("IMT_Version", ::_IMT_Version);
				jo.insert("name", ui->libraryname->text());
				jo.insert("engine", ui->libraryengine->text());
				jo.insert("dictionary", ui->librarydictionary->text());
				QByteArray icondata;
				QBuffer iconbuffer(&icondata);
				ui->libraryicon->getPix().save(&iconbuffer, "PNG");
				jo.insert("icon", QString::fromLocal8Bit(icondata.toBase64()));
				jo.insert("author", ui->libraryauthor->text());
				jo.insert("version", ui->libraryversion->value());
				jo.insert("infor", ui->libraryinfor->toPlainText());

				QJsonArray sdblista, sdblinka;

				for (int i = 0; i < ui->lsdlist->count(); i++) {
					sdblista.append(ui->lsdlist->item(i)->text());
				}

				for (int i = 0; i < ui->lsdlink->rowCount(); i++) {
					QJsonObject sjo;
					sjo.insert("pitch", ui->lsdlink->item(i, 0)->text());
					sjo.insert("sdb", ui->lsdlink->item(i, 1)->text());
					sdblinka.append(sjo);
				}
				jo.insert("sdbdefault", ui->lsddefault->currentText());
				jo.insert("sdblist", sdblista);
				jo.insert("sdblink", sdblinka);

				jo.insert("checkmethod", ui->librarycheckmethod->currentIndex());
				jo.insert("autocheck", ui->libraryautocheck->isChecked());
				jo.insert("eula", ui->libraryeula->toPlainText());
				jo.insert("warrantdate", ui->librarywarrantdate->selectedDate().toString("yyyy-MM-dd"));
				jo.insert("warranttime", ui->librarywarranttime->time().toString("hh:mm:ss"));

				QJsonDocument jd;
				jd.setObject(jo);

				QByteArray data = jd.toJson(QJsonDocument::Indented);

				QFile file(filen);
				if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
					file.write(data);
					file.close();
					QMessageBox::information(this, "保存", "已保存声库信息表：" + filen);
				}
				else {
					QMessageBox::warning(this, "出错", "无法打开文件：" + filen);
				}
			}
		}
		else {
			QMessageBox::warning(this, "出错", "未设置声库默认音阶");
		}
	}
	else {
		QMessageBox::warning(this, "出错", "未设置声库名称");
	}
	ui->tabWidget->setCurrentIndex(1);
	ui->toolBox->setCurrentIndex(0);
}


void MainWindow::on_actionFiles_triggered()
{
	FTBDialog ftbd(this);
	ftbd.setWindowFlags(Qt::Dialog | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
	ftbd.exec();
}

void MainWindow::on_actionSign_triggered()
{
	QString filen = QFileDialog::getOpenFileName(this, "选择要签名的信息表", QDir::currentPath(), "Infinity引擎信息表(*.ifteinfor);;Infinity声库信息表(*.iftlinfor)");
	if (!filen.isEmpty()) {
		QFileInfo filei(filen);
		QDir::setCurrent(filei.absolutePath());

		QFile file(filen);
		if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QString data = file.readAll();
			QJsonDocument jd = QJsonDocument::fromJson(data.toUtf8());
			file.close();
			if (jd.isObject()) {
				QJsonObject jo = jd.object();

				if (jo.find("IMT_Version")->toDouble() <= ::_IMT_Version) {

					QFile prikeyfile(":/keys/keys/1.pri.key");
					if (prikeyfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
						QString prikey = prikeyfile.readAll();
						prikeyfile.close();

						QCryptographicHash hash(QCryptographicHash::Sha512);
						hash.addData(data.toLatin1().data());
						QString datahash = hash.result().toHex().toLower();

						QString datasign;
						RSASignature::private_encrypt(datahash, prikey, datasign);

						QFile signfile(filen + ".signature");
						if (signfile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
							signfile.write(datasign.toUtf8());
							signfile.close();
							QMessageBox::information(this, "签名", "已对信息表签名：" + filen);
						}
						else {
							QMessageBox::warning(this, "出错", "无法写入签名文件！");
						}
					}
					else {
						QMessageBox::warning(this, "出错", "无法载入私钥！");
					}
				}
				else {
					QMessageBox::warning(this, "出错", "不支持的文件版本：" + filen);
				}
			}
			else {
				QMessageBox::warning(this, "出错", "文件格式损坏：" + filen);
			}
		}
		else {
			QMessageBox::warning(this, "出错", "无法打开文件：" + filen);
		}
	}
}

void MainWindow::on_actionCheckSign_triggered()
{
	QString filen = QFileDialog::getOpenFileName(this, "选择要校验签名的信息表", QDir::currentPath(), "Infinity引擎信息表(*.ifteinfor);;Infinity声库信息表(*.iftlinfor)");
	if (!filen.isEmpty()) {
		QFileInfo filei(filen);
		QDir::setCurrent(filei.absolutePath());

		QFile file(filen);
		if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QString data = file.readAll();
			QJsonDocument jd = QJsonDocument::fromJson(data.toUtf8());
			file.close();
			if (jd.isObject()) {
				QJsonObject jo = jd.object();

				if (jo.find("IMT_Version")->toDouble() <= ::_IMT_Version) {

					QFile publicfile(":/keys/keys/1.pub.key");
					if (publicfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
						QString pubkey = publicfile.readAll();
						publicfile.close();

						QCryptographicHash hash(QCryptographicHash::Sha512);
						hash.addData(data.toLatin1().data());
						QString datahash = hash.result().toHex().toLower();

						QFile signfile(filen + ".signature");
						if (signfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
							QString signdata = signfile.readAll();
							signfile.close();

							QString datadecrypted;
							RSASignature::public_decrypt(signdata, pubkey, datadecrypted);

							if (datadecrypted == datahash) {
								QMessageBox::information(this, "签名校验", "信息表的指纹与签名相符：" + filen);
							}
							else {
								QMessageBox::warning(this, "签名校验", "信息表的指纹与签名不符：" + filen);
							}
						}
						else {
							QMessageBox::warning(this, "出错", "签名文件丢失或无法读取！");
						}
					}
					else {
						QMessageBox::warning(this, "出错", "无法载入私钥！");
					}
				}
				else {
					QMessageBox::warning(this, "出错", "不支持的文件版本：" + filen);
				}
			}
			else {
				QMessageBox::warning(this, "出错", "文件格式损坏：" + filen);
			}
		}
		else {
			QMessageBox::warning(this, "出错", "无法打开文件：" + filen);
		}
	}
}


void MainWindow::on_actionAbout_triggered()
{
	IIDialog iid(this);
	iid.setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
	iid.exec();
}

void MainWindow::on_actionBuildEngine_triggered()
{
	QString filen = QFileDialog::getExistingDirectory(this, "选择要打包的文件所在目录", QDir::currentPath());
	if (!filen.isEmpty()) {
		QDir::setCurrent(filen);

		QFile listfile(filen + "/.Infinity.MT.Filelist.raw");
		if (listfile.exists()) {
			if (listfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
				QStringList filelist = QString(listfile.readAll()).split("\n", QString::SkipEmptyParts);
				listfile.close();

				if (PKGBuilder::checkFileList(filelist)) {
					QStringList inforlist = PKGBuilder::getInforList(filelist, filen, 0);
					if (inforlist.size() > 0) {
						if (PKGBuilder::checkSignature(inforlist)) {
							QString defaultInforFile = QInputDialog::getItem(
								this,
								"选择打包时使用的信息表",
								"请选择一个信息表并将其中的信息用于打包",
								PKGBuilder::getInforNameList(inforlist, filen),
								0,
								false,
								nullptr,
								Qt::Dialog | Qt::WindowCloseButtonHint
							);
							if (!defaultInforFile.isEmpty()) {
								QString inforname = filen + "/" + defaultInforFile;

								QFile file(inforname);
								if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
									QJsonDocument jd = QJsonDocument::fromJson(file.readAll());
									file.close();
									if (jd.isObject()) {
										QJsonObject jo = jd.object();

										if (jo.find("IMT_Version")->toDouble() <= ::_IMT_Version) {

											PKGBuilder::PKGTask task;

											task.type = 0;
											task.name = jo.find("name")->toString();
											task.IMT_Ver = ::_IMT_Version;
											task.icon = jo.find("icon")->toString().toLocal8Bit();
											task.author = jo.find("author")->toString();
											task.version = jo.find("version")->toDouble();
											task.about = jo.find("infor")->toString();
											task.EULA = jo.find("eula")->toString();
											task.wdate = jo.find("warrantdate")->toString();
											task.wtime = jo.find("warranttime")->toString();
											task.files = filelist;
											task.root = filen;

											QString packfilen = QFileDialog::getSaveFileName(this, "选择包文件生成目标", QDir::currentPath(), "Infinity组件包(*.iftpack)");
											if (!packfilen.isEmpty()) {
												QFileInfo filei(packfilen);
												QDir::setCurrent(filei.absolutePath());

												PKGBuilder::Pack_D(task, packfilen);
												QMessageBox::information(this, "打包", "打包完成");
											}
											else {
												QMessageBox::warning(this, "出错", "未选择包文件生成目标，已取消打包");
											}
										}
										else {
											QMessageBox::warning(this, "出错", "不支持的文件版本：" + inforname);
										}
									}
									else {
										QMessageBox::warning(this, "出错", "文件格式损坏：" + inforname);
									}
								}
								else {
									QMessageBox::warning(this, "出错", "无法打开文件：" + inforname);
								}
							}
							else {
								QMessageBox::warning(this, "出错", "未选择打包时使用的信息表，已取消打包");
							}
						}
						else {
							QMessageBox::warning(this, "出错", "文件树根目录中有签名无效的信息表文件");
						}
					}
					else {
						QMessageBox::warning(this, "出错", "文件树根目录中不存在信息表文件");
					}
				}
				else {
					QMessageBox::warning(this, "出错", "文件树中有文件不存在");
				}
			}
			else {
				QMessageBox::warning(this, "出错", "无法打开文件树");
			}
		}
		else {
			QMessageBox::warning(this, "出错", "目录内没有找到文件树");
		}
	}
}

void MainWindow::on_actionBuildLibrary_triggered()
{

}

void MainWindow::on_actionBuildDictionary_triggered()
{

}
