#include <iostream>
#include <cmath>
#include <ctime>
#include <random>
#include "backEnd.h"
#include <conio.h>
#include <windows.h>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

// generates random prime number
int backEnd::genRand()
{
	srand(time(NULL));
	int smallPrimes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
	int bigPrimes[20] = {24091, 26951, 17851, 15137, 38609, 32003, 43399, 46549, 58379, 58871, 62207, 67139, 75967, 74717, 80863, 84089, 92557, 94447, 70753, 45827 };
	int num = 0;
	int i = 0;

	i = rand() % 20;
	num = bigPrimes[i];

	return num;
};

int backEnd::EuclidGCD(int a, int b) {
	if (b == 0)
		return a;
	return EuclidGCD(b, a % b);
}

int backEnd::power(int a, unsigned int n, int p)
{
	int res = 1;
	a = a % p;

	while (n > 0)
	{
		if (n & 1)
			res = (res * a) % p;

		n = n >> 1;
		a = (a * a) % p;
	}
	return res;
}


// encrypts the message
string backEnd::encrypt(string m, int e, int n)
{
	string c = "empty ";

	int s = m.length();
	int x = 0;
	int y = 0;

	for (int i = 0; i < s; i++)
	{
		m[i] = int(m[i]);

		x = pow(m[i], e);
		y = x % n;

		m[i] = y;
	}
	c = m;
	return m;
}


// decrypts the message
string backEnd::decrypt(string c, int n, int d)
{
	string m = "empty ";

	int s = c.length();
	int x = 0;
	int y = 0;

	for (int i = 0; i < s; i++)
	{
		c[i] = int(c[i]);

		x = pow(c[i], d);
		y = x % n;

		c[i] = y;
	}

	return c;
}

string backEnd::sign(int d, int n, string msg)
{
	int s = msg.length();
	int x = 0;
	int y = 0;

	for (int i = 0; i < s; i++)
	{
		msg[i] = int(msg[i]);

		x = pow(d, n);
		y = x % msg[i];

		msg[i] = y;
	}

	string sMsg = msg;
	return sMsg;
}

string backEnd::verifySig(string sMsg, int n, int e, string msg)
{
	int s = msg.length();
	int x = 0;
	int y = 0;

	for (int i = 0; i < s; i++)
	{
		sMsg[i] = int(msg[i]);

		x = pow(sMsg[i], e);
		y = x % n;

		sMsg[i] = y;
	}
	return sMsg;
}

// got this GUI ex online, changed it up a bit
void backEnd::GUI()
{
	int len = 0, x, y;
	time_t t;
	srand((unsigned)time(&t));

	cout << endl << "   ";
	for (x = 0; x < 6; x++)
	{
		for (y = 0; y < 114; y++)
		{
			SetConsoleTextAttribute(console, (rand() % 16) * 15);
			cout << " ";
		}
		SetConsoleTextAttribute(console, 0);
		cout << endl << "   ";
	}
	SetConsoleTextAttribute(console, 15);

	cout << "\n\t\t\t\t\t\t\tALGORITHMS\n";
	cout << "\t\t\t\t\t\t\t PROJECT 1\n";
	cout << "\t\t\t\t\t\t     Braeden, Josh, Ian";
}