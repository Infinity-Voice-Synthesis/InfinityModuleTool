#include "FileScaner.h"

FileScaner::FileScaner()
{
}

FileScaner::~FileScaner()
{
}

void FileScaner::DFS(QStringList* filelist, QString path)
{
	QDir dir(path);
	if (dir.exists()) {
		dir.setFilter(QDir::Files);
		for (uint i = 0; i < dir.count(); i++) {
			filelist->append(path + "/" + dir[i]);
		}

		dir.setFilter(QDir::Dirs);
		for (uint i = 0; i < dir.count(); i++) {
			FileScaner::DFS(filelist, path + "/" + dir[i]);
		}
	}
}