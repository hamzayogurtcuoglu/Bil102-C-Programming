/*############################################################################*/
/*HW02_Hamza_Yoğurtcuoğlu_part2.c                                     */
/*09.01.2018 18:00*/
/*C program that calculates letter grade of 5 students*/
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/

#include<stdio.h>
#define ogrenci 5

void evaluatingaverage(int[],int[],int[],int[]);
void gradeofnote(char[],int[]);
void contribution_to_GPA(char[],char[],char[]);

int main()
{
	
	char n[ogrenci],s[ogrenci],grade[ogrenci];
	int mid1[ogrenci],mid2[ogrenci],final[ogrenci],average[ogrenci];

	FILE *inp,*out;

	inp=fopen("Students.txt","r");
	out=fopen("Grades.txt","w");
	//Catching student information from an input file called “Students.txt”.
	for (int i = 0; i <ogrenci ; ++i)
	{
		fscanf(inp,"%c%c %d %d %d\n", &n[i],&s[i],&mid1[i],&mid2[i],&final[i]);
	}
	
	//Evaluated averages of students.
	evaluatingaverage(mid1,mid2,final,average);
	
	for (int i = 0; i < ogrenci; ++i)
	{
		fprintf(out,"%c%c %d\n",n[i],s[i],average[i]);
	}

	//statement assign the corresponding letter grade
	gradeofnote(grade,average);

	//This function calculates contributions and returns double
	contribution_to_GPA(grade,n,s);

	fclose(inp);
	fclose(out);
	
	return 0;
}

//Midterms has a weight of 30% and Final has a weight of 40%.
//Calculating average of exams.
void evaluatingaverage(int mid1[],int mid2[],int final[],int average[])
{

	for (int i = 0; i < ogrenci; ++i)
	{
		average[i]=(int)(mid1[i]*0.3+mid2[i]*0.3+final[i]*0.4);
	}

}

//statement assign the corresponding letter grade

void gradeofnote(char grade[],int average[])
{
	for (int i = 0; i < ogrenci; ++i)
	{
		if (85<=average[i]&&ogrenci<=100)
		{
			grade[i]='A';
		}
	
		else if (70<=average[i]&&84>=average[i])
			{
				grade[i]='B';
			}

			else if (65<=average[i]&&69>=average[i])
				{
					grade[i]='C';
				}

				else if (40<=average[i]&&64>=average[i])
					{
						grade[i]='D';
					}

					else if (39>=average[i])
					{
						grade[i]='F';
					}
	}				

}

//This function calculates contributions and returns double
void contribution_to_GPA(char grade[],char n[],char s[])
{
	double GPAc;
	for (int i = 0; i < ogrenci; ++i)
	{
		switch(grade[i])
		{
			case 'A': GPAc=4*3/20.0;
					  printf("%c%c GPAc : %1.1lf \n",n[i],s[i],GPAc);
					  break;
			case 'B': GPAc=3*3/20.0;
					  printf("%c%c GPAc : %1.1lf \n",n[i],s[i],GPAc);
					  break;
			case 'C': GPAc=2*3/20.0;
					  printf("%c%c GPAc : %1.1lf \n",n[i],s[i],GPAc);
					  break;
			case 'D': GPAc=1*3/20.0;
					  printf("%c%c GPAc : %1.1lf \n",n[i],s[i],GPAc);
					  break;
			case 'F': GPAc=0.0;
					  printf("%c%c GPAc : %1.1lf",n[i],s[i],GPAc);
					  break;
		}
	}
}
/*############################################################################*/
/*            End of HW02_Hamza_Yoğurtcuoğlu_171044086_part2.c                  */
/*############################################################################*/