#include <stdio.h>

int main()
{
	int r,c,i,j;
	while((scanf("%d%d",&r,&c))!=EOF)
	{
		int A[r][c];
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				scanf("%d",&A[i][j]);
			}
		}
		for(i=0;i<c;i++)
		{
			for(j=0;j<r-1;j++)
			{
				printf("%d ",A[j][i]);
			}
			printf("%d\n",A[j][i]);
		}
	}
	return 0;
}
