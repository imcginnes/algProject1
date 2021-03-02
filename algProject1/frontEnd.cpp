// Algorithms
// Project 1
// Braeden Myers, Ian McGinnes, Joshua Barber

#include <conio.h>
#include <iostream>
#include <cmath>
#include <ctime>
#include "backEnd.h"

using namespace std;

int main()
{
	// variables
	double p, q, n, e, phi, count;
	string message;
	bool prompt1, repeat;
	backEnd backEnd;

	// GUI call
	backEnd.GUI();
	
	// asks user if he/she is general public user, then validates
	cout << "\n\n   Are you a general public user, or do you own the keys? (1 for yes/0 for no): ";
	cin >> prompt1;

	//if(prompt1 == 1)
		do {
			// prompts user for message to encrypt and generates primes for p and q
			p = backEnd.genRand();
			cout << "\n\n   Enter the message you want to encrypt: ";
			cin >> message;
			q = backEnd.genRand();

			// calculates n, t, & e
			n = p * q;
			phi = (p - 1) * (q - 1);
			e = 3;

			// find e
			double track;
			while (e < phi) {
				track = backEnd.EuclidGCD(e, phi);
				if (track == 1)
					break;
				else
					e++;
			}

			// encrypt message
			string c = backEnd.encrypt(message, e, n);

			// decypt message
			double k2 = 2;
			double d = -1;
			d = (1 + (k2 * phi)) / e;
			string decryptedMessage = backEnd.decrypt(c, n, d);

			// tells user the stuff
			cout << "\n   Message: " << message;
			cout << "\n   p: " << p;
			cout << "\n   q: " << q;
			cout << "\n   n: " << n;
			cout << "\n   phi: " << phi;
			cout << "\n   e: " << e;
			cout << "\n   d: " << d;
			cout << "\n   c: " << c;
			cout << "\n   Message: " << message << endl;

			// asks if user wants to repeat the program
			cout << "\n\n   Would you like to run this program again? (1 for yes/0 for no): ";
			cin >> repeat;
		} while (repeat == 1);

	return 0;
}