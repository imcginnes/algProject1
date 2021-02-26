#include <iostream>
#include <cmath>
#include <ctime>
#include <random>
#include "backEnd.h"

using namespace std;

int backEnd::genRand()
{
	srand(time(NULL));
	int num = 0;

	do {
		num = rand() & 100;
	} while (isPrime(num, 3) == false);

	return num;
};

int backEnd::EuclidGCD(int a, int b) {
	if (b == 0)
		return a;
	return EuclidGCD(b, a % b);
}

int backEnd::power(int a, unsigned int n, int p)
{
	int res = 1;      // Initialize result
	a = a % p;  // Update 'a' if 'a' >= p

	while (n > 0)
	{
		// If n is odd, multiply 'a' with result
		if (n & 1)
			res = (res * a) % p;

		// n must be even now
		n = n >> 1; // n = n/2
		a = (a * a) % p;
	}
	return res;
}

bool backEnd::isPrime(unsigned int n, int k)
{
	// Corner cases
	if (n <= 1 || n == 4)  return false;
	if (n <= 3) return true;

	// Try k times
	while (k > 0)
	{
		// Pick a random number in [2..n-2]        
		// Above corner cases make sure that n > 4
		int a = 2 + rand() % (n - 4);

		// Checking if a and n are co-prime
		if (EuclidGCD(n, a) != 1)
			return false;

		// Fermat's little theorem
		if (power(a, n - 1, n) != 1)
			return false;

		k--;
	}

	return true;
}

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
	return c;
}

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

	return m;
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