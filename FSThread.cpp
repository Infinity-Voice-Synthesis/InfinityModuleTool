#include "FSThread.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

FSThread::FSThread()
	: QThread()
{
}

FSThread::~FSThread()
{
	if (this->isRunning()) {
		this->terminate();
		this->wait();
	}
}

void FSThread::run()
{
	result.clear();
	result = FileScaner::Search(path);
	emit finished();
	quit();
	return;
}

void FSThread::setPath(QString path)
{
	if (!this->isRunning()) {
		this->path = path;
		this->result.clear();
	}
}

QStringList FSThread::getResult()
{
	return this->result;
}
