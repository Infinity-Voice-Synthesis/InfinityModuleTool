#pragma once

#include <QString>
#include <QByteArray>
#include <QFile>
#include <QDataStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QCryptographicHash>
#include "rsasignature.h"
#include <QStringList>

typedef unsigned long RIFF_SIZE;

class PKGBuilder
{
public:
	PKGBuilder();
	~PKGBuilder();
	struct PKGTask
	{
		int type;
		double IMT_Ver;
		QString name;
		QByteArray icon;
		QString author;
		QString EULA;
		QString wdate;
		QString wtime;
		QStringList files;
		QString root;
	};

	static void appendChunk(QDataStream stream, char* name, QByteArray data);
	static QByteArray BuildChunk(char* name, QByteArray data);
	static void appendFile(QByteArray* chunkdata, QByteArray filedata, QString filepos);
	static QByteArray BuildInformationChunk(int type, double IMT_Ver, double Ver, QString name, QByteArray icon, QString author, QString EULA, QString wdate, QString wtime);
	static QByteArray SignChunk(QByteArray chunkdata);
	static QByteArray BuildPack(QByteArray inforchunk, QByteArray filechunk);
	static QString getPosPath(int type, QString filepath, QString rootpath, QString pkgname);
	static QByteArray BuildListChunk(int type, QStringList filelist, QString rootpath, QString pkgname);
};
