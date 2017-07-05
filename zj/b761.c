#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	puts(n % 4 ? "fat" : "egg");
}
