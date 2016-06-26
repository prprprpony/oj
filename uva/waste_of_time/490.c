#include <stdbool.h>
#include <stdio.h>
#include <string.h>
int main()
{
	char s[105][105];
	int r=-1;
	while(gets(s[++r])!=NULL);

	r--; 
	 /*because gets wiil read one more empty line*/

	bool end[r+1];
	memset(end,0,sizeof(end));
	int i,j,edge=0;
	for(j=0;edge<=r;j++)
	{
		while(end[edge]||s[edge][j]=='\0')
		{
			edge++;
			if(edge>r)break;
		}

		for(i=r;(i>=0)&&(edge<=r);i--)
		{
			if(!end[i])
				if(s[i][j]!='\0')
					printf("%c",s[i][j]);
				else {
					end[i]=1;
				}
			if(end[i])
                        	printf(" ");				
		}
		if(edge<=r)printf("\n");
	}

	return  0;
}
