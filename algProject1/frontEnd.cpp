#include <iostream>
#include <cmath>
#include "backEnd.cpp"

using namespace std;

int main()
{
	// variables
	int p, q, n, num1, num2;

	// prompts user for message to encrypt
	string message;
	cout << "Enter the message you want to encrypt: ";
	cin >> message;

	// list of first several prime numbers
	int PrimeNumbers[] = {1,2,3,5,7,11,13,17,19,23,29,31,37};

	// generates p based on user input
	cout << "Enter a number between 0 and 12: ";
	do {
		cin >> num1;
	} while (num1 < 0 || num1 > 12);
	p = PrimeNumbers[num1];

	// generates q based on user input
	cout << "Enter another number (different from the first) between 0 and 11: ";
	do {
		cin >> num2;
	} while (num2 < 0 || num2 > 12 || num2 == num1);
	q = PrimeNumbers[num2];

	//calculates n
	n = p * q;

	// tells user the stuff
	cout << "q: " << p << "\nq: " << q << "\nn: " << n;
	return 0;
}