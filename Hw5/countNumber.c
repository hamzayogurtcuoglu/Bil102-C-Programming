
/* I don't use any unnecessary arrays or variables. Read/write operations also seems good. Size of arrays
don't exceed 100. */

/* Time complexity of my code is O(n^2) as there are two nested loops. */

#include <stdio.h>


int findIndex(int * number,int readingInteger,int size);

int main()
{
    FILE *fp,*out;

    fp = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    int freq[100] = {};
    int number[100] = {};
    int readingInteger;
    int size = -1;
    while(fscanf(fp,"%d",&readingInteger) != -1)
    {
    	int index = findIndex(number,readingInteger,size);
    	if (index == -1)
    	{
    		size++;
    		number[size] = readingInteger;
    		freq[size] = 1;
    	}else{

    		freq[index] += 1;
    	}
    }

    int temp1,temp2;
    for (int i = 0; i < size+1; ++i)
    {
        for (int j = i + 1; j < size+1; ++j)
        {
            if (freq[i] > freq[j])
            {
                temp1 =  freq[i];
	            temp2=number[i];
                freq[i] = freq[j];
                number[i]=number[j];
                number[j]=temp2;
                freq[j] = temp1;
            }else if (freq[i] == freq[j])
            {
            	if (number[i]>number[j])
	            {
	           		temp1 =  freq[i];
		            temp2=number[i];
	                freq[i] = freq[j];
	                number[i]=number[j];
	                number[j]=temp2;
	                freq[j] = temp1;
            	}
            }
        }
     }

    for (int i = 0; i < size+1; ++i)
    {
    	fprintf(out,"%d:%d\n", number[i], freq[i]);
    }

}

int findIndex(int * number,int readingInteger,int size){

	for (int i = 0; i < size + 1; ++i)
	{
		if (number[i]==readingInteger)
		{
			return i;
		}
	}
	return -1;
}