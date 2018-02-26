//07.01.2017 written by Hamza Yoğurtcuoğlu
//
//
//C program which evaluates the fog(x) and gof(x)

#include<stdio.h>
#include<math.h>

#define y 9.5  //y is defined as a constant macro

double fx(double);
double gx(double);

int main()
{
	
	FILE *inp,*out;//Creating file pointer
	double x,a,b;	//defining  variables
	
	inp=fopen("Variable.txt","r");//OPENING Variable.txt file in order to read in text file
	out=fopen("Result.txt","w"); //OPENING Result.txt file in order to write in text file
	fscanf(inp,"%lf",&x);         //Variable x is assigned a value in text file

	a=fx(gx(x));	//assigning value of fog
	b=gx(fx(x));	//assigning value of gof

	printf("Result of fog : %1.2lf\n",a);	//Printing screen.
	printf("Result of gof : %1.2lf\n",b);	//Printing screen.

	
	fprintf(out,"%1.2lf %1.2lf",a,b);	// printing a and b in text file.

	fclose(inp);	//Closing file pointers
	fclose(out);	

	return 0;
	
}

//Evaluating fx function
double fx(double x) 
{
	double temp;

	temp=(x+y)/x+sqrt(log10((pow(3,x))/(2*x+1)));	//required process is used	
			
	
	return sin(pow(temp,2.5));
}

//Evaluating gx function	
double gx(double x)
{

	return (x+pow((x+y/(2*x)),-1));

}
