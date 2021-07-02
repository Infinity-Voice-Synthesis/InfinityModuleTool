#include "PKGBuilder.h"

PKGBuilder::PKGBuilder()
{
}

PKGBuilder::~PKGBuilder()
{
}

void PKGBuilder::appendChunk(QDataStream stream, char* name, QByteArray data)
{
	RIFF_SIZE size = data.size();
	stream << name[0] << name[1] << name[2] << name[3];
	stream.writeRawData((char*)&size, sizeof(RIFF_SIZE));
	stream << data;
}

QByteArray PKGBuilder::BuildChunk(char* name, QByteArray data)
{
	RIFF_SIZE size = data.size();
	QByteArray chunk;
	chunk.append(name, 4);
	chunk.append((char*)&size, sizeof(RIFF_SIZE));
	chunk.append(data);
	return chunk;
}
/*
* ==========
* 'F''I''L''E'(size)
*	==========
*	'H''E''A''D'(size)
*		==========
*		'M''D''5''\0'(size)
*		...
*		==========
*		==========
*		'P''S''P''T'(size)
*		...
*		==========
*	==========
*	==========
*	'D''A''T''A'(size)
*	...
*	==========
* ==========
*/
void PKGBuilder::appendFile(QByteArray* chunkdata, QByteArray filedata, QString filepos)
{
	QByteArray fpa = filepos.toUtf8();
	QByteArray fh, fd;
	QByteArray filechunk;
	QByteArray fmd5, fpos;
	QCryptographicHash hash(QCryptographicHash::Md5);
	hash.addData(filedata);
	QByteArray fha = hash.result();

	char md5head[4] = { 'M','D','5','\0' };
	char poshead[4] = { 'P','S','P','T' };
	char fhhead[4] = { 'H','E','A','D' };
	char fdatahead[4] = { 'D','A','T','A' };
	char filehead[4] = { 'F','I','L','E' };

	fmd5 = BuildChunk(md5head, fha);
	fpos = BuildChunk(poshead, fpa);

	fh = BuildChunk(fhhead, fmd5 + fpos);
	fd = BuildChunk(fdatahead, filedata);

	filechunk = BuildChunk(filehead, fh + fd);

	*chunkdata += filechunk;
}
/*
* ==========
* 'I''F''M''T'(size)
*	(type)
*	(IMT_Ver)
*	(Ver)
*	==========
*	'N''A''M''E'(size)
*	...
*	==========
*	==========
*	'I''C''O''N'(size)
*	...
*	==========
*	==========
*	'A''T''H''R'(size)
*	...
*	==========
*	==========
*	'E''U''L''A'(size)
*	...
*	==========
*	==========
*	'D''A''T''E'(size)
*	...
*	==========
*	==========
*	'T''I''M''E'(size)
*	...
*	==========
* ==========
*/
QByteArray PKGBuilder::BuildInformationChunk(int type, double IMT_Ver, double Ver, QString name, QByteArray icon, QString author, QString EULA, QString wdate, QString wtime)
{
	QByteArray inforchunk, infordata;

	QByteArray namedata, authordata, EULAdata, wdatedata, wtimedata;
	QByteArray namechunk, iconchunk, authorchunk, EULAchunk, wdatechunk, wtimechunk;

	namedata = name.toUtf8();
	authordata = author.toUtf8();
	EULAdata = EULA.toUtf8();
	wdatedata = wdate.toUtf8();
	wtimedata = wtime.toUtf8();

	infordata.append((char*)&type, sizeof(int));
	infordata.append((char*)&IMT_Ver, sizeof(double));
	infordata.append((char*)&Ver, sizeof(double));

	char inforhead[4] = { 'I','F','M','T' };
	char namehead[4] = { 'N','A','M','E' };
	char iconhead[4] = { 'I','C','O','N' };
	char authorhead[4] = { 'A','T','H','R' };
	char EULAhead[4] = { 'E','U','L','A' };
	char wdatehead[4] = { 'D','A','T','E' };
	char wtimehead[4] = { 'T','I','M','E' };

	namechunk = BuildChunk(namehead, namedata);
	iconchunk = BuildChunk(iconhead, icon);
	authorchunk = BuildChunk(authorhead, authordata);
	EULAchunk = BuildChunk(EULAhead, EULAdata);
	wdatechunk = BuildChunk(wdatehead, wdatedata);
	wtimechunk = BuildChunk(wtimehead, wtimedata);

	infordata.append(namechunk);
	infordata.append(iconchunk);
	infordata.append(authorchunk);
	infordata.append(EULAchunk);
	infordata.append(wdatechunk);
	infordata.append(wtimechunk);

	inforchunk = BuildChunk(inforhead, infordata);
	return inforchunk;
}

