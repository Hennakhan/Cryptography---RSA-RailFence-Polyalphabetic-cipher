//Heena Khan
//Railfence Projet 2

#include "EncryptDecrypt.h"


EncryptDecrypt::EncryptDecrypt()
{
}

vector<char> EncryptDecrypt::encryption(vector<char> message, int depth)
{
	int **dynamicArray = 0;
	int len = message.size();
	dynamicArray = new int *[depth];

	//memory allocated for  elements of each column.
	for (int i = 0; i < depth; i++)
		dynamicArray[i] = new int[len];

	// Fill array wid null value
	for (int i = 0; i < depth; i++)
		for (int j = 0; j < len; j++)
			dynamicArray[i][j] = '\0';

	bool direction_down = false;
	int row = 0, col = 0;

	for (int i = 0; i < len; i++)
	{
		
		// change the direction if we've reached the top or bottom rail 
		if (row == 0 || row == depth - 1)
			direction_down = !direction_down;

		// fill the matrix with alphabet 
		dynamicArray[row][col++] = message[i];

		// find the next row
		direction_down ? row++ : row--;
	}

	//constructing ciphertext using the rail matrix 
	vector<char> result;
	for (int i = 0; i < depth; i++)
		for (int j = 0; j < len; j++)
			if (dynamicArray[i][j] != '\0')
				result.push_back(dynamicArray[i][j]);

	//free the allocated memory
	for (int i = 0; i < depth; i++)
		delete[] dynamicArray[i];
	delete[] dynamicArray;

	return result;
}

vector<char> EncryptDecrypt::decryption(vector<char> ciphertext, int depth)
{
	int **dynamicArray = 0;
	int len = ciphertext.size();
	dynamicArray = new int *[depth];

	//memory allocated for  elements of each column.

	for (int i = 0; i < depth; i++)
		dynamicArray[i] = new int[len];

	// spaces from blank ones 
	for (int i = 0; i < depth; i++)
		for (int j = 0; j < len; j++)
			dynamicArray[i][j] = '\0';
	for (int i = 0; i < depth; i++)
		for (int j = 0; j < len; j++)
			dynamicArray[i][j] = '\0';

	// to find the direction 
	bool direction_down;

	int row = 0, col = 0;

	// mark the places with '*' 
	for (int i = 0; i < len; i++)
	{
		// check the direction of flow 
		if (row == 0)
			direction_down = true;
		if (row == depth - 1)
			direction_down = false;

		// place the marker 
		dynamicArray[row][col++] = '*';

		// find the next row 
		direction_down ? row++ : row--;
	}

	// Construct matrix 
	int index = 0;
	for (int i = 0; i < depth; i++)
		for (int j = 0; j < len; j++)
			if (dynamicArray[i][j] == '*' && index < len)
				dynamicArray[i][j] = ciphertext[index++];


	//read matrix in zigzag
	vector<char> result;

	row = 0, col = 0;
	for (int i = 0; i < len; i++)
	{
		// check the direction of flow 
		if (row == 0)
			direction_down = true;
		if (row == depth - 1)
			direction_down = false;

		// place the marker 
		if (dynamicArray[row][col] != '*')
			result.push_back(dynamicArray[row][col++]);

		// find the next row using direction flag 
		direction_down ? row++ : row--;
	}

	//free the allocated memory

	for (int i = 0; i < depth; i++)
		delete[] dynamicArray[i];
	delete[] dynamicArray;

	return result;
}



