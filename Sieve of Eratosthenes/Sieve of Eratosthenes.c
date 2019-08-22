#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <math.h>
#include <float.h>
#include <stdbool.h>

int min=25, max, RowMinA, RowMinB, RowMaxA, RowMaxB;
bool Array[10000000];
int Lasts[10000000];
int CountPrimes = 0, CountInRow[10000000];

void cls()
{
	system("@cls||clear");
}

void SetArray(int n)
{
	for (int i = 2; i <= n; i++)
	{
		Array[i] = 1;
	}
}
void SetLasts(int n)
{
	for (int i = 2; i <= n; i++)
	{
		Lasts[i] = 0;
	}
}
void SetCount(int n)
{
	for (int i = 0; i <= n; i++)
	{
		CountInRow[i] = 0;
	}
}

void Output(int n)
{
	int j = 0;
	for (int i = 2; i <= n; i++)
	{
		if (Array[i] == 1)
		{
			CountPrimes++;
			CountInRow[j]++;
			printf("%d. ", i);
		}
		if (i % 100 == 0)
			j++;
	}
}

void OutputForLasts(int n)
{

	int j = 0, z = 100, x = 0;
	
	for (int i = 2; i <= n; i++)
	{
		if (i == n)
			break;
		if (i == 2 || i % 100 == 0)
		{
			if (max < CountInRow[x])
			{
				max = CountInRow[x];
				RowMaxA = i;
				RowMaxB = j+z;
			}
			if (min > CountInRow[x])
			{
				min = CountInRow[x];
				RowMinA = i;
				RowMinB = j+z;
			}
			printf("\nRow:\t%d - %d \t", i, j + z);
			j += z;
			printf("InRow:%d \t", CountInRow[x]);
			x++;
			
		}
		if (Lasts[i] != 0)
		{
			printf("%d, ", Lasts[i]);
		}
	}
}

void LastNumbers(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (Array[i] == 1)
		{
			Lasts[i] = i % 10;
		}
	}
}

void Calculate(int n)
{
	SetArray(n);
	SetLasts(n);
	SetCount(n);
	for (int i = 2; i < sqrt(n); i++)
	{
		if (Array[i] == 1)
		{
			for (int j = i * i; j <= n; j += i)
			{
				Array[j] = 0;
			}
		}
	}
	LastNumbers(n);
	Output(n);
	printf("\nYou got %d primes \n", CountPrimes);
	printf("\n Their last numbers\n");
	OutputForLasts(n);
	printf("\n Min primes: %d (row:%d - %d), max: %d (row:%d - %d)", min, RowMinA, RowMinB, max, RowMaxA, RowMaxB);
}

int main()
{
	int n;
	printf("Max range: ");
	scanf_s("%d", &n);
	Calculate(n);
	return 0;
}