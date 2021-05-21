#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*steven Guo*/
int main()
{	
	/* this initializes smallest and largest arrays. Also a word array to act as a place holder that i use to scan in and to compare*/
        char smallest[20];
	char largest[20];
	char word[20];
	 /* this gets user input*/
        printf("enter a word to find smallest and largest. enter a three letter word to exit.\n");
        scanf("%s", word);
	 /* this copys the first word to largest and smallest*/
	strcpy(largest, word);
	strcpy(smallest, word);
	
	 /* this while loop keeps going until the user enters a three letter word*/

	while(strlen(word) != 3 )
  	{
    	printf("Enter a word: ");
    	scanf("%s", word);
	 /* these if statements checks to see if the word the user entered is the largest or smallest. and if it is the smallest or largest word entered, it copies it to smallest or largest */
    	if( strcmp(smallest, word) > 0 )
      	 strcpy(smallest, word);
    	if( strcmp(largest, word) < 0 )
     	 strcpy(largest, word);
	}
  
	
	 /* this is output*/
        printf("the smallest word is: %s\n ", smallest);
	printf("the largest word is: %s\n ", largest);

return 0;
}

