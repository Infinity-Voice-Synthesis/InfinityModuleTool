#include "BuildThread.h"

BuildThread::BuildThread()
{
}

BuildThread::~BuildThread()
{
	if (this->isRunning()) {
		this->terminate();
		this->wait();
	}
}

void BuildThread::setTask(QString packfile, PKGBuilder::PKGTask task)
{
	this->packfile = packfile;
	this->task = task;
}

void BuildThread::run()
{
	PKGBuilder::Pack_D(task, packfile);
	emit buildfinished();
	quit();
	return;
}
