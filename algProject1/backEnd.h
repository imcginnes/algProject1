#pragma once
#ifndef BACKEND_H
#define BACKEND_H

using namespace std;

class backEnd
{
public:
	void GUI();
	int genRand();
	int EuclidGCD(int a, int b);
	int power(int a, unsigned int n, int p);
	bool isPrime(unsigned int n, int k);
	string encrypt(string m, int e, int n);
	string decrypt(string c, int n, int d);
	string sign(int d, int n, string msg);
	string verifySig(string sMsg, int n, int e, string msg);
};

#endif