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
	int p, q, n, e, t, count;
	string message;
	string prompt1;
	backEnd backEnd;
	string c1;

	// GUI call
	backEnd.GUI();

	/*
	// asks user if he/she is general public user, then validates
	cout << "\n\n   Are you a general public user, or do you own the keys? (Y/N): ";
	cin >> prompt1;
	if (prompt1 == "Y" || "y")
		cout << "   yes";
	else
		cout << "   no";*/

	p = backEnd.genRand();
	// prompts user for message to encrypt
	cout << "\n\n   Enter the message you want to encrypt (integer): ";
	cin >> message;
	q = backEnd.genRand();


	// calculates n, t, & e
	n = p * q;
	t = (p - 1) * (q - 1);
	e = 1;
	e = backEnd.EuclidGCD(e, n);

	// encrypt message
	string c = backEnd.encrypt(message, e, n);
	cout << c;

	// decypt message
	double k2 = 2;
	double d = (1 + (k2 * t)) / e;
	string decryptedMessage = backEnd.decrypt(c, n, d);

	// tells user the stuff
	cout << "\n   Message: " << message;
	cout << "\n   p: " << p;
	cout << "\n   q: " << q;
	cout << "\n   n: " << n;
	cout << "\n   t: " << t;
	cout << "\n   e: " << e;
	cout << "\n   d: " << d;
	cout << "\n   c: " << c1;
	cout << "\n   Message: " << decryptedMessage << endl;
}