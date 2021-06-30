#pragma once

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QString>
#include <QDir>
#include <QStringList>
#include <QFileInfo>

class FileScaner
{
public:
	FileScaner();
	~FileScaner();

	static QStringList Search(QString path);
	static QStringList getDir(QStringList filelist);
	static QStringList getDirReflect(QStringList dirlist, QString mainpath);
private:
	static void DFS(QStringList* filelist, QString path);
};
