#include <stdio.h>
const int M = 60 * 24;
int main()
{
	int h,m,a;
	scanf("%d%d",&h,&m);
	a = h * 60 + m;
	scanf("%d%d",&h,&m);
	a = (h * 60 + m + M - a) % M;
	printf("%d %d\n", a/60, a%60);
}
