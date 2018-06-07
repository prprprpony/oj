#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 2066;
const ll inf = 1e18;
pii p[N];
int idx[N],deg[N];
int in[N];
ll dis[N];
bool inq[N];
ll sqr(ll x) {return x * x;}
void solve()
{
    int n;
    cin >> n;
    iota(idx,idx+n,0);
    fill_n(deg,n,0);
    fill_n(dis,n,inf);
    fill_n(in,n,-1);
    fill_n(inq,n,true);

    for (int i = 0; i < n; ++i)
        cin >> p[i].F >> p[i].S;

    vector<pii> ans;
    inq[0] = false;
    for (int u = 0; ans.size() < n - 1; ) {
        ll mi = inf;
        int v = -1;
        for (int i = 1; i < n; ++i) {
            if (!inq[i])
                continue;
            ll w = sqr(p[i].F - p[u].F) + sqr(p[i].S - p[u].S);
            if (w < dis[i]) {
                dis[i] = w;
                in[i] = u;
            }
            if (dis[i] < mi) {
                mi = dis[i];
                v = i;
            }
        }
        ans.emplace_back(v,in[v]);
        ++deg[v];
        ++deg[in[v]];
        inq[v] = false;
        u = v;
    }

    for (int m = n; ans.size(); --m) {
        for (int i = 0; i < m; ++i) {
            int u,v;
            tie(u,v) = ans[i];
            if (deg[v] == 1)
                swap(u,v);
            if (deg[u] != 1)
                continue;
            int d = (idx[u] - idx[v] + m) % m;
            if (d == m-1 || d == 1) {
                cout << u+1 << ' ' << v+1 << '\n';
                ans[i] = ans.back();
                ans.pop_back();
                --deg[u];
                --deg[v];
                for (int j = u; j < n; ++j)
                    --idx[j];
                break;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
}
