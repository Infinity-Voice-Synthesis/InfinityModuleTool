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
*	'A''B''O''T'(size)
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
QByteArray PKGBuilder::BuildInformationChunk(int type, double IMT_Ver, double Ver, QString name, QByteArray icon, QString author, QString about, QString EULA, QString wdate, QString wtime)
{
	QByteArray inforchunk, infordata;

	QByteArray namedata, authordata, aboutdata, EULAdata, wdatedata, wtimedata;
	QByteArray namechunk, iconchunk, authorchunk, aboutchunk, EULAchunk, wdatechunk, wtimechunk;

	namedata = name.toUtf8();
	authordata = author.toUtf8();
	aboutdata = about.toUtf8();
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
	char abouthead[4] = { 'A','B','O','T' };
	char EULAhead[4] = { 'E','U','L','A' };
	char wdatehead[4] = { 'D','A','T','E' };
	char wtimehead[4] = { 'T','I','M','E' };

	namechunk = BuildChunk(namehead, namedata);
	iconchunk = BuildChunk(iconhead, icon);
	authorchunk = BuildChunk(authorhead, authordata);
	aboutchunk = BuildChunk(abouthead, aboutdata);
	EULAchunk = BuildChunk(EULAhead, EULAdata);
	wdatechunk = BuildChunk(wdatehead, wdatedata);
	wtimechunk = BuildChunk(wtimehead, wtimedata);

	infordata.append(namechunk);
	infordata.append(iconchunk);
	infordata.append(authorchunk);
	infordata.append(aboutchunk);
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
* 'P''A''C''K'(size)
*	==========
*	'I''F''M''T'(size)
*	...
*	==========
*	==========
*	'L''I''S''T'(size)
*	...
*	==========
* ==========
*/
QByteArray PKGBuilder::BuildPack(QByteArray inforchunk, QByteArray filechunk)
{
	char packhead[4] = { 'P','A','C','K' };

	return BuildChunk(packhead, inforchunk + filechunk);
}

QString PKGBuilder::getPosPath(int type, QString filepath, QString rootpath, QString pkgname)
{
	QString fpt = filepath;
	if (fpt.startsWith(rootpath)) {
		fpt = fpt.right(fpt.size() - rootpath.size());
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
		task.about,
		task.EULA,
		task.wdate,
		task.wtime
	);
	return BuildPack(inforchunk, listchunk);
}

bool PKGBuilder::checkFileList(QStringList filelist)
{
	bool ok = true;
	for (int i = 0; i < filelist.size(); i++) {
		QFile file(filelist.at(i));
		if (!file.exists()) {
			ok = false;
			break;
		}
	}
	return ok;
}

QStringList PKGBuilder::getInforList(QStringList filelist, QString rootpath, int type)
{
	QStringList list;
	for (int i = 0; i < filelist.size(); i++) {
		QString stemp = filelist.at(i);
		if (stemp.startsWith(rootpath)) {
			stemp = stemp.right(stemp.size() - rootpath.size() - 1);
			if (!stemp.contains("/")) {
				if (stemp.endsWith(".ifteinfor2") && type == 0) {
					list.append(rootpath + "/" + stemp);
				}
				if (stemp.endsWith(".iftlinfor2") && type == 1) {
					list.append(rootpath + "/" + stemp);
				}
			}
		}
	}
	return list;
}

bool PKGBuilder::checkSign(QString filename)
{
	QFile file(filename);
	if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		QString data = file.readAll();
		file.close();
		QFile publicfile(":/keys/keys/1.pub.key");
		if (publicfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QString pubkey = publicfile.readAll();
			publicfile.close();

			QCryptographicHash hash(QCryptographicHash::Sha512);
			hash.addData(data.toLatin1().data());
			QString datahash = hash.result().toHex().toLower();

			QFile signfile(filename + ".signature");
			if (signfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
				QString signdata = signfile.readAll();
				signfile.close();

				QString datadecrypted;
				RSASignature::public_decrypt(signdata, pubkey, datadecrypted);

				if (datadecrypted == datahash) {
					return true;
				}
			}
		}
	}
	return false;
}

