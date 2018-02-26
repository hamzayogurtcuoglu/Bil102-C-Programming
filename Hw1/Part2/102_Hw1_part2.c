#include<stdio.h>

double fxy(double,double);


int main()
{
	
	FILE *inp1,*out;							//Catching and printing in files
	double fex1,fey1,fer1,fex2,fey2,fer2,fer3;	//Declaring ,coefficients
	double x,y;									//Declaring ,value of x and y
	double Coefficients1;						//Declaring ,rate of first and second value of y
	inp1=fopen("EqCoefficients.txt","r");		//Opening,first and second equation coefficient of x and y
	out=fopen("Results2.txt","w");				//Opening ,in order to result of x,y,function

	fscanf(inp1,"%lf %lf %lf %lf %lf %lf",&fex1,&fey1,&fer1,&fex2,&fey2,&fer2);	//Catching coefficients of equation in file
	
	printf("Equation1-> %1.1lfx+ %1.1lfy=%1.1lf\n",fex1,fey1,fer1);	
	printf("Equation2-> %1.1lfx+%1.1lfy=%1.1lf\n",fex2,fey2,fer2);
	
	{	Coefficients1=fex1/fex2;
	
		if (Coefficients1>0)
		{
			Coefficients1*=-1;		
		}							//Optimizing rate of equation	

		fey2*=Coefficients1;
		fer2*=Coefficients1;
		y=(fer2+fer1)/(fey2+fey1);
		x=(fer1-fey1*y)/fex1;
    }
	
	fer3=fxy(x,y);
	
	fprintf(out,"%1.1lf %1.1lf %1.1lf",x,y,fer3);		

	fclose(inp1);
	fclose(out);

	return 0;
}

//Finding  result of f(x,y) function 
double fxy(double x,double y)
{ 

	double	fex1,fey1,fer1;
	
	FILE *inp2;
	inp2=fopen("FuncCoefficients.txt","r");	
	
	fscanf(inp2,"%lf %lf",&fex1,&fey1);		//Catching coefficient of function in text file
	
	fer1=x*fex1+y*fey1;						//function result
	
	printf("f(x,y)=%1.1lfx+%1.1lfy=%1.1lf\n",x,y,fer1);	

	fclose(inp2);		//Closing the file pointer
	
	return fer1;

}
