#pragma once
#include <iostream>
#include <string>
#include<fstream>
#include <vector>

using namespace std;


class FileHandler
{
public:
	FileHandler();
	~FileHandler();

	vector<int> readFile(string inf);

	vector<long long int> readCipherText(string cipherFileName);

	void writeCipherText(vector<long long int> encryptedText, string outf);

	void writeDecryptedText(vector<int> decryptedText, string outf);

};

