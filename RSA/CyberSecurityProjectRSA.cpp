//Heena Khan
//Proj1 - RSA

// CyberSecurityProjectRSA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "AlgoImplementation.h"
#include "FileHandler.h"
#include <fstream>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <vector>
using namespace std;
int userOptionSelection();
vector<long long int> askPublicKeyForEncrypt();
vector<long long int> askPrivateKeyForDecrypt();
void option1Process(AlgoImplementation a);
void option2Process(AlgoImplementation a);
void option3Process(AlgoImplementation a, vector<long long int> publicKey);
void option4Process(AlgoImplementation a, vector<long long int> privateKey);

int main()
{
	//ask what user wants to do
	int option = userOptionSelection();
	cout << "You have selected option " << option << endl;

	if (option == 0) {
		cout << "Exiting Application. " << option << endl << "Byee!" << endl;


		return 0;
	}

	if (!(option >= 1 && option <= 4)) {
		cout << "Wrong option selected - " << option << endl << "Byee!" << endl;


		return 0;
	}
	//**
	//create instance of algoImplementation so that we can call it's methods according to user options
	AlgoImplementation a;

	//ask for public key or private key if option 3 or 4 has been selected by user. Do processing as per the option
	if (option == 1) {
		option1Process(a);
	}
	else if (option == 2) {
		option2Process(a);
	}
	else if (option == 3) {
		vector<long long int> publicKey = askPublicKeyForEncrypt();
		option3Process(a, publicKey);
	}
	else if (option == 4) {
		vector<long long int> privateKey = askPrivateKeyForDecrypt();
		option4Process(a, privateKey);
	}
	//**
	return 0;
}

int userOptionSelection() {

	cout << "Select from below options - " << endl;
	cout << "**************************************Options****************************************" << endl;
	cout << "1. Type 1 to generate Public and Private Keys. OutPut of this step -  " << endl;
	cout << "   (a). Key.txt - This file will be written with public and private keys. " << endl;
	cout << endl;
	cout << "2. Type 2 to generate keys and encrypt text using the generated keys. You will " << endl;
	cout << "   have to write you text in plaintext.txt file before doing this. OutPut of this  " << endl;
	cout << "   step would be two files - " << endl;
	cout << "   (a). cipherText.txt - This file will be written with cipher text. " << endl;
	cout << "   (b). Key.txt        - This file will be written with public and private keys." << endl;
	cout << endl;
	cout << "3. Type 3 to encrypt text. You will have provide public key for encryption. " << endl;
	cout << "   OutPut of this step -  " << endl;
	cout << "   (a). cipherText.txt - This file will be written with cipher text. " << endl;
	cout << endl;
	cout << "4. Type 4 to decrypt. You will have to provide private key for decryption." << endl;
	cout << "   OutPut of this step -  " << endl;
	cout << "   (a). decrypt.txt - This file will be written with cipher text. " << endl;
	cout << endl;
	cout << "5. Type 0 to exit." << endl;
	cout << "************************************************************************************" << endl;
	cout << endl;
	cout << "Please type your option " << endl;
	int option;
	cin >> option;

	return option;

}

vector<long long int> askPublicKeyForEncrypt()
{
	vector<long long int> publicKey;

	long long int eIn, nIn;
	int typeKey;
	cout << "What key are you using to encrypt the file ?" << endl;
	cout << "Press 1 for Private Key [d, n] " << endl;
	cout << "Press 2 for Public Key [e, n] " << endl;
	cin >> typeKey;
	if (typeKey == 2)
	{
		cout << endl << "Please type public key e - " << endl;
		cin >> eIn;
		
	}
	else if (typeKey == 1)
	{
		cout << endl << "Please type private key d - " << endl;
		cin >> eIn;
	
	}
	else
	{
		cout << "Wrong option selected - " <<endl << "Byee!" << endl;
		exit (2);
	}
	cout << endl;
	cout << "Please type public key n - " << endl;
	cin >> nIn;

	publicKey.push_back(eIn);
	publicKey.push_back(nIn);

	return publicKey;
}

