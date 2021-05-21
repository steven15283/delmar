/* steven guo*/
/*this program preforms XOR encryption on a sequence of characters*/
#include <stdio.h>
#include <ctype.h>
int main()
{   
	char c1,c2;
	char key='&',enc;
	while(1)
	{
        scanf("%c%c",&c1,&c2);
        if(c1=='^' && (c2=='C' || c2=='D'))
        break;
        enc=c1^key;
        if(iscntrl(enc))
        printf("%c\n",c1);
        else
        printf("%c\n",enc);
	}

    return 0;
}
