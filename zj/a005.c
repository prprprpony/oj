#include <stdio.h>

int main()
{
	int i,n,t,a,b,c,d,e;
	while(scanf("%d",&t)!=EOF)
	{
		for(i=1;i<=t;i++)
		{
		scanf("%d %d %d %d",&a,&b,&c,&d);
		if(b-a==c-b)
		{
			e=d+b-a;
			printf("%d %d %d %d %d\n",a,b,c,d,e);
		}
		else if(b/a==c/b)
        {

				e=d*b/a;
				printf("%d %d %d %d %d\n",a,b,c,d,e);
        }

		}
	}
	return 0;
}