bool PKGBuilder::checkSignature(QStringList inforfilelist)
{
	bool ok = true;
	for (int i = 0; i < inforfilelist.size(); i++) {
		if (!checkSign(inforfilelist.at(i))) {
			ok = false;
			break;
		}
	}
	return ok;
}

QStringList PKGBuilder::getInforNameList(QStringList inforfilelist, QString rootpath)
{
	QStringList list;
	for (int i = 0; i < inforfilelist.size(); i++) {
		QString stemp = inforfilelist.at(i);
		if (stemp.startsWith(rootpath)) {
			stemp = stemp.right(stemp.size() - rootpath.size() - 1);
			list.append(stemp);
		}
	}
	return list;
}

void PKGBuilder::prepareTempory(QString TemporyDir)
{
	QDir dir(TemporyDir);
	if (dir.exists()) {
		dir.removeRecursively();
	}
	dir.mkpath(TemporyDir);
	QFile countfile(TemporyDir + "/.files");
	if (countfile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
		countfile.close();
	}
}

void PKGBuilder::cleanTempory(QString TemporyDir)
{
	QDir dir(TemporyDir);
	if (dir.exists()) {
		dir.removeRecursively();
	}
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
void PKGBuilder::tempFileChunk(QString TemporyDir, QString FileName, QString FilePos)
{
	QString tfns = FilePos;
	tfns.replace("/", "_");
	tfns.replace(" ", "_");
	tfns.replace("<", "_");
	tfns.replace(">", "_");
	tfns.replace(".", "_");
	QString tempfilename = TemporyDir + "/" + tfns;
	QFile listfile(TemporyDir + "/.files"), tempfile(tempfilename), sourcefile(FileName);
	if (tempfile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
		if (sourcefile.open(QIODevice::ReadOnly)) {
			QDataStream tempstream(&tempfile);

			QByteArray sourcedata = sourcefile.readAll();

			QCryptographicHash* hash = new QCryptographicHash(QCryptographicHash::Md5);
			hash->addData(sourcedata);
			QByteArray md5data = hash->result();
			delete hash;

			QByteArray posdata = FilePos.toUtf8();

			RIFF_SIZE md5_size = md5data.size() + sizeof(RIFF_SIZE) + 4;
			RIFF_SIZE pos_size = posdata.size() + sizeof(RIFF_SIZE) + 4;

			RIFF_SIZE head_size = md5_size + pos_size + sizeof(RIFF_SIZE) + 4;

			RIFF_SIZE data_size = sourcedata.size() + sizeof(RIFF_SIZE) + 4;

			RIFF_SIZE wmd5_size = md5data.size();
			RIFF_SIZE wpos_size = posdata.size();
			RIFF_SIZE whead_size = md5_size + pos_size;
			RIFF_SIZE wdata_size = sourcedata.size();
			RIFF_SIZE wfile_size = head_size + data_size;

			char md5head[4] = { 'M','D','5','\0' };
			char poshead[4] = { 'P','S','P','T' };
			char fhhead[4] = { 'H','E','A','D' };
			char fdatahead[4] = { 'D','A','T','A' };
			char filehead[4] = { 'F','I','L','E' };

			tempstream.writeRawData((char*)filehead, 4);
			tempstream.writeRawData((char*)&wfile_size, sizeof(RIFF_SIZE));
			tempstream.writeRawData((char*)fhhead, 4);
			tempstream.writeRawData((char*)&whead_size, sizeof(RIFF_SIZE));
			tempstream.writeRawData((char*)md5head, 4);
			tempstream.writeRawData((char*)&wmd5_size, sizeof(RIFF_SIZE));
			tempstream.writeRawData((char*)md5data.constData(), md5data.size());
			tempstream.writeRawData((char*)poshead, 4);
			tempstream.writeRawData((char*)&wpos_size, sizeof(RIFF_SIZE));
			tempstream.writeRawData((char*)posdata.constData(), posdata.size());
			tempstream.writeRawData((char*)fdatahead, 4);
			tempstream.writeRawData((char*)&wdata_size, sizeof(RIFF_SIZE));
			tempstream.writeRawData((char*)sourcedata.constData(), sourcedata.size());
			sourcedata.clear();

			sourcefile.close();
		}
		tempfile.close();

		if (listfile.open(QIODevice::ReadWrite | QIODevice::Append)) {
			listfile.write(QString(tfns + "\n").toUtf8());
			listfile.close();
		}
	}
}

RIFF_SIZE PKGBuilder::getTempSize(QString TemporyDir)
{
	RIFF_SIZE count = 0;
	QFile listfile(TemporyDir + "/.files");
	if (listfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
		QString filelistdata = listfile.readAll();
		listfile.close();
		if (!filelistdata.isEmpty()) {
			QStringList TempList = filelistdata.split("\n", Qt::SkipEmptyParts);

			for (int i = 0; i < TempList.size(); i++) {
				QFile file(TemporyDir + "/" + TempList.at(i));
				count += file.size();
			}
		}

	}
	return count;
}

void PKGBuilder::linkTempFile(QDataStream* stream, QString TemporyDir)
{
	QFile listfile(TemporyDir + "/.files");
	if (listfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
		QString filelistdata = listfile.readAll();
		listfile.close();
		if (!filelistdata.isEmpty()) {
			QStringList TempList = filelistdata.split("\n", Qt::SkipEmptyParts);

			for (int i = 0; i < TempList.size(); i++) {
				QFile file(TemporyDir + "/" + TempList.at(i));
				if (file.open(QIODevice::ReadOnly)) {
					QByteArray tempdata = file.readAll();
					file.close();
					stream->writeRawData((char*)tempdata.constData(), tempdata.size());
					tempdata.clear();
				}
			}
		}

	}
}
/*
* ==========
* 'P''A''C''K'(size)
*	==========
*	'I''F''M''T'(size)
*	...
*	==========
*	==========
*	'L''I''S''T'(size)
*	...
*	==========
* ==========
*/
void PKGBuilder::Pack_D(PKGTask task, QString packfile)
{
	char packhead[4] = { 'P','A','C','K' };
	char listhead[4] = { 'L','I','S','T' };

	QFile file(packfile);
	if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
		QDataStream packstream(&file);

		QByteArray infordata = BuildInformationChunk(
			task.type,
			task.IMT_Ver,
			task.version,
			task.name,
			task.icon,
			task.author,
			task.about,
			task.EULA,
			task.wdate,
			task.wtime
		);

		QString tempdir = task.root + "/.IMT.build";
		prepareTempory(tempdir);

		for (int i = 0; i < task.files.size(); i++) {
			tempFileChunk(tempdir, task.files.at(i), getPosPath(task.type, task.files.at(i), task.root, task.name));
		}

		RIFF_SIZE wlist_size = getTempSize(tempdir);
		RIFF_SIZE list_size = wlist_size + sizeof(RIFF_SIZE) + 4;
		RIFF_SIZE infor_size = infordata.size();
		RIFF_SIZE wpack_size = infor_size + list_size;

		packstream.writeRawData((char*)packhead, 4);
		packstream.writeRawData((char*)&wpack_size, sizeof(RIFF_SIZE));
		packstream.writeRawData((char*)infordata.constData(), infordata.size());
		packstream.writeRawData((char*)listhead, 4);
		packstream.writeRawData((char*)&wlist_size, sizeof(RIFF_SIZE));
		linkTempFile(&packstream, tempdir);

		cleanTempory(tempdir);
		file.close();
	}
}
