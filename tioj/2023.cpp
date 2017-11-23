#include<bits/stdc++.h>
using namespace std;
int dp[1<<22];
char s[25];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; ++i) {
        int v;
        scanf("%s%d",s,&v);
        int k = 0;
        for (int j = 0; j < n; ++j)
            k |= (s[j]-'0') << j;
        dp[k] = v;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 1; j < (1 << n); ++j)
            if (j & (1 << i))
                dp[j] += dp[j ^ (1 << i)];
    sort(dp+1,dp+(1<<n));
    long long ans = 0;
    for (int i = 1; i < (1 << n); ++i)
        ans += i * 1LL * dp[i];
    printf("%lld\n",ans);
}
