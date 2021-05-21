#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* this program takes in-line parameters and outputs them in reverse*/
/* steven guo*/

/* argc counts the amount of arguments passed through parameters*/
/* argv[] stores all the arguments passed through the parameters*/
int main(int argc, char * argv[])
{
/* this initializes i for the for loop*/
int i;
	/*the for loop makes i argc - 1 because argv[] stores another arguement after your last one. the i is set to count down so we can output last arguement first*/
        for(i = argc - 1; i > 0; i--)
        {
		/* this prints the strings in argv*/
                printf("%s  ",argv[i]);
        }
return 0;
}