vector<long long int> askPrivateKeyForDecrypt()
{
	vector<long long int> privateKey;

	long int dIn, nIn;
	int typeKey;
	cout << "What key are you using to decrypt the file ?" << endl;
	cout << "Press 1 for Private Key [d, n]" << endl;
	cout << "Press 2 for Public Key [e, n] " << endl;
	cin >> typeKey;
	if (typeKey == 1)
	{
		cout << endl << "Please type private key d - " << endl;
		cin >> dIn;
	}
	else if (typeKey == 2)
	{
		cout << endl << "Please type public key e - " << endl;
		cin >> dIn;
	}
	else
	{
		cout << "Wrong option selected - " << endl << "Byee!" << endl;
		exit(2);
	}
	cout << endl;

	cout << "Please type private key n - " << endl;
	cin >> nIn;

	privateKey.push_back(dIn);
	privateKey.push_back(nIn);

	return privateKey;
}

void option1Process(AlgoImplementation a)
{
	//generate both keys
	a.publicKey();
	a.privateKey();

	//Write keys to a file
	ofstream keyFile;
	keyFile.open("Key.txt", std::ofstream::out | std::ofstream::app);
	keyFile << "Public Key [" << a.e << ", " << a.n << "]";
	keyFile << " Private Key [" << a.d << ", " << a.n << "]" << '\n';
	keyFile.close();
}

void option2Process(AlgoImplementation a)
{
	//generate both keys
	a.publicKey();
	a.privateKey();

	//Write keys to a file
	ofstream keyFile;
	keyFile.open("Key.txt", std::ofstream::out | std::ofstream::app);
	keyFile << "Public Key [" << a.e << ", " << a.n << "]";
	keyFile << " Private Key [" << a.d << ", " << a.n << "]" << '\n';
	keyFile.close();

	//create instance for FileHandler to plainText file and to write to cipherText file
	FileHandler fh;

	//read plaintext file
	vector<int> msg = fh.readFile("plaintext.txt");

	//display plain text 
	cout << endl << "THE PLAIN TEXT IS = "<<endl;
	for (char x : msg)
		cout << x;
	cout << endl;

	if (!msg.empty()) {
		//Encrypt the value in vector 
		vector<long long int> cipher = a.encryptMsg(msg, a.e, a.n);

		//write cypherText.txt file
		fh.writeCipherText(cipher, "cipherText.txt");
	}
}

void option3Process(AlgoImplementation a, vector<long long int> publicKey)
{
	//set private keys of the AlgoImplementation object by the keys provided by user
	a.e = publicKey[0];
	a.n = publicKey[1];

	//create instance for FileHandler to plainText file and to write to cipherText file
	FileHandler fh;

	//read plaintext file
	vector<int> msg = fh.readFile("plaintext.txt");

	//display plain text 
	cout << endl << "THE PLAIN TEXT IS = "<<endl;
	for (char x : msg)
		cout << x;
	cout << endl;

	if (!msg.empty())
	{
		//Encrypt the value in vector 
		vector<long long int> cipher = a.encryptMsg(msg, a.e, a.n);

		//write cypherText.txt file
		fh.writeCipherText(cipher, "cipherText.txt");

	}

}

void option4Process(AlgoImplementation a, vector<long long int> privateKey)
{
	//set private keys of the AlgoImplementation object by the keys provided by user
	a.d = privateKey[0];
	a.n = privateKey[1];

	//create instance for FileHandler to plainText file and to write to cipherText file
	FileHandler fh;

	//read plaintext file
	vector<long long int> cipher = fh.readCipherText("cipherText.txt");

	if (!cipher.empty()) {
		//decrypt the cipher
		vector<int> plText = a.decryptMsg(cipher, a.d, a.n);

		//Write decrypted text to output file
		fh.writeDecryptedText(plText, "decrypt.txt");
	}
}
