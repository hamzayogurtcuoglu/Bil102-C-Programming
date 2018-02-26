//Hamza Yoğurtcuoğlu_171044086
//08.01.2017 21:17
//C program for “Guessing An Integer Number” game.
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int RNG();
int CalculateTheDifference(int,int);
void WarnThePlayer(int);

int main()
{
	srand(time(NULL));

	int number=RNG();
	
	int chance=0,guess,difference;
	
	//He or She has only two chances.	
	while(chance<2)
	{
		printf("Enter a guess between 1 to 10 :\n");
		scanf("%d",&guess);
		difference=CalculateTheDifference(guess,number);
		
		if (difference==0)
		{
			WarnThePlayer(difference);
			return 0;
		}

		WarnThePlayer(difference);
		chance++;	
	
	}
	
	if(difference!=0)
		printf("###Game Over### \nNumber is %d\n",number);	
	return 0;
}

//Generates a random number between 1 to 10
int RNG()
{
	int number = rand()%10+1;

	return number ;
}

//To calculate the difference between guess and the number
int CalculateTheDifference(int guess,int number)
{
	int difference;	
	return (difference=abs(number-guess));	
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
/*           End of HW02_Hamza_Yoğurtcuoğlu_171044086_part3.c                   */
/*############################################################################*/
