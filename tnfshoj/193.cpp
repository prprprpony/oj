#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 15, M = 205, inf = 1e6;
int n,dp[1<<N][M][2],can[M];
pii a[N];
int cl(int b,int m,int x)
{
	b &= can[m];
	int & d = dp[b][m][x];
	if (d != -1)
		return d;
	if (!b)
		return d = 0;
	if (x == 0) {
		for (int i = 0; i < n; ++i) if (b & (1<<i))
			d = max(d, a[i].S + cl(b^(1<<i),m-a[i].F,1));
	} else {
		d = inf;
		for (int i = 0; i < n; ++i) if (b & (1<<i))
			d = min(d, cl(b^(1<<i),m,0));
	}
	return d;
}
void fl(int b,int m,int x)
{
	b &= can[m];
	int & d = dp[b][m][x];
	if (d == -1)
		return;
	d = -1;
	if (!b)
		return;
	if (x == 0) {
		for (int i = 0; i < n; ++i) if (b & (1<<i))
			fl(b^(1<<i),m-a[i].F,1);
	} else {
		for (int i = 0; i < n; ++i) if (b & (1<<i))
			fl(b^(1<<i),m,0);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	memset(dp,-1,sizeof(dp));
	while (T--) {
		scanf("%d",&n);
		for (int i = 0; i < n; ++i)
			scanf("%d%d",&(a[i].S),&(a[i].F));
		sort(a,a+n);
		int m;
		scanf("%d",&m);
		for (int i = 1, j = 0; i <= m; ++i) {
			can[i] = can[i - 1];
			for ( ; j < n && a[j].F <= i; ++j)
				can[i] |= 1 << j;
		}
		printf("%d\n",cl((1<<n)-1,m,0));
		fl((1<<n)-1,m,0);
	}
}
