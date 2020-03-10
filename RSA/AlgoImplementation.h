
#ifndef AlgoImplementation_H 
#define AlgoImplementation_H

#include <vector>
using namespace std;
class AlgoImplementation
{

private:

	bool isPPrime;
	bool isQPrime;

	void isPrime();
	int totient();
	int calcModulus();
	long int genE(long int phi);
	int gcd(int, int);

public:
	double c;
	long int e, phi, n;
	int p, q;
	long int d;
	AlgoImplementation();
	void publicKey();
	void privateKey();
	vector<long long int> encryptMsg(vector<int>, long long int, long long int);
	vector<int> decryptMsg(vector<long long int>, long long int, long long int);
};

#endif 

