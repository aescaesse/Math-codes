#include <stdio.h> 
#include <complex.h>
#include <time.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <windows.h>

double a, b, c, x1, x2, delta, x1im, x1real;

void DisplayFormula()
{
	if (a < 0)
		printf("%.0lfx^2", a);
	else
	{
		if (a == 1)
			printf("x^2 ");
			
		else if (a > 0)
			printf("%.0lfx^2 ", a);
		else
			printf("");

	}
	if (b < 0)
		printf("%.0lfx ", b);
	else 
	{
		if (b == 1)
			printf("x ");
		else {
			if (b > 0 && a != 0)
				printf("+%.0lfx ", b);
			else
			{
				if (b > 0 && a == 0)
					printf("%.0lfx ", b);

				else
					printf("");
			}
		}
	}
	if (c > 0 && b!=0)
		printf("+%.0lf ", c);
	else
	{
		if (c > 0 && b == 0)
			printf("%.0lf ", c);
		else 
		{
			if (c < 0)
				printf("%.0lf ", c);
			else printf("");
		}
	}
	printf("= 0");
}

void DisplayEverything()
{
	printf("Insert coefficients: ");
	scanf_s("%lf", &a);
	scanf_s("%lf", &b);
	scanf_s("%lf", &c);
	printf("Given formula: ");
	DisplayFormula();
}

int Assumption()
{
	if (a != 0)
		return 1;
	else
		return 0;
}

void Roots()
{
	delta = b * b - 4 * a * c;
	if (delta < 0)
	{
		x1real = -b / (2 * a);
		x1im = sqrt(-delta) / (2 * a);
		printf("\nSolutions: x1 = %.2lf + %.2lfi, x2 = %.2f - %.2fi", x1real, x1im, x1real, x1im);

	}
	else if (delta == 0)
		{
			x1 = -b / 2 * a;
			printf("\nOne solution: x1 = %.2lf", x1);
		}
	else if(delta>0)
		{
			Roots();
			printf("\nSolutions: x1 = %.2lf, x2 = %.2lf", x1, x2);
		}
}

void Core()
{
	DisplayEverything();	
	if (Assumption())
	{
		Roots();
	}
	else
		printf("\nIt is not a quadratic equation.");
}

int main()
{

	Core();
	return 0;
}