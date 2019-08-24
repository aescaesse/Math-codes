#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <windows.h>

unsigned long long int reverse = 0, n, m, Check, CheckL;

void Reverse()
{
	m = n;
	reverse = 0;
	while (m != 0)
	{
		int last = m % 10;
		reverse = reverse * 10 + last;
		m /= 10;
	}
	
}

void AddReversed()
{
	n += reverse;
}

int IsPalindrome()
{
	unsigned long long int k = n;
	m = k;
	Check = 0;
	while (m != 0)
	{
		CheckL = m % 10;
		Check = Check * 10 + CheckL;
		m /= 10;
	}
	if (k==Check)
	{
		return 1;
	}
	else
		return 0;
}

void Core()
{
	int i = 1;
	while (!IsPalindrome())
	{
		Reverse();
		printf("%d. %lli + %lli = ",i,n,reverse);
		AddReversed();
		printf("%lli \n", n);
		i++;
	}
	printf("Palindrome: %lli", n);
}

int main()
{
	printf("Give number: ");
	scanf_s("%lli", &n);
	Core();
	return 0;
}