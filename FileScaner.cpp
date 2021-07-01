#include "FileScaner.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

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
			if (dir[i] != "." && dir[i] != "..") {
				FileScaner::DFS(filelist, path + "/" + dir[i]);
			}
		}
	}
}

QStringList FileScaner::Search(QString path)
{
	QStringList filelist;
	FileScaner::DFS(&filelist, path);
	return filelist;
}

QStringList FileScaner::getDir(QStringList filelist)
{
	QStringList dirs;
	for (int i = 0; i < filelist.size(); i++) {
		QFileInfo fi(filelist.at(i));
		dirs.append(fi.absolutePath());
	}
	return dirs;
}

QStringList FileScaner::getDirReflect(QStringList dirlist, QString mainpath)
{
	QStringList reflectDir;
	for (int i = 0; i < dirlist.size(); i++) {
		if (dirlist.at(i).startsWith(mainpath + "/")) {
			QString st = dirlist.at(i);
			reflectDir.append(st.right(st.size() - (mainpath.size() + 1)));
		}
	}
	return reflectDir;
}
