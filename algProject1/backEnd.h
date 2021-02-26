#pragma once
#ifndef backEnd_H
#define backEnd_H

#include<iostream>
#include<math.h>
#include<string.h>
#include <cstring>

using namespace std;

class backEnd
{
public:
    backEnd();
    int gcd(int p, int q);
    int genRand();
    bool isPrime(int);
    string encrypt(string m, int e, int n);
    string decrypt(string c, int n, int d);
    string sign(int d, int n, string msg);
    string verifySig(string sMsg, int n, int e, string msg);
};

#endif