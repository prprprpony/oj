#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int f;
		scanf("%d",&f);
		long long int size,ef,bud=0;
		while(f--)
		{
			scanf("%lld%lld%lld",&size,&ef,&ef);
			bud+=(size*ef);
		}
		printf("%lld\n",bud);
	}

	return 0;
}
