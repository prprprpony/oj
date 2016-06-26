#include <stdio.h>
int main()
{
	char s[1000];
	int i;
	while(gets(s)!=NULL)
	{
		for(i=0;s[i]!='\0';i++)
			s[i]=s[i]-7;
		puts(s);
	}


	return 0;
}
