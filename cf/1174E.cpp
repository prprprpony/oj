#include<bits/stdc++.h>
typedef long long ll;
ll M = 1e9+7,n,dp[2][1000007][2];
int main()
{
    std::cin >> n;
    ll v = 1<<std::__lg(n), u = v/2*3, b=1;
    dp[0][1][0] = 1, dp[0][1][1] = u <= n;
    for (; (u /= 2, v /= 2) >= 1; b^=1) {
        ll w=n/v,x=n/(v*2),y=n/(v*3),z=n/u;
        for (ll j = 1; j <= w; ++j) 
            dp[b][j][0]=(dp[b][j-1][0]*(w-(j-1))%M +dp[b^1][j-1][0]*(w-x)%M + dp[b^1][j-1][1]*(w-y)%M)%M, 
            dp[b][j][1]=(dp[b][j-1][1]*(z-(j-1))%M +dp[b^1][j-1][1]*(z-y)%M)%M;
    }
    std::cout << dp[b^1][n][0] << '\n';
}
