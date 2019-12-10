#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+87;
const ll inf = 1e18;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define F first
#define S second
struct edge
{
    int u,v,w;
    int go(int x)
    {
        return u ^ v ^ x;
    }
} e[N];
vector<int> g[N];
int n,m,q;
void dijk(int s, ll d[], int pr[], vector<int> & tp)
{
    tp.clear();
    fill_n(d, n+1, inf);
    d[s] = 0;
    pr[s] = 0;
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,s});
    while (pq.size()) {
        ll w, u;
        tie(w, u) = pq.top();
        pq.pop();
        if (w != d[u])
            continue;
        tp.push_back(u);
        for (int i : g[u]) {
            int v = e[i].go(u);
            ll nw = w + e[i].w;
            if (d[v] > nw) {
                d[v] = nw;
                pq.push({nw, v});
                pr[v] = i;
            }
        }
    }
}
ll ds[N], dt[N];
int pr[N];
int on[N];
vector<int> pe, pv; // edge idx, vertex idx on an optimal path
ll ohne[N];
ll opt;
int lt[N], rt[N];
vector<ll> add[N], del[N];
void bld()
{
    vector<int> tss,tdd;
    dijk(1,ds,pr,tss);
    memset(pr,0,sizeof pr);
    dijk(n,dt,pr,tdd);
    opt = ds[n];
    pv = pe = {0}; // 1-indexed
    for (int u = 1; pr[u]; u = e[pr[u]].go(u)) {
        int i = pr[u];
        on[i] = pe.size();
        pe.push_back(i);
        pv.push_back(u);
    }
    pv.push_back(n);
    for (int u : tss) {
        if (u == 1) {
            lt[u] = 0;
            continue;
        }
        lt[u] = N;
        for (int i : g[u]) {
            int v = e[i].go(u);
            if (ds[v] + e[i].w != ds[u])
                continue;
            if (on[i]) {
                lt[u] = min(lt[u], on[i]);
            } else {
                lt[u] = min(lt[u], lt[v]);
            }
        }
    }
    for (int u : tdd) {
        if (u == n) {
            rt[u] = pe.size();
            continue;
        }
        rt[u] = -N;
        for (int i : g[u]) {
            int v = e[i].go(u);
            if (dt[v] + e[i].w != dt[u])
                continue;
            if (on[i]) {
                rt[u] = max(rt[u], on[i]);
            } else {
                rt[u] = max(rt[u], rt[v]);
            }
        }
    }
    auto upd = [&](int u,int v,int w) {
        if (ds[u] >= inf || dt[v] >= inf)
            return;
        ll d = ds[u] + w + dt[v];
        int l = lt[u] + 1, r = rt[v] - 1;
        if (l <= r) {
            //cerr << "u, v, l, r " << u << ' ' << v << ' ' << l << ' ' << r << endl;
            assert(l > 0 && r < pe.size());
            add[l].emplace_back(d);
            del[r+1].emplace_back(d);
        }
    };
    for (int i = 1; i <= m; ++i)
        if (!on[i]) {
            int u = e[i].u, v = e[i].v, w = e[i].w;
            upd(u,v,w);
            upd(v,u,w);
        }
    multiset<ll> ms;
    for (int i = 1; i < pe.size(); ++i) {
        for (ll x : add[i]) ms.insert(x);
        for (ll x : del[i]) ms.erase(ms.lower_bound(x));
        ohne[i] = ms.size() ? *begin(ms) : inf;
    }
}
ll qry(int t, ll x)
{
    int u = e[t].u, v = e[t].v, w = e[t].w;
    if (!on[t])
        return min({opt, ds[u] + x + dt[v], ds[v] + x + dt[u]});
    //cerr << "2nd case "; cerr << ohne[on[t]] <<' '  <<  opt - w + x << endl;
    return min(ohne[on[t]], opt - w + x);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        g[e[i].u].emplace_back(i);
        g[e[i].v].emplace_back(i);
    }
    bld();
    while (q--) {
        int t, x;
        cin >> t >> x;
        cout << qry(t, x) << '\n';
    }
}
