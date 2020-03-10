//Heena Khan
//Proj1-RSA

//Class for RSA algorithm implementation 
//Generating Key
//Encrypting
//Decrypting


#include "AlgoImplementation.h"
#include <iostream>
#include <algorithm>
#include <math.h>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
using namespace std;

AlgoImplementation::AlgoImplementation()
{

}

//Generating Public key: Calling function generating p,q,phi,n,e
void AlgoImplementation::publicKey()
{
	isPrime();
	n = calcModulus();
	phi = totient();
	e = genE(phi);
	cout << "n = " << n << endl;
	cout << "phi = " << phi << endl;
	cout << "e = " << e << endl;
	cout << "The public key [e,n] = [" << e << "," << n << "]" << endl;

}


//to generate random prime number p and q and to make sure they are not same
void AlgoImplementation::isPrime()
{
	srand(time(0));  // Initialize random number generator
	isPPrime = false;
	isQPrime = false;

	while (!isPPrime)
	{
		int flag = 0;
		//random p
		p = rand() % (1000 - 500) + 500;

		int m = p / 2;
		for (int i = 2; i <= m; i++)
		{
			if (p % i == 0)
			{

				flag = 1;
				break;
			}
		}
		if (flag == 0 && p != 1)
		{
			cout << "p = " << p << endl;
			isPPrime = true;
		}

	}
	while (!isQPrime)
	{
		int flag2 = 0;
		//random q
		q = rand() % (1000 - 500) + 500;
		int m = q / 2;
		for (int i = 2; i <= m; i++)
		{
			if (q % i == 0)
			{

				flag2 = 1;
				break;
			}
		}
		if (flag2 == 0 && q != p && q != 1)
		{
			cout << "q = " << q << endl;
			isQPrime = true;
		}

	}


}

//Generating phi
int AlgoImplementation::totient()
{
	return (p - 1)*(q - 1);

}

//Generating n
int AlgoImplementation::calcModulus()
{
	return  p * q;

}

//generating e
long int AlgoImplementation::genE(long int phi)
{
	bool isCoPrime = false;

	while (!isCoPrime)
	{
		//randomly selecting e such that e is 16 bit 
	//	e = rand() % ((phi - 32768) + 1) + 32768;
		e = rand() % ((phi - 100000) + 1) + 100000;
		if (gcd(e, phi) == 1)
		{
			isCoPrime = true;
		}
	}
	return e;
}

//Coprime check for e and phi
int AlgoImplementation::gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

//Genearating d
void AlgoImplementation::privateKey()
{
	long long int k = 1;
	bool isnotdone = true;

	while (isnotdone && k > 0) {
		k = k + phi;

		if ( (k % e == 0) && ((k/e) > 32700) )
			isnotdone = false;
	}
	d = (k / e);

	cout << "The private key [d,n] = [" << d << "," << n << "]" << endl;

}

//Encrypting 
vector<long long int> AlgoImplementation::encryptMsg(vector<int> msg, long long int e, long long int n)
{

	vector <long long int> ciph;
	int etemp;
	int pt;

	for (auto x : msg) {

		etemp = e;
		pt = x;

		long long int value = 1;
		while (etemp > 0)
		{
			value *= pt;
			value %= n;
			etemp--;
		}
		ciph.push_back(value);
	}


	cout << "\nTHE ENCRYPTED MESSAGE IS = " << endl;
	for (auto x : ciph)
	{
		cout << x << " ";
	}
	cout << endl;
	return ciph;
}

//Decrypting
vector<int> AlgoImplementation::decryptMsg(vector<long long int> mssg, long long int d, long long int n)
{
	vector <int> pt;

	int dtemp;
	long long int value;

	for (auto x : mssg) {
		dtemp = d;
		value = 1;
		while (dtemp > 0)
		{

			value *= x;
			value %= n;
			dtemp--;
		}


		//value = value + 96;

		pt.push_back(value);
	}
	cout << "THE DECRYPTED ORIGINAL TEXT IS = " << endl;
	for (char x : pt)
	{
		cout << x;
	}
	cout << endl;

	return pt;
}
