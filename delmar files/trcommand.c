#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* steven guo*/
/* this program implements the tr command*/
int main(int argc, char* argv[])
{
int i = 0;
int count = 12;
char * numbers = malloc(count * sizeof(char));
for(i = 1 ; i <= argc ; i++)
{
numbers[i] = *(*(argv[i]));
}

FILE *ftpr;
ftpr = fopen(numbers[3], "r");
FILE *ftpw;
ftpw = fopen(numbers[4], "w");
char c;
c = fgetc(ftpr);





while(c != EOF)
{
	if(strcmp(c, numbers1) == 0)
	{
	fputc(numbers2, ftpw);
	c = fgetc(ftpr);
	}
	else
	{
	fputc(c, ftpw);
	c = fgetc(ftpr);
	}
}

fclose(ftpr);
fclose(ftpw);
return 0;
}
