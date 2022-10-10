#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

double factorial(int n)
{
	int res = 1;
	if (n == 0 || n == 1)
	{
		return res;
	}
	for (int i = 2; i <= n; i++)
	{
		res *= i;
	}
	return double(res);
}

double sin(double x)
{
	double res = 0;
	double tx = x;
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
		{
			res += (tx / factorial(i * 2 + 1));
		}
		else
		{
			res -= tx / factorial(2 * i + 1);
		}
		tx = tx * x * x;
	}
	return res;
}
double cos(double x)
{
	double res = 0;
	double tx = 1;
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
		{
			res += (tx / factorial(i * 2));
		}
		else
		{
			res -= tx / factorial(2 * i);
		}
		tx = tx * x * x;
	}
	return res;
}
double tg(double x)
{
	return sin(x) / cos(x);
}
double ctg(double x)
{
	return cos(x) / sin(x);
}

double exp(int x) {
	double tx = 1;
	double res = 0;
	for (int i = 0; i < 10; i++) {
		res += tx / factorial(i);
		std::cout << "==" << tx / factorial(i) << std::endl;
		tx *= x;
	}

	return res;
}

double logBase(double x, double bs) {
	return log(x) / log(bs);
}

