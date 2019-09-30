#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <windows.h>

int Numbers[10] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
int Best_Start = 0, Best_End = 0;
int Count_Elements = sizeof(Numbers) / sizeof(Numbers[0]) - 1;

int Max_Subarray(int Numbers[])
{
	int Current_Start = 0, Current_End = 0;
	int Current_Sum = 0, Best_Sum = 0;
	for (Current_End = 0; Current_End < Count_Elements; Current_End++)
	{
		if (Current_Sum <= 0)
		{
			Current_Start = Current_End;
			Current_Sum = Numbers[Current_End];
		}
		else
			Current_Sum += Numbers[Current_End];
		if (Current_Sum > Best_Sum)
		{
			Best_Sum = Current_Sum;
			Best_Start = Current_Start;
			Best_End = Current_End + 1;
		}
	}
	printf("Best sum is: %d \n", Best_Sum);
	return 0;
}

void Draw_Array()
{
	printf("Given array: [ ");
	for (int i=0; i< Count_Elements; i++)
	{
		printf("%d, ", Numbers[i]);
	}
	printf("]\n");
}

void Draw_Results(int Start, int End)
{
	printf("Made from sequence: [ ");
	for (;Start < End;Start++)
	{
		printf("%d, ", Numbers[Start]);
	}
	printf("]");
}

void Core()
{
	Draw_Array();
	Max_Subarray(Numbers);
	Draw_Results(Best_Start, Best_End);
}

int main()
{
	Core();
	return 0;
}