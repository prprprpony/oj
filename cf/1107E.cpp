#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 106;
int a[N],n;
char s[N];
ll dp[N][N][N];
ll cal(int i,int j,int w)
{
    if (i > j)
        return 0;
    ll & d = dp[i][j][w];
    if (d != -1)
        return d;
    d = a[w] + cal(i+1,j,1);
    for (int k = i+1; k <= j; ++k)
        if (s[k] == s[i])
            d = max(d, cal(i+1,k-1,1) + cal(k,j,w+1));
    return d;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> (s+1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    memset(dp,-1,sizeof(dp));
    cout << cal(1,n,1) << endl;
}
