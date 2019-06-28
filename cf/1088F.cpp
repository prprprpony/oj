#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+87;
int n;
ll a[N],ans;
vector<int> g[N];
int pa[N][20];
void dfs(int p,int u)
{
    if (!p)
        p=u;
    pa[u][0] = p;
    for (int i = 1; i < 20; ++i)
        pa[u][i] = pa[pa[u][i-1]][i-1];
    if (p!=u) {
        ll w = a[u]*2;
        for (int i = 0; i < 20 && pa[u][i]; ++i)
            w = min(w, (i+1) * a[pa[u][i]]);
        ans += a[u] + w;
    }
    for (int v : g[u]) if (v != p) dfs(u,v);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i < n-1; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0,min_element(a+1,a+1+n)-a);
    cout << ans << endl;
}
