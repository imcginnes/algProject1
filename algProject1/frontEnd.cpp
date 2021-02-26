#include<iostream>
#include<cmath>
#include<string>
#include <cstring>
#include <ctime>
#include "backEnd.h"


using namespace std;

int main()
{
	// variables
	int p, q, n, e;
	string message;
	backEnd obj1, obj2;

	// prompts user for message to encrypt
	cout << "Enter the message you want to encrypt: ";
	cin >> message;

	// generates prime number p & q
	//p = obj1.genRand();
	//q = obj2.genRand();
	p = 7;
	q = 13;

	//calculates n & e
	n = p * q;
	e = (p - 1) * (q - 1);

	// tells user the stuff
	cout << "p: " << p << "\nq: " << q << "\nn: " << n << "\ne: " << e;

	return 0;
}