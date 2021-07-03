#pragma once

#include <QThread>
#include "PKGBuilder.h"

class BuildThread : public QThread
{
	Q_OBJECT
public:
	BuildThread();
	~BuildThread();
	void setTask(QString packfile, PKGBuilder::PKGTask task);

	QString packfile;
	PKGBuilder::PKGTask task;
protected:
	void run() override;
signals:
	void buildfinished();
};
