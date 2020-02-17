#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 1e5 + 87;
const int M = 2e5 + 87;
vector<int> g[N];
int a[N];
bool vis[N], ans[M];
pii e[M];
void dfs(int u)
{
    vis[u] = 1;
    for (int i : g[u]) {
        int v = e[i].F ^ e[i].S ^ u;
        if (!vis[v]) {
            dfs(v);
            if (a[v]) {
                a[v] ^= 1;
                a[u] ^= 1;
                ans[i] = 1;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pii> vp(n);
    for (auto & p : vp)
        cin >> p.F >> p.S;
    sort(begin(vp), end(vp));
    for (int i = 0; i < n; ++i)
        a[i] = vp[i].S ^ (i ? vp[i - 1]. S : 0);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        ++r;
        l = lower_bound(vp.begin(), vp.end(), pii(l, -1)) - vp.begin();
        r = lower_bound(vp.begin(), vp.end(), pii(r, -1)) - vp.begin();
        if (l < r) {
            e[i] = {l, r};
            g[l].push_back(i);
            g[r].push_back(i);
        }
    }
    for (int i = n; i >= 0; --i) 
        if (!vis[i]) {
            dfs(i);
            if (i < n && a[i]) {
                cout << "-1\n";
                return 0;
            }
        }
    int k = accumulate(ans, ans + m, 0);
    cout << k << '\n';
    for (int i = 0; i < m; ++i)
        if (ans[i])
            cout << i + 1 << " \n"[--k == 0];
}
