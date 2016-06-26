#include <stdbool.h>
#include <stdio.h>
bool isalpha(char c)
{
	return (c>='a'&&c<='z')||(c>='A'&&c<='Z');
}
int main()
{
	char s[1000];
	while(gets(s)!=NULL)
	{
		int i=0,words;
		bool cur=isalpha(s[i]);
		words=(cur)?1:0;
		while(s[++i]!='\0')
		{
			if(!(isalpha(s[i])^cur))continue;
			else
			{
				cur=!cur;
				if(cur)words++;
			}
		}
		printf("%d\n",words);
	}



	return 0;
}