QByteArray PKGBuilder::SignChunk(QByteArray chunkdata)
{
	QByteArray sign;
	QFile prikeyfile(":/keys/keys/1.pri.key");
	if (prikeyfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
		QString prikey = prikeyfile.readAll();
		prikeyfile.close();

		QCryptographicHash hash(QCryptographicHash::Sha512);
		hash.addData(chunkdata);
		QString datahash = hash.result().toHex().toLower();

		QString datasign;
		RSASignature::private_encrypt(datahash, prikey, datasign);

		sign = datasign.toUtf8();
	}
	return sign;
}
/*
* ==========
* 'R''I''F''F'(size)
*	==========
*	'S''I''G''N'(size)
*	...
*	==========
*	==========
*	'P''A''C''K'(size)
*		==========
*		'I''F''M''T'(size)
*		...
*		==========
*		==========
*		'L''I''S''T'(size)
*		...
*		==========
*	==========
* ==========
*/
QByteArray PKGBuilder::BuildPack(QByteArray inforchunk, QByteArray filechunk)
{
	QByteArray packchunk;

	char packhead[4] = { 'P','A','C','K' };
	char signhead[4] = { 'S','I','G','N' };
	char riffhead[4] = { 'R','I','F','F' };

	packchunk = BuildChunk(packhead, inforchunk + filechunk);

	QByteArray packsign = SignChunk(packchunk);
	QByteArray signchunk = BuildChunk(signhead, packsign);

	return BuildChunk(riffhead, signchunk + packchunk);
}

QString PKGBuilder::getPosPath(int type, QString filepath, QString rootpath, QString pkgname)
{
	QString fpt = filepath;
	if (fpt.startsWith(rootpath)) {
		fpt = fpt.left(fpt.size() - rootpath.size());
		if (type == 0) {
			fpt.prepend("<enginePath>" + QString("/") + pkgname);
		}
		if (type == 1) {
			fpt.prepend("<libraryPath>" + QString("/") + pkgname);
		}
		if (type == 2) {
			fpt.prepend("<dictionaryPath>" + QString("/") + pkgname);
		}
		if (type == 3) {
			fpt.prepend("<scriptPath>");
		}
	}
	return fpt;
}
/*
* ==========
* 'L''I''S''T'(size)
*	==========
*	'F''I''L''E'(size)
*	...
*	==========
*	==========
*	'F''I''L''E'(size)
*	...
*	==========
* ...
*	==========
*	'F''I''L''E'(size)
*	...
*	==========
* ==========
*/
QByteArray PKGBuilder::BuildListChunk(int type, QStringList filelist, QString rootpath, QString pkgname)
{
	QByteArray listdata;
	for (int i = 0; i < filelist.size(); i++) {
		QFile file(filelist.at(i));
		file.open(QIODevice::ReadOnly);
		QByteArray datatemp = file.readAll();
		file.close();
		appendFile(&listdata, datatemp, getPosPath(type, filelist.at(i), rootpath, pkgname));
	}
	char listhead[4] = { 'L','I','S','T' };
	return BuildChunk(listhead, listdata);
}

QByteArray PKGBuilder::Pack(PKGTask task)
{
	QByteArray listchunk = BuildListChunk(task.type, task.files, task.root, task.name);
	QByteArray inforchunk = BuildInformationChunk(
		task.type,
		task.IMT_Ver,
		task.version,
		task.name,
		task.icon,
		task.author,
		task.EULA,
		task.wdate,
		task.wtime
	);
	return BuildPack(inforchunk, listchunk);
}
