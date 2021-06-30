#pragma once

#include <QString>
#include <QDir>
#include <QStringList>

class FileScaner
{
public:
	FileScaner();
	~FileScaner();
private:
	static void DFS(QStringList* filelist, QString path);
};
