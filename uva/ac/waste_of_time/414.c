#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n) && n)
	{
		getchar();
		char s[n][26];
		int i,j,lb=25,sb=0;
		for(i=0;i<n;i++)
		{
			gets(s[i]);
			int b=0;
			for(j=0;j<25;j++)
				if(s[i][j]==' ')b++;
			sb+=b;
			if(b<lb)
				lb=b;
		}
		printf("%d\n",sb-n*lb);


	}

	return 0;
}
