#include<iostream>
#include<cmath>
#include<string>
#include <cstring>
#include <ctime>
#include "backEnd.h"

using namespace std;

backEnd::backEnd()
{

}

int backEnd::gcd(int p, int q)
{
	int temp = 0;

	while (p != 0)
	{
		temp = p % q;

		if (temp == 0)
			return q;
		p = q;
		q = temp;
	}
	return -1;
}

int backEnd::genRand()
{
	srand(time(NULL));
	int num = 0;

	while (num == 0 || isPrime(num) == false) {
		num = rand() & 100;
	}

	return num;
};


bool backEnd::isPrime(int num)
{
	bool flag = true;
	for (int i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
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