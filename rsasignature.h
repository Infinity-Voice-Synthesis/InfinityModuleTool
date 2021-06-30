#ifndef RSASIGNATURE_H
#define RSASIGNATURE_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/bn.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include "openssl/ssl.h"
#include "openssl/err.h"
#include <QString>
#include <QDebug>

class RSASignature
{
public:
	RSASignature();
	static RSA* createRSA(unsigned char* key, int publi);
	static int public_encrypt(unsigned char* data, int data_len, unsigned char* key, unsigned char* encrypted);
	static int private_decrypt(unsigned char* enc_data, int data_len, unsigned char* key, unsigned char* decrypted);
	static int private_encrypt(unsigned char* data, int data_len, unsigned char* key, unsigned char* encrypted);
	static int public_decrypt(unsigned char* enc_data, int data_len, unsigned char* key, unsigned char* decrypted);
	static int public_encrypt(QString& data, QString& keystr, QString& encrypted);
	static int private_decrypt(QString& data, QString& keystr, QString& decrypted);
	static int private_encrypt(QString& data, QString& keystr, QString& encrypted);
	static int public_decrypt(QString& data, QString& keystr, QString& decrypted);
private:
	constexpr static int padding = RSA_PKCS1_PADDING;
};

#endif // RSASIGNATURE_H
