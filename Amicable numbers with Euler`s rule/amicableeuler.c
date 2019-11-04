#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <math.h>

int IsPrime(int p) {
	if (p == 2) return 1;
	else if (p <= 1 || p % 2 == 0) return 0;
	else {
		for (int i = 3; i < p; i++)
		{
			if (p % i == 0)
				return 0;
		}
		return 1;
	}
}

void EulersStates(int n, int m)
{
	long double p, q, r, First, Second;
	p = (pow(2, n - m) + 1) * pow(2, m) - 1;
	q = (pow(2, n - m) + 1) * pow(2, n) - 1;
	r = pow(pow(2, n - m) + 1, 2) * pow(2, m + n) - 1;
	if (IsPrime(p) == IsPrime(q) == IsPrime(r))
	{
		First = pow(2, n) * p * q;
		Second = pow(2, n) * r;
		printf("(n,m)(%d,%d) amicable %.0lf %.0lf \n", n,m, First, Second);
	}
}

void Core()
{
	int  n,m;
	n = 2;
	m = 1;
	while (1)
	{
		for (int i = 1; i <= n; i++)
		{
			EulersStates(n,i);
		}
		n++;
	}
}

int main()
{

	Core();
	return 0;
}