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

string backEnd::sign(int d, int n1, string msg)
{
	int n = msg.length();
	int x = 0;
	int y = 0;

	for (int i = 0; i < n; i++)
	{
		x = pow(d, n);
		y = x % msg[i];

		msg[i] = int(msg[i]);
		msg[i] = y;
	}

	string sMsg = msg;

	return sMsg;
}

string backEnd::verify(string sMsg, int n, int e, string msg)
{
	int x, y = 0;

	for (int i = 0; i < n; i++)
	{
		x = pow(sMsg[i], e);
		y = x % n;

		sMsg[i] = int(msg[i]);
		sMsg[i] = y;
	}
	return sMsg;
}