#include <iostream>
#include <cmath>
#include "backEnd.cpp"

using namespace std;

int main()
{
	// variables
	int p, q, n;

	// prompts user for message to encrypt
	string message;
	cout << "Enter the message you want to encrypt: ";
	cin >> message;

	// generates prime number p & q
	p = genRand();
	q = genRand();

	//calculates n
	n = p * q;

	// tells user the stuff
	cout << "q: " << p << "\nq: " << q << "\nn: " << n;

	return 0;
}