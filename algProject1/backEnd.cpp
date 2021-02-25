#include <iostream>
#include <cmath>
#include <ctime>
#include <random>

using namespace std;

int genRand()
{
	srand(time(NULL));
	int num = 0;

	do {
		num = rand() & 100;
	} while (num != 1);              //isPrime(num) == false);

	return num;
}


bool isPrime(int num)
{
	int i = 0;
	bool prime = true;
	
	if (num == 0 || num == 1) {
		prime = false;
	}
	else {
		for (i = 2; i <= num / 2; ++i) {
			if (num % i == 0) {
				prime = false;
				break;
			}
		}
	}

	return prime;
}

/*
double gcd(double num1, double num2)
{
	
	Returns the Greatest Common Divisor (GCD) of two given numbers.



	if (num1 == 0 && num2 == 0)
	{
		return 0;
	}

	if (num1 == 0)
	{
		return num2;
	}

	if (num2 == 0)
	{
		return num1;
	}
	double remainder = 0;

	do
	{
		remainder = num1 % num2;
		num1 = num2;
		num2 = remainder;

	} while (remainder != 0);

	return num1;
}

void keygen(double& e_key, double& d_key, double phival)
{
	//Code to find the encryption key.

	e_key = genrndnum(2, (phival));

	while (gcd(e_key, phival) != 1)
	{
		e_key = genrndnum(2, (phival - 1));
	}

	//Code to find decryption key.

	double k = 0;
	d_key = (1 + (k * phival)) / e_key;

	while (((1 + (k * phival)) % e_key) != 0)
	{
		++k;
		d_key = (1 + (k * phival)) / e_key;
	}

	return;
}*/