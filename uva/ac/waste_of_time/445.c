#include <stdio.h>
#include <ctype.h>

int main()
{
	char c;
	int times=0;
	while( (c=getchar()) !=EOF)
	{
		if(c=='b')c=' ';
		if( isdigit(c) ) times += (c-'0');
		else if( c=='!' || c=='\n')putchar('\n');
		else while(times)
			{
				putchar(c);
				times--;
			}
	}

	return 0;
}
