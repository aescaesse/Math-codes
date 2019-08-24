#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <windows.h>

unsigned long long int reverse = 0, n, m, Check, CheckL,k, tmp;
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
	k = n;
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
	{
		return 0;
	}
}

void Core()
{
	while (!IsPalindrome())
	{
		Reverse();
		AddReversed();
	}
	printf("For number %lli : %lli + %lli = %lli\n", tmp, n, reverse, k);
}

int main()
{
	tmp = 10;
	while (1)
	{	
		n = tmp;
		Core();
		tmp++;
	}
	
	return 0;
}