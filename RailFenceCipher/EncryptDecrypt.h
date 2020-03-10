#ifndef ENCRYPTDECRYPT_H
#define ENCRYPTDECRYPT_H

#include <vector>
#include <iostream>

using namespace std;
class EncryptDecrypt
{
public:
	EncryptDecrypt();
	vector<char> encryption(vector<char>, int);
	vector<char> decryption(vector<char>, int);
	
};

#endif