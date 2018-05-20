#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
__int128 LIM;
#define F first
#define S second
const int N = 106;
vector<int> g[N];
int md;
vector<int> mu;
int pa[N];
int dm[N];
void far(int u,int p = 0,int d = 0)
{
    if (d == md) {
        mu.push_back(u);
    } else if (d > md) {
        md = d;
        mu = {u};
    }
    pa[u] = p;
    for (int v : g[u]) if (v != p) {
        far(v,u,d+1);
    }
}
void solve(int u,int p = 0,int d = 0)
{
    int deg = 0;
    for (int v : g[u]) if (v != p) {
        solve(v,u,d+1);
        ++deg;
    }
    dm[d] = max(dm[d], deg);
}
pii get_dia()
{
    mu = {};
    md = 0;
    far(1);
    int a = mu[0];
    mu = {};
    md = 0;
    far(a);
    int b = mu[0];
    return pii(a,b);
}
ll solve_even(int mi,int mj,int w)
{
    memset(dm,0,sizeof(dm));
    solve(mi,mj);
    solve(mj,mi);
    ll ans = 2;
    for (int i = 0; i < w/2-1; ++i)
        ans *= dm[i];
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    LIM = __int128(1) << 124;
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int a,b;
    tie(a,b) = get_dia();
    int w = md+1;
    ll ans;
    if (w % 2 == 0) {
        int mi = b;
        for (int i = 0; i < w/2-1; ++i)
            mi = pa[mi];
        int mj = pa[mi];
        ans = solve_even(mi,mj,w);
    } else {
        int mi = b;
        for (int i = 0; i < w/2; ++i)
            mi = pa[mi];
        memset(dm,0,sizeof(dm));
        solve(mi);
        ans = 1;
        for (int i = 0; i < w/2; ++i)
            ans *= dm[i];
        for (int u : g[mi])
            ans = min(ans, solve_even(mi,u,w+1));
    }
    cout << (w + 1) / 2 << ' ' << ans << endl;
}
