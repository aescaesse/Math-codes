#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <math.h>

int IsDividable(int n, int Sum)
{
	return (n % Sum == 0);
}

int SumOfDigits(int n)
{
	int Sum = 0, Digits = 0;
	while (n > 0)
	{
		Digits = n % 10;
		Sum += Digits;
		n /= 10;
	}
	return Sum;
}

void Core()
{
	int n = 1;
	while (n < 1000000)
	{
		if (IsDividable(n,SumOfDigits(n)))
				printf("%d ", n);
		n++;
	}
}

int main()
{
	Core();
	return 0;
}