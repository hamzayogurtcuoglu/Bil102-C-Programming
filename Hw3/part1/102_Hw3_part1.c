//Hamza Yoğurtcuoğlu_171044086
//10.01.2017 18:41
//C program for “Guessing An Integer Number But It Will Contunie as long as user guesses.” game.
/*############################################################################*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*----------------------------------------------------------------------------*/
/*------------------------------Includes--------------------------------------*/
/*----------------------------------------------------------------------------*/
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int RNG();
int CalculateTheDifference(int,int);
void WarnThePlayer(int);

int main()
{
	
	int guess,number,difference;

	char playornot;
	
	printf("Take a character from console “p” or “P” for play and “e” or “E” to exit\n");
	
	scanf("%c",&playornot);											//User enters what he/she wants to do.

	while (playornot!='e'&&playornot!='E')		// If e or E it will be entered a number else finished the game
	{
		if (playornot=='p'||playornot=='P')					// p or P is entered   
		{
			number=RNG();									//taken a number randomly.

			difference=1;

			while(difference!=0)							//Loop continues as long as difference is 0;
			{
				printf("Enter a number between 1 to 10\n");		
				scanf("%d",&guess);									//Entering a number between  1 to 10.
				difference=CalculateTheDifference(guess,number);	//Finding difference between guess and random number.
				WarnThePlayer(difference);							//this function warning to user ,if close or not
			}		

		}
		
		else //if p or P is not entered user enter again.
		{
			printf("You pressed wrong button\n");

			printf("To Play game press 'P' or 'p' and To Exit press 'E' or 'e'\n");

			scanf(" %c",&playornot);	

		}	

		printf("To Play game press 'P' or 'p' and To Exit press 'E' or 'e'\n");

		scanf(" %c",&playornot);	

	}
	
	return 0;
}
	         

//Generates a random number between 1 to 10
int RNG()
{
	srand(time(NULL));     					// Every time random number will be changed by this function.

	int number = rand()%10+1;

	return number ;
}

//To calculate the difference between guess and the number
int CalculateTheDifference(int guess,int number)
{
	int difference;	
	return difference=abs(number-guess);	
}

//To print a warning in order to guide the player.
void WarnThePlayer(int difference)
{
	if (difference>=5)
	{
		printf("You are too far from the number\n");
	}

	else if (difference<5&&difference>=3)
		{
			printf("You are far from the number\n");
		}

		else if (difference<=2&&difference==1)
		{
			printf("You are close to the number\n");
		}
			else printf("!!!!Congratulations!!!!\n");
}
/*############################################################################*/
/*           End of HW03_Hamza_Yoğurtcuoğlu_171044086_part1.c                   */
/*############################################################################*/
