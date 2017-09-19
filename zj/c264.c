#include <stdio.h>
#include <stdlib.h>
#define N 205
#define C 1005
typedef struct
{
	int w,v;
}  pii;
pii a[N];
int dp[N][C];
int cmp(void const * x, void const * y)
{
	return ((pii*)x)->w < ((pii*)y)->w ?  1 :
	       ((pii*)x)->w > ((pii*)y)->w ? -1 :
		                                  0 ;
}
int max(int x,int y)
{
	return x < y ? y : x;
}
int min(int x,int y)
{
	return x > y ? y : x;
}
int main()
{
	int n,c,l;
	scanf("%d%d%d",&n,&c,&l);
	for (int i = 0; i < n; ++i)
		scanf("%d%d",&(a[i].w),&(a[i].v));
	qsort(a,n,sizeof(*a),cmp);
	for (int i = 0; i < n; ++i)
		for (int j = min(l,i+1); j >= 1; --j)
			for (int k = c; k >= j * a[i].w; --k)
				dp[j][k] = max(dp[j][k], dp[j-1][k-j * a[i].w] + a[i].v);
	int ans = 0;
	for (int j = l; j >= 1; --j)
		for (int k = c; k > 1; --k)
			ans = max(ans, dp[j][k]);
	printf("%d\n",ans);
}
