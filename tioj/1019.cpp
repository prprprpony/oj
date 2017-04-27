#include<bits/stdc++.h>
using namespace std;
const int N = 1087;
int a[3];
long long dp[3];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--) {
		int n;
		scanf("%d%d%d",&n,a,a+1);
		dp[0] = 0;
		dp[1] = abs(a[0] - 1LL * a[1]);
		int c = 2, k = 0, j = 1, i = 2;
		for (; c < n; ++c, i = k, k = j, j = 3 ^ i ^ k) {
			scanf("%d",a+i);
			dp[i] = min(abs(a[i] - 1LL * a[j]) + dp[j], abs(a[i] - 1LL * a[k]) + dp[k]);
		}
		printf("%lld\n",dp[j]);
	}
}
