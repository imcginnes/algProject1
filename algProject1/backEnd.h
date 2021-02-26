#pragma once
#ifndef BACKEND_H
#define BACKEND_H

using namespace std;

class backEnd
{
public:
	int genRand();
	bool isPrime(int);
	string sign(int d, int n, string msg);
	string verify(string sMsg, int n1, int e, string msg);
};

#endif