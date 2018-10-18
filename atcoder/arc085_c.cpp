#include<bits/stdc++.h>
using namespace std;
const int N = 206;
typedef long long ll;
const ll C = 1e12, inf = 1e18;
struct 
{
    struct edge
    {
        int v;
        ll r,f;
    };
    vector<edge> e;
    vector<int> g[N];
    int n,s,t, d[N], pr[N];
    bitset<N> inq;
    void init(int _n,int _s,int _t)
    {
        n=_n,s=_s,t=_t;
    }
    void addE(int u,int v,ll c)
    {
        g[u].push_back(e.size());
        e.push_back(edge{v,c,0});
        g[v].push_back(e.size());
        e.push_back(edge{u,0,0});
    }
    ll aug()
    {
        fill_n(pr,n,-1);
        fill_n(d,n,N);
        d[s] = 0;
        queue<int> q;
        inq.reset();
        q.push(s);
        while (q.size()) {
            int u = q.front();
            q.pop();
            inq[u] = false;
            for (int i : g[u]) {
                if (e[i].r) {
                    int w = d[u] + 1;
                    if (w < d[e[i].v]) {
                        d[e[i].v] = w;
                        pr[e[i].v] = i;
                        if (!inq[e[i].v]) {
                            q.push(e[i].v);
                            inq[e[i].v] = true;
                        }
                    }
                }
            }
        }
        ll f=inf;
        for (int u = t; pr[u] != -1; u = e[pr[u]^1].v)
            f = min(f, e[pr[u]].r);
        for (int u = t; pr[u] != -1; u = e[pr[u]^1].v) {
            e[pr[u]].r -= f;
            e[pr[u]].f += f;
            e[pr[u]^1].r += f;
            e[pr[u]^1].f -= f;
        }
        return f;
    }
} f;
int n,a[N];
int main()
{
    cin >> n;
    f.init(n+2,0,n+1);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] > 0) {
            ans += a[i];
            f.addE(i,f.t,a[i]);
        } else {
            f.addE(f.s,i,-a[i]);
        }
        for (int j = i * 2; j <= n; j += i)
            f.addE(i,j,inf);
    }
    ll w;
    while ((w = f.aug()) != inf)
        ans -= w;
    cout << ans << '\n';
}
