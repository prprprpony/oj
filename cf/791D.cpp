#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define PB push_back

const int N = 2e5+87;
int n,k;
ll sz[N][5],sl[N][5],dp[N][5],up[N][5];
vi g[N];
void dfs(int d,int p,int u)
{
    sz[u][0] = 1;
    for (int v:g[u]) if (v != p) {
        dfs(d+1,u,v);
        for (int i = 0;  i < k; ++i) {
            sl[u][(i+1)%k] += sl[v][i] + sz[v][i];
            sz[u][(i+1)%k] += sz[v][i];
        }
    }
}
void gdp(int p,int u)
{
    if (p!=-1) {
        for (int i = 0; i < k; ++i) {
            dp[u][i] = dp[p][(i-1+k)%k] + up[p][(i-1+k)%k] + sl[p][(i-1+k)%k] - sl[u][(i-2+k+k)%k] - sz[u][(i-2+k+k)%k] + sz[p][(i-1+k)%k] - sz[u][(i-2+k+k)%k];
            up[u][i] = up[p][(i-1+k)%k] + sz[p][(i-1+k)%k] - sz[u][(i-2+k+k)%k];
        }
    }
    for (int v:g[u]) if (v!=p) {
        gdp(u,v);
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n-1; ++i) {
        int a,b;
        scanf("%d%d",&a,&b);
        --a,--b;
        g[a].PB(b);
        g[b].PB(a);
    }
    dfs(0,-1,0);
    gdp(-1,0);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        --sz[i][0];
        for (int j = 0; j< k; ++j) {
            ans += (dp[i][j] - j * up[i][j] + sl[i][j] - j * sz[i][j]) / k + (j ? (up[i][j] + sz[i][j]) : 0);
        }
    }
    printf("%lld\n",ans/2);
}
