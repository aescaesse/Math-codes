#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <windows.h>
#include <string.h>
int number;

void UGuess()
{
	srand(time(NULL));
	number = 1 + rand() % 100;
	int userGuess;
	bool Guessed = 0;
	while (!Guessed)
	{
		printf("Try to guess: ");
		scanf_s("%d", &userGuess);
		if (userGuess == number)
		{
			printf("Great, number you was looking for is: %d", number);
			Guessed = 1;
		}
		else if (userGuess < number)
		{
			printf("Number is greater than %d \n", userGuess);
		}
		else
			printf("Number is smaller than %d \n", userGuess);
	}
}

void AGuess()
{
	printf("Provide number to guess: ");
	scanf_s("%d", &number);
	int AGuess;
	int B=0, T = 100;
	AGuess = (100 / 2) + 1;
	bool Guessed = 0;
	while (!Guessed)
	{
		printf("Bot is guessing: %d \n", AGuess);
		if (AGuess == number)
		{
			printf("\nGreat, number you was looking for is: %d", number);
			Guessed = 1;
		}
		else if (AGuess < number)
		{
			printf("Number is greater than bot though \n");
			B = AGuess;
			AGuess = (B + T) / 2;
			
		}
		else
		{
			printf("Number is smaller than bot though \n");
			T = AGuess;
			AGuess = (B + T) / 2;
		}
	}
}

void Core()
{
	int i;
	bool Game = 1;
	int game = 1;
	printf("1. Player, 2. Bot, [Default Bot Mode]  :");
	scanf_s("%d", &i);
	while (Game)
	{
		if (i == 1)
		{
			UGuess();
			printf("\nDo you want try again? [1 = yes, 2 = no]  :");
			scanf_s("%d", &game);
			if (game !=1)
				Game = 0;
		}
		else
		{
			AGuess();
			printf("\nDo you want try again? [1 = yes, 2 = no]  :");
			scanf_s("%d", &game);
			if (game != 1)
				Game = 0;
		}
	}
	printf("\nThanks for playing");
}

int main()
{
	Core();
	return 0;
}