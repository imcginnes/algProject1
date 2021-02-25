#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

double genrndnum(double lower_limit, double upper_limit)
{
    srand(time(NULL));
	double rdnum = 0;

    rdnum = lower_limit + (rand() % (double)(upper_limit - lower_limit + 1));

    return rdnum;
}

double gcd(double num1, double num2)
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
}