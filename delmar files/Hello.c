/* Example of a simple C program */
#include <stdio.h>

main()
{
     int n, i;
     printf("How many times would you like to print \"Hello\"?\n");
     scanf("%d", &n);
     for (i=1; i<=n; i++)
       printf("Hello!\n");

     return 0;
}
