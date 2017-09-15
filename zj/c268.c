#include <stdio.h>
#include <stdlib.h>
#define INF ((int)1e9)
int cmp(const void * a,const void * b)
{
	return *(int*)a < *(int*)b ? -1 :
	       *(int*)a > *(int*)b ?  1 :
		                          0 ;
}
int f[100], a[100];
int main()
{
	int m;
	f[1] = 1;
	for (m = 1; f[m] <= INF - f[m-1]; f[m+1] = f[m] + f[m-1], ++m);
	int T;
	scanf("%d",&T);
	while (T--) {
		int n;
		scanf("%d ",&n);
		if (n > m) {
			puts("YES");
			if (T) 
				scanf("%*[^\n]");
//				while (getchar() != '\n');
			continue;
		}
		for (int i = 0; i < n; ++i)
			scanf("%d",a + i);
		qsort(a,n,sizeof(*a),cmp);
		int flag = 0;
		for (int i = 2; i < n; ++i)
			flag |= (a[i-2] + a[i-1] > a[i]);
		puts(flag ? "YES" : "NO");
	}
}
