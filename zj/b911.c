#include <stdio.h>
int main()
{
	long long n;
	while (scanf("%lld",&n) == 1)
		printf("%lu\n",sizeof(long long) * 8 -  __builtin_clzl(n));
}
