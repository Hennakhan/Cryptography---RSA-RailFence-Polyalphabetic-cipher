// RailFenceCipher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "EncryptDecrypt.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
	char c;
	int mode;
	int depth;
	cout << "FOR ENCRYPTION PRESS:  1" << endl;
	cout << "FOR DECRYPTION PRESS:  2" << endl;
	cin >> mode;
	cout << endl;

	if (mode != 1 && mode != 2)
	{
		cout << "Improper command! Program aborted" << endl;
		exit(2);
	}
	else if (mode == 1)
	{
		cout << "Please enter the depth of Railfence for Encryption: " << endl;
		cin >> depth;
		cout << endl;
		cout << "ENCRYPTED TEXT:  " << endl;
	}
	else
	{
		cout << "Please enter the depth of Railfence for Decryption: " << endl;
		cin >> depth;
		cout << endl;
		cout << "DECRYPTED ORIGINAL TEXT:  " << endl;
	}
	vector<char> text;
	ofstream outfile;
	ifstream filein;
	//file to read and write while encryption
	if (mode == 1)
	{
		filein.open("plaintext.txt");
		outfile.open("ciphertext.txt");
	}
	else //file to read and write while decryption
	{
		filein.open("ciphertext.txt");
		outfile.open("decrypttext.txt");
	}

	if (!filein)
	{
		fputs("error opening file\n", stderr);
		exit(2);
	}
	char infl_char;
	while (filein >> noskipws >> infl_char) {
		if (infl_char == '\0')
		{
			infl_char = ' ';
		}
		text.push_back(infl_char);
	}
	
	filein.close();
	vector<char> cipher;
	EncryptDecrypt ed;
	if (mode == 1)
	{
		cipher = ed.encryption(text, depth);
	}
	else
	{
		cipher = ed.decryption(text, depth);
	}
	for (int i = 0; i < cipher.size(); i++)
	{
		cout << cipher[i];
		outfile << cipher[i];
	}

	cout << '\n' << '\n' << "Note: Encrypted/Decrypted data are also stored in their respective text files" << endl;
	outfile.close();

}

