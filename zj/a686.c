#include <stdio.h>
int main()
{
	int n,x,y,z;
	scanf("%d",&n);
	while (n--) {
		scanf("%d%d%d",&x,&y,&z);
		if (y >= x)
			puts("1");
		else if (y <= z)
			puts("Poor Snail");
		else
			printf("%d\n", (x-z-1)/(y-z) + 1);
	}
}
