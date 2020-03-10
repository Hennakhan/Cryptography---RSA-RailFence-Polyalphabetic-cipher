//Heena Khan
//Project 2

// PolyalphabeticCipher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>


using namespace std;

char M1(char, int);
char M2(char, int);
char M3(char, int);


int main()
{
	char c;
	int mode;
	int countMeth = 0;
	cout << "FOR ENCRYPTION PRESS:  1"<<endl;
	cout << "FOR DECRYPTION PRESS:  2" << endl;
	cin >> mode;
	cout << endl;
	if (mode != 1 && mode != 2)
	{
		cout << "Improper command! Program aborted"<<endl;
		exit(2);
	}
	else if (mode == 1)
	{
		cout << "ENCRYPTED TEXT:  " << endl;
	}
	else
	{
		cout << "DECRYPTED ORIGINAL TEXT:  " << endl;
	}
	
		vector<int> method;
		char meth1, meth2, meth3;
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

		char infl_char;
		while (filein >> noskipws >> infl_char) {
			text.push_back(infl_char);
		}
			/*for (std::string line; getline(filein, line); )
			{
				for (int i = 0; i < line.length(); i++)
				{
					text.push_back(line[i]);
				}

			}*/
			filein.close();

			//vector<int> method stores the cycle for  M2 M3 M2 M1 M3
			for (int i = 0; i < text.size(); i = i + 5)
			{
				if (i < text.size())
					method.push_back(2);
				if (i + 1 < text.size())
					method.push_back(3);
				if (i + 2 < text.size())
					method.push_back(2);
				if (i + 3 < text.size())
					method.push_back(1);
				if (i + 4 < text.size())
					method.push_back(3);

			}

			
			//Encrypt and write each character at a time to the output file
			for (int i = 0; i < text.size(); i++)
			{
				 c = text[i];
				char check = int(c);

				//checking if the character is any character other than text
				
				if ((check >= 97 && check <= 122) || (check >= 65 && check <= 90))
				{
					if (method[countMeth] == 1)
					{

							meth1 = M1(c, mode);    // calls method M1 to encrypt text
							cout << meth1;    //display encrypted value on cmd
							outfile << meth1; //write encrypted value to file
							

					}
					if (method[countMeth] == 2)
					{
						
							meth2 = M2(c, mode);  // calls method M2 to encrypt text
							cout << meth2;
							outfile << meth2;
							
						
					}
					if (method[countMeth] == 3) //// calls method M3 to encrypt text
					{
						
							meth3 = M3(c, mode);
							cout << meth3;
							outfile << meth3;
							
						
						
					}
					countMeth++;
				}
				else
				{
					cout << c;
					outfile << c;
				}

			}
		outfile.close();
	 
		cout << '\n'<<'\n'<< "Note: Encrypted/Decrypted data are also stored in their respective text files" << endl;
	return 0;
}



char M1(char c, int mode)
{			
	char result = '1';
	if (mode == 1)
	{
		if(isupper(c))
			
		result = char(int((26 - 3 + c - 65) % 26 + 65));
		else
	
		result = char(int((26 - 3 + c - 97) % 26 + 97));
	}
	if (mode == 2)
	{
		if (isupper(c))
			result = char(int((c + 3) - 65) % 26 + 65);
		
		else
			result = char(int((c + 3) - 97) % 26 + 97);
		
		
	}
	
	return result;
}

char M3(char c, int mode)
{
	char result = '1';
	if (mode == 1)
	{	
		if(isupper(c))
			result = char(int(c + 5 - 65)%26 + 65);
		else
			result = char(int(c + 5 - 97) % 26 +97);

	}
	if (mode == 2)
	{	
		if (isupper(c))
			result = char(int((26 - 5 + c - 65) % 26 + 65));
		else
			result = char(int((26 - 5 + c - 97)%26 +97));
		
	}
	return result;
}

char M2(char c, int mode)
{
	char result = '1';
	if (mode == 1)
	{
		if (c == 'a' || c == 'A')
			result = 'D';
		else if (c == 'b' || c == 'B')
			result = 'K';
		else if (c == 'c' || c == 'C')
			result = 'V';
		else if (c == 'd' || c == 'D')
			result = 'Q';
		else if (c == 'e' || c == 'E')
			result = 'F';
		else if (c == 'f' || c == 'F')
			result = 'I';
		else if (c == 'g' || c == 'G')
			result = 'B';
		else if (c == 'h' || c == 'H')
			result = 'J';
		else if (c == 'i' || c == 'I')
			result = 'W';
		else if (c == 'j' || c == 'J')
			result = 'P';
		else if (c == 'k' || c == 'K')
			result = 'E';
		else if (c == 'l' || c == 'L')
			result = 'S';
		else if (c == 'm' || c == 'M')
			result = 'C';
		else if (c == 'n' || c == 'N')
			result = 'X';
		else if (c == 'o' || c == 'O')
			result = 'H';
		else if (c == 'p' || c == 'P')
			result = 'T';
		else if (c == 'q' || c == 'Q')
			result = 'M';
		else if (c == 'r' || c == 'R')
			result = 'Y';
		else if (c == 's' || c == 'S')
			result = 'A';
		else if (c == 't' || c == 'T')
			result = 'U';
		else if (c == 'u' || c == 'U')
			result = 'O';
		else if (c == 'v' || c == 'V')
			result = 'L';
		else if (c == 'w' || c == 'W')
			result = 'R';
		else if (c == 'x' || c == 'X')
			result = 'G';
		else if (c == 'y' || c == 'Y')
			result = 'Z';
		else if (c == 'z' || c == 'Z')
			result = 'N';
	}
	if (mode == 2)
	{
		if (c == 'd' || c == 'D')
			result = 'a';
		else if (c == 'k' || c == 'K')
			result = 'b';
		else if (c == 'v' || c == 'V')
			result = 'c';
		else if (c == 'q' || c == 'Q')
			result = 'd';
		else if (c == 'f' || c == 'F')
			result = 'e';
		else if (c == 'i' || c == 'I')
			result = 'f';
		else if (c == 'b' || c == 'B')
			result = 'g';
		else if (c == 'j' || c == 'J')
			result = 'h';
		else if (c == 'w' || c == 'W')
			result = 'i';
		else if (c == 'p' || c == 'P')
			result = 'j';
		else if (c == 'e' || c == 'E')
			result = 'k';
		else if (c == 's' || c == 'S')
			result = 'l';
		else if (c == 'c' || c == 'C')
			result = 'm';
		else if (c == 'x' || c == 'X')
			result = 'n';
		else if (c == 'h' || c == 'H')
			result = 'o';
		else if (c == 't' || c == 'T')
			result = 'p';
		else if (c == 'm' || c == 'M')
			result = 'q';
		else if (c == 'y' || c == 'Y')
			result = 'r';
		else if (c == 'a' || c == 'A')
			result = 's';
		else if (c == 'u' || c == 'U')
			result = 't';
		else if (c == 'o' || c == 'O')
			result = 'u';
		else if (c == 'l' || c == 'L')
			result = 'v';
		else if (c == 'r' || c == 'R')
			result = 'w';
		else if (c == 'g' || c == 'G')
			result = 'x';
		else if (c == 'z' || c == 'Z')
			result = 'y';
		else if (c == 'n' || c == 'N')
			result = 'z';
	}

return result;
}


