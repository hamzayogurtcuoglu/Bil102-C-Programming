//Hamza Yoğurtcuoğlu 171044086	08.01.2017

//C program which reads car information from an input text file

//named as ‘Cars.txt’ and output total fuel cost.
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/

#include<stdio.h>
#include<math.h>

#define carnumber 3

int main()
{
	
	FILE *inp,*out;

	inp=fopen("Cars.txt","r");
	out=fopen("TotalFuelCosts.txt","w");
	double cars[carnumber][4];
	double costs[carnumber];
	int tl[3],kurus[3];

	for (int i = 0; i <carnumber ; ++i)
	{
		fscanf(inp,"%lf %lf %lf %lf",&cars[i][0],&cars[i][1],&cars[i][2],&cars[i][3]);	//Catching  fuel consumed per km,price of fuel (1lt)
																						//total km taken by car
	}

	//Evaluating cost of cars and it is printed  in the file 
	for (int i = 0; i < carnumber; ++i)				
	{
		costs[i]=cars[i][1]*cars[i][2]*cars[i][3];
		fprintf(out,"%d %1.2lf\n",i+1,costs[i]);
	}

	//Separed kurus and tl
	for (int i = 0; i <carnumber ; ++i)
	{
		tl[i]=(int)costs[i];
		kurus[i]=(int)(fmod(costs [i],1.0)*100);
		printf("The total fuel cost of the car %d is %d Tl and %d kurus\n",i+1,tl[i],kurus[i]);
	}

	return 0;
}

/*############################################################################*/
/*           End of HW01_Hamza_Yoğurtcuoğlu_171044086_part3.c                   */
/*############################################################################*/
