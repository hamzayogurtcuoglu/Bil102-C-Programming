
#include<stdio.h>

int PlainTextMessages(char [],FILE *);	//This function calculate lenght_of_file
										//Catching character in the file , copying a array.
void EncodedMessages(char [],FILE *,int);

int EncrypedMessages(int counter,int hyphen,int * temp,FILE * encryptedout);

int main()
{
	
	FILE * textin,* encodeout;

	textin = fopen("PlainMessagesToSent.txt","r");

	encodeout = fopen("EncodedMessages.txt","w");

	char text[100];
	
	int text_lenght;

	text_lenght=PlainTextMessages(text,textin);

	EncodedMessages(text,encodeout,text_lenght);

	return 0;
}


//This function calculate lenght_of_file
//Catching character in the file , copying a array.
int PlainTextMessages(char text[],FILE * textin)
{
	int array_lenght=0;					//Keeping array_lenght how many character

	while(fscanf(textin,"%c",&text[array_lenght])!=EOF)			//If end of file ,loop is finished EOF is a FILE command
	{	
		
		array_lenght++;								//Increasing counting array_lenght :)

	}

	return --array_lenght;				//Decrasing for wasteing increasing.
}

void EncodedMessages(char text[],FILE * encodeout,int text_lenght)
{
	
	FILE * encryptedout;	//Creating encryptedout pointer

	encryptedout = fopen("EncryptedMessages.txt","w");

	int hyphen = 5;			//Creating hyphen "-" it works between 5 and 1 that is change	

	int * temp = &hyphen ;    //That means.Temp is assigned hyphen when will be put in 5,4,3,2,1,5....

	int counter; 		//It's keeping - counter that it works each  binary number of alphabet 

	for (int i = 0; i < text_lenght; ++i)	//Loop is continued until text_lenght 
	{
		switch(text[i])			//According to conditions writing binary digits
		{
			case 'E' : fprintf(encodeout,"%d",0);
						counter=1;
						hyphen=EncrypedMessages(counter,hyphen,temp,encryptedout);	//Function will return where hypen is 
						break;
			case 'I' : fprintf(encodeout,"%d",10 );
						counter=2;
						hyphen=EncrypedMessages(counter,hyphen,temp,encryptedout);	//Function will return where hypen is 
						break;
			case ' ' : fprintf(encodeout,"%d",110 );
						counter=3;
						hyphen=EncrypedMessages(counter,hyphen,temp,encryptedout);	//Function will return where hypen is 
						break;
			case 'T' : fprintf(encodeout,"%d",1110 );
						counter=4;
						hyphen=EncrypedMessages(counter,hyphen,temp,encryptedout);	//Function will return where hypen is 
						break;
			case 'C' : fprintf(encodeout,"%d",11110 );
						counter=5;
						hyphen=EncrypedMessages(counter,hyphen,temp,encryptedout);	//Function will return where hypen is 
						break;
			case 'N' : fprintf(encodeout,"%d",111110 );
						counter=6;
						hyphen=EncrypedMessages(counter,hyphen,temp,encryptedout);	//Function will return where hypen is 
						break;
			case 'A' : fprintf(encodeout,"%d",1111110 );
						counter=7;
						hyphen=EncrypedMessages(counter,hyphen,temp,encryptedout);	//Function will return where hypen is 
						break;			
			case 'G' : fprintf(encodeout,"%d",11111110 );
						counter=8;
						hyphen=EncrypedMessages(counter,hyphen,temp,encryptedout);	//Function will return where hypen is 
						break;			
			case 'B' : fprintf(encodeout,"%d",111111110 );
						counter=9;
						hyphen=EncrypedMessages(counter,hyphen,temp,encryptedout);	//Function will return where hypen is 
						break;
			case 'Z' : fprintf(encodeout,"%d",1111111110 );
						counter=10;
						hyphen=EncrypedMessages(counter,hyphen,temp,encryptedout);	//Function will return where hypen is 
						break;
			case 'H' : fprintf(encodeout,"%d",111111);					//I separated two parts in order not to be enough digit number
					   fprintf(encodeout,"%d",11110 );					//But I noticed that can be encoded according to counter and last digit -  
						counter=11;										//would be '0'  
						hyphen=EncrypedMessages(counter,hyphen,temp,encryptedout);	//Function will return where hypen is 
						break;
			case 'L' : fprintf(encodeout,"%d",1111111);
					   fprintf(encodeout,"%d",11110);
						counter=12;
						hyphen=EncrypedMessages(counter,hyphen,temp,encryptedout);	//Function will return where hypen is 
						break;
			case 'U' : fprintf(encodeout,"%d",111111);
					   fprintf(encodeout,"%d",1111110);
						counter=13;
						hyphen=EncrypedMessages(counter,hyphen,temp,encryptedout);	//Function will return where hypen is 
						break;
			case 'V' : fprintf(encodeout,"%d",1111111);
						fprintf(encodeout,"%d",1111110);
						counter=14;
						hyphen=EncrypedMessages(counter,hyphen,temp,encryptedout);	//Function will return where hypen is 
						break;
			case 'R' : fprintf(encodeout,"%d",1111111);
					   fprintf(encodeout,"%d",11111110 );
						counter=15;
						hyphen=EncrypedMessages(counter,hyphen,temp,encryptedout);	//Function will return where hypen is 
						break;
			case 'S' : fprintf(encodeout,"%d",11111111 );
					   fprintf(encodeout,"%d",11111110);
						counter=16;
						hyphen=EncrypedMessages(counter,hyphen,temp,encryptedout);	//Function will return where hypen is 
						break;
			case 'Y' : fprintf(encodeout,"%d",111111111);
					   fprintf(encodeout,"%d",11111110);
						counter=17;
						hyphen=EncrypedMessages(counter,hyphen,temp,encryptedout);	//Function will return where hypen is 
						break;
			default : 	
						break;

		}
	}	//For loop bracked

}

int EncrypedMessages(int counter,int hyphen,int * temp,FILE * encryptedout)
{

	for (int i = 0; i < counter; ++i)
	{
		
		if (hyphen==0)			//When hyphen is equal 0 putting '-'
		{
			fprintf(encryptedout,"-");
			
			if (* temp==1)
			{
				hyphen = 5;
			
				* temp = 5;
			}
			else if (* temp==5)
				{
					hyphen = 4;

					* temp = 4;
				}
				else if (* temp==4)
					{
						hyphen = 3;
					
						* temp = 3 ;
					}
					else if (* temp==3)
						{
							hyphen = 2;
						
							* temp = 2 ;
						}

						else if (* temp==2)
						 	{
								hyphen = 1;
							
								* temp = 1 ;
							}
		}

		if ((counter-1)==i)
		{
			fprintf(encryptedout,"_");		//Last binary 0 is equal '_'
		}


		if ((counter-1)!=i)		//Other binary 1 is equal '*'
		{
			fprintf(encryptedout,"*");
		}		

		hyphen--;

	}

	return hyphen;

}
