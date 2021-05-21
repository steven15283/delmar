/* this program reverses a given string */ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char * before, char * after)
{
int i=0;

	for(i=strlen(before)-1;i>=0;i--)
	{
	after[strlen(before)-i-1]=before[i];
	}
}
int main()
{
char*before="steven guo";
char*after=(char*)malloc((strlen(before)+1)*sizeof(char));
reverse(before,after);
printf("reversed string:%s",after);
return 0;
}
