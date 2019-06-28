#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+87;
vector<int> g[N];
ll a[N],dp[N],mx,ct;
void dfs(int p,int u,bool c)
{
    dp[u] = a[u];
    for (int v:g[u]) if (v != p) {
        dfs(u,v,c);
        dp[u] += max(0ll,dp[v]);
    }
    if (c && dp[u] == mx)
        ++ct, dp[u]=0;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=0;i<n-1;++i) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,1,0);
    mx=*max_element(dp+1,dp+1+n);
    dfs(1,1,1);
    cout << mx*ct << ' ' << ct << endl;
}
