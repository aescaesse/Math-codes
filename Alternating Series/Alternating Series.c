#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <windows.h>

long double Value;
int n;

long double Factorial(int n)
{
	long double factorial = 1;
	for (int i = 1; i <= n +1; ++i)
		factorial *= i;
	return factorial;
}

void Core()
{
	n = 0;
	long double F;
	while (1)
	{
		F=Factorial(n);
		Value = (pow(-1, n)) / F;
		printf("%.250Lf \n", Value);
		n++;
	}
}

int main()
{
	Core();
	return 0;
}
