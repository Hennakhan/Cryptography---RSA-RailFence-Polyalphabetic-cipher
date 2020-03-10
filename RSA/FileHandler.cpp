//Heena Khan
//Proj1 - RSA


//This class is used to read and write to a file. Generate error message when file not found.
//Reading file and storing each character into a vector one by one.


#include "FileHandler.h"
#include<iostream> 
#include<fstream>
#include <string>
#include <vector>

using namespace std;


FileHandler::FileHandler()
{
}


FileHandler::~FileHandler()
{
}

vector<int> FileHandler::readFile(string filename)
{
	ifstream file(filename);

	vector<int> ptVector;

	if (!file) {
		cout << "No file to read!!!";
		return ptVector;
	}

	char ascii;
	//read all charcter with space and line change
	while (file >> noskipws >> ascii) {
		ptVector.push_back(ascii);
	}

	return ptVector;
}

vector<long long int> FileHandler::readCipherText(string cipherFileName)
{
	vector<long long int> encryptedText;

	ifstream file(cipherFileName);

	if (!file) {
		cout << "No file to read!!!";
		return encryptedText;
	}

	int code;

	while (file >> code) {
		encryptedText.push_back(code);
	}


	return encryptedText;
}

void FileHandler::writeCipherText(vector<long long int> encryptedText, string outputFileName)
{

	ofstream outFl(outputFileName);

	if (encryptedText.size() == 0) return;

	for (int x : encryptedText) {
		outFl << x << " ";
	}
}

void FileHandler::writeDecryptedText(vector<int> decryptedText, string outFileName)
{

	ofstream outFl(outFileName);

	if (decryptedText.size() == 0) return;

	for (char x : decryptedText) {
		outFl << x;
	}

}

