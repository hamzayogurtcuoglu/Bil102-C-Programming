//Hamza_Yoğurtcuoğlu_Hw3_Part3.c
//16.01.2017 19:52
//a program which draw a vertical diagram of a bouncing ball.
/*############################################################################*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*----------------------------------------------------------------------------*/
/*------------------------------Includes--------------------------------------*/
/*----------------------------------------------------------------------------*/

#include<stdio.h>

int draw_ver_diag_of_bb(int   first_height,int   feet_height,char   the_peak_point,char the_road_point);
int draw_diag_step(int height,int feet_height,char the_peak_point,char the_road_point);
int finish_diag(int length);  

int main()
{
	int first_height=10,feet_height=5,char_number;
	
	char the_peak_point='O',the_road_point='#';
	
	char_number = draw_ver_diag_of_bb(first_height,feet_height,the_peak_point,the_road_point);

	printf("\nNumber of Used Character : %d\n",char_number);

	return 0;
}

// return value is the total number of the character used 
//(both peaks and path points) .
int  draw_ver_diag_of_bb(int   first_height,int   feet_height,char   the_peak_point,char the_road_point)
{
	int total_character = 0,temp;	//how many character keeping

	printf("^\n");					//this axis arrow

	temp = first_height;			//temp is keeping first height.

	//When the first_height is 0,the loop is finished
	while(temp!=0)	
	{	
		total_character += draw_diag_step(temp,feet_height,the_peak_point,the_road_point);	//drawing each step 

		temp-- ;															//in each loop decreasing height.
	}

	int state = finish_diag(first_height*feet_height);

	printf(">\n");																// axis arrow.

	return total_character; 				//function return used total character in this function.
}

//this function draws each step one by one
//return in each step used character
int draw_diag_step(int height,int feet_height,char the_peak_point,char the_road_point)
{
	int space = 0 ; //Distance of coordinate system

	for (int i = 0; i < height; ++i) // up of step drawing 
	{
		printf("l");	//axis 

		for (int i = 0; i < space; i++)	//this space loop
		{
			printf(" ");
		}

		for (int i = 0; i < feet_height; ++i)	//putting the_road_point to the road
		{
			printf("%c",the_road_point);
		}

		space +=feet_height; //incresing space by feet_height.

		printf("\n");	//new tag 
	}

			

	printf("l");	//axis for the_peak_point

	for (int i = 0; i < space; i++)	//this space loop
	{
			printf(" ");
	}

	printf("%c\n",the_peak_point);

	space -=feet_height;	// a decreasing for half of step

	for (int i = 0; i < height; ++i) // up of step drawing 
	{
		printf("l");	//axis 

		for (int i = 0; i < space; i++)	//this space loop
		{
			printf(" ");
		}

		for (int i = 0; i < feet_height; ++i)	//putting the_road_point to the road
		{
			printf("%c",the_road_point);
		}	

		space -=feet_height; //incresing space by feet_height.

		printf("\n");	//new tag 
	}

	return (feet_height*height*2+1);
}

//Drawing the axis.
int finish_diag(int length)
{

	printf("L");
	
	for (int i = 0; i < length; ++i)
	{
		printf("-");
	}

	return 1;
}
/*############################################################################*/
/*           End of HW03_Hamza_Yoğurtcuoğlu_171044086_part3.c                 */
/*############################################################################*/
