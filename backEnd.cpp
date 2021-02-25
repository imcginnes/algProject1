#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

long long int gcd(long long int num1, long long int num2)
{
	/*

	Returns the Greatest Common Divisor (GCD) of two given numbers.

*/


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
	long long int remainder = 0;

	do
	{
		remainder = num1 % num2;
		num1 = num2;
		num2 = remainder;

	} while (remainder != 0);

	return num1;
}


long genrndnum(long lower_limit, long upper_limit)
{
	srand(time(NULL));
	long rdnum = 0;

	rdnum = lower_limit + (rand() % (int)(upper_limit - lower_limit + 1));

	return rdnum;
}


void keygen(long long int& e_key, long long int& d_key, long long int phival)
{
	//Code to find the encryption key.

	e_key = genrndnum(2, (phival));

	while (gcd(e_key, phival) != 1)
	{
		e_key = genrndnum(2, (phival - 1));
	}

	//Code to find decryption key.

	long long int k = 0;
	d_key = (1 + (k * phival)) / e_key;

	while (((1 + (k * phival)) % e_key) != 0)
	{
		++k;
		d_key = (1 + (k * phival)) / e_key;
	}

	return;
}