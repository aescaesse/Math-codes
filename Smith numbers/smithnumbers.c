#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <math.h>

int IsPrime(int p) {
	if (p == 2) return 1;
	else if (p <= 1 || p % 2 == 0) return 0;
	else 
		for (int i = 3; i < p; i++)
			if (p % i == 0)
				return 0;
		return 1;
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

int PrimeFactors(int n)
{
	int sum = 0;
	for (int i = 2; i <= n; i++) 
	{
		if (IsPrime(i))
			while (n % i == 0 && i != 1)
			{
				sum += SumOfDigits(i);
				n /= i;
			}	
	}
	return sum;
}

void Core()
{
	int n = 1;
	printf("Smith numbers: ");
	while (n<1000000)
	{
		if(!IsPrime(n))
			if (PrimeFactors(n) == SumOfDigits(n))
				printf("%d ", n);
		n++;
	}

}

int main()
{
	Core();
	return 0;
}