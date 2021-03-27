#include<bits/stdc++.h>
using namespace std;
const int N = 1024;
struct Dinic
{
    struct edge
    { 
        int to,fl;
    };
    int n,s,t;
    vector<int> g[N];
    vector<edge> E;
    int lv[N],que[N],idx[N];
    void init(int _n,int _s,int _t)
    {
        n = _n, s = _s, t = _t;
        for (int i = 0; i < n; ++i)
            g[i].clear();
        E.clear();
    }
    void add_edge(int u,int v,int f)
    {
        g[u].push_back((int)E.size());
        E.push_back({v, f});
        g[v].push_back((int)E.size());
        E.push_back({u, 0});
    }
    bool BFS()
    {
        fill_n(lv,n,0);
        lv[s] = 1;
        int ql=0,qr=0;
        que[qr++] = s;
        while (ql < qr) {
            int u = que[ql++];
            for (int i : g[u]) {
                if (E[i].fl && !lv[E[i].to]) {
                    lv[E[i].to] = lv[u] + 1;
                    que[qr++] = E[i].to;
                }
            }
        }
        fill_n(idx,n,0);
        return lv[t];
    }
    int DFS(int u,int a)
    {
        if (u == t || a == 0)
            return a;
        if (lv[u] >= lv[t])
            return 0;
        int f = 0;
        for (int & i = idx[u]; i < (int)g[u].size(); ++i) {
            int x = g[u][i];
            if (!(E[x].fl && lv[E[x].to] == lv[u] + 1))
                continue;
            int k = DFS(E[x].to, min(a, E[x].fl));
            a -= k;
            f += k;
            E[x].fl -= k;
            E[x^1].fl += k;
            if (a == 0)
                break;
        }
        return f;
    }
    int max_flow()
    {
        int f = 0;
        while (BFS()) 
            f += DFS(s,INT_MAX);
        return f;
    }
} f;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    int fn = n + m + 3;
    int s = fn-1, t = fn-2, p = fn-3;
    f.init(fn,s,t);
    f.add_edge(s,p,k);
    for (int i = 0; i < n; ++i) {
        f.add_edge(s,i,1);
        f.add_edge(p,i,1);
        int sz;
        cin >> sz;
        while (sz--) {
            int x;
            cin >> x;
            --x;
            f.add_edge(i,n+x,1);
        }
    }
    for (int i = 0; i < m; ++i) {
        f.add_edge(n+i,t,1);
    }
    cout << f.max_flow() << endl;
}
