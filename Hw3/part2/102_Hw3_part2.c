/*############################################################################*/
/*HW03_Hamza_Yoğurtcuoğlu_171044086_part2.c                                     */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Hamza Yoğurtcuoğlu 13.01.2018 16:35                              */
/*                                                                            */
/*Description                                                                 */
/*__________                                                                  */
/*Calculates vertical distance of bouncing ball                               */
/*                                                                            */
/*Inputs:                                                                     */
/* -                                                                          */
/*Outputs:                                                                    */ 
/* -Number of bouncing                                                        */
/* -Total vertical distance of bouncing ball                                  */
/*############################################################################*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*----------------------------------------------------------------------------*/
/*------------------------------Includes--------------------------------------*/
/*----------------------------------------------------------------------------*/
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>

double	calculate_the_new_height(double,double); //its parameters are height and ratio calculate new height 
double  calculate_the_vertical_distance(double,double); //Evaluating All distance by this function return all distance
int     count_the_number(int);                   //How many times ball bounced that is calculeting.
void 	report(int,double,double,FILE *);               //it takes parameters these are height,all distance,counter_bouncing

int main()
{
	srand(time(NULL));	
	
	FILE *out;

	out=fopen("Results_Table.txt","w");

	fprintf(out,"No – The Rebounching Height -- The Total vertical Distance\n");

	int counter = 1;

	double first_height=rand()%40+10; //Ball first fit between 10 feet to 40 feet.
	
	double total_distance=first_height;

	double ratio=fmod(rand(),0.399)+0.4;	//ball will raise according to ratio.

	printf("No – The Rebounching Height -- The Total vertical Distance\n");

	while(1.0 < first_height)
	{
		printf("%d\t%10.3lf%20.3lf\n",counter,first_height,total_distance );

		report(counter,first_height,total_distance,out); //It takes like argument that is printed in file.

		first_height = calculate_the_new_height(first_height,ratio);
		
		total_distance = calculate_the_vertical_distance(first_height,total_distance);
	
		counter=count_the_number(counter);				//keeping how many times ball bounced.
	}

	printf("\nThe bouncing is stopped and the task completed...\n");

	fprintf(out, "\nThe bouncing is stopped and the task completed...");

	return 0;
}

//Calculating new height of ball
double calculate_the_new_height(double first_height,double ratio)
{
	return first_height*ratio;		//first height is multiples with ratio
}

//Evaluating total distance.
double calculate_the_vertical_distance(double first_height,double total_distance)
{
	return (total_distance+first_height*2);
}

//it is printing in file
void report(int counter,double first_height,double total_distance,FILE * out )
{
	fprintf(out,"\n%d\t%10.3lf%20.3lf",counter,first_height,total_distance );
}

//Increasing counter how many times ball bounced.
int  count_the_number(int counter)
{
	return ++counter;
}
/*############################################################################*/
/*           End of HW03_Hamza_Yoğurtcuoğlu_171044086_part2.c                 */
/*############################################################################*/
