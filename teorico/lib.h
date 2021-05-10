#pragma once
#ifndef _LIB_H
#define _LIB_H
#include <iostream>
#include <iomanip>
#include<cryptopp/modes.h>
#include<cryptopp/aes.h>
#include<cryptopp/filters.h>
#include<cstdlib>
#include<time.h>
#include<cryptopp/rsa.h>
#include<string>
#include<ostream>
#include<fstream>
#define MAXNUM 100000000
class aes {
public:
	aes(int);
	aes(void);
	std::string  aesencrypt(std::string);
	std::string aesdecrypt(std::string);
private:
	CryptoPP::byte key[CryptoPP::AES::DEFAULT_KEYLENGTH], iv[CryptoPP::AES::BLOCKSIZE];
};
int randprimos(void);//genera numeros primos random
#endif //_LIB_H
