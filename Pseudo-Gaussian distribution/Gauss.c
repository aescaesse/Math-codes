#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <math.h>
#include <float.h>
#include <stdbool.h>

#define PI 3.141592654
int Count[100]; 
int n = 50; /* number of results */

void cls() 
{ 
	system("@cls||clear"); 
} 

void Erase()
{
	for (int i = 0; i < n; i++)
	{
		Count[i] = 0;
	}
}

void Print()
{
	for (int i = 1; i <= n; i++)
	{
		if (i > 1 && i % 10 == 0)
		{
			printf("\n");
		}
			printf(" %d -> { %d }\t ",  i, Count[i]);
	}
}

double GaussianNoise()
{
	double x = (double)rand() / RAND_MAX;
	double y = (double)rand() / RAND_MAX;
	double z = sqrt(-2 * log(x)) * cos(2 * PI * y);
	return z;
}

void RandomGauss()
{
	int Given = 0;
	Given = (long)floor(GaussianNoise()*10) + 25; /* i just modified formula for my own target 0-50*/
	Count[Given]++;
}

void Plot()
{
	printf("\n");
	for (int i = 1; i <= n; i++)
	{
		printf("%d. ", i);
		for (int j = 0; j<Count[i]; j++)
				printf("*");
		printf("\n");	
	}
}

void Generator()
{
	int IsDone = 0;
	Erase();
	while (!IsDone)
	{
		Print();
		printf("\n\nGraph");
		RandomGauss();
		Plot();
		cls();
	}
}

int main() 
{ 
	Generator();
	return 0;
}