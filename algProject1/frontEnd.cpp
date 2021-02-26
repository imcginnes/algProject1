#include <iostream>
#include <cmath>
#include <ctime>
#include "backEnd.h"

using namespace std;

int main()
{

	// variables
	double p, q, n, e, t, count;
	double message;
	backEnd obj1, obj2;

	// prompts user for message to encrypt
	cout << "Enter the message you want to encrypt (integer): ";
	cin >> message;

	// generates prime number p & q
	//p = obj1.genRand();
	//q = obj2.genRand();

	// genRand is broke so settled on these
	p = 19;
	q = 37;

	//calculates n & q
	n = p * q;
	t = (p - 1)*(q - 1);
	e = 4;

	obj1.EuclidGCD(e, t);

	double d;
	double k2 = 2;

	d = (1 + (k2 * t)) / e;
	double c = pow(message, e);
	double decryptedMessage = pow(c, d);
	c = fmod(c, n);
	decryptedMessage = fmod(decryptedMessage, n);

	// tells user the stuff
	cout << "\nMessage: " << message << "\np: " << p << "\nq: " << q << "\nn: " << n << "\nt: " << t << "\ne: " << e << "\nd: " << d << "\nc: " << c << "\nMessage: " << decryptedMessage << endl;

	return 0;
}