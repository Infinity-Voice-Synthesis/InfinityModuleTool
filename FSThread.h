#pragma once

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QThread>
#include <QObject>
#include <QString>
#include <QStringList>
#include "FileScaner.h"

class FSThread : public QThread
{
	Q_OBJECT

public:
	FSThread();
	~FSThread();
	void setPath(QString path);
	QStringList getResult();

protected:
	void run() override;
private:
	QString path;
	QStringList result;
signals:
	void finished();
};
