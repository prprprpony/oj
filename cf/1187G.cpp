#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u,v,cap,flow,w,wc;
    // next(from) = {to, residual, cost}
    tuple<int,int,int> next(int i)
    {
        if (i == u)
            return {v,cap-flow,(2*flow+1)*w+wc};
        assert(i == v);
        return {u,flow,-(2*flow-1)*w-wc};
    }
    void upd(int i,int f)
    {
        if (i == u) {
            flow += f;
        } else {
            assert(i == v);
            flow -= f;
        }
        assert(0 <= flow && flow <= cap);
    }
};
const int MAXN = 100 * 55, inf = 1e9+7;
struct MCMF
{
    int n,s,t;
    vector<edge> e;
    vector<int> g[MAXN];
    int d[MAXN],da[MAXN],p[MAXN];
    bool inq[MAXN];
    void init(int a,int b,int c)
    {
        tie(n,s,t) = make_tuple(a,b,c);
        e.clear();
        for (int i = 0; i < n; ++i)
            g[i].clear();
    }
    void add_edge(int u,int v,int c,int w,int wc)
    {
        g[u].push_back(e.size());
        g[v].push_back(e.size());
        e.push_back({u,v,c,0,w,wc});
    }
    void BF()
    {
        queue<int> q;
        fill_n(d,n,inf);
        fill_n(p,n,-1);
        fill_n(inq,n,0);
        d[s] = 0;
        inq[s] = 1;
        da[s] = inf;
        q.push(s);
        while (q.size()) {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (int i : g[u]) {
                int v,r,c;
                tie(v,r,c) = e[i].next(u);
                int nc = d[u] + c;
                if (!r || nc >= d[v])
                    continue;
                d[v] = nc;
                da[v] = min(da[u],r);
                p[v] = i;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = 1;
                }
            }
        }
    }
    pair<int,int> max_flow()
    {
        int f=0,c=0;
        while (2) {
//            cerr << "f " << f << endl;
            BF();
            if (d[t] == inf)
                break;
            assert(da[t] == 1);
            f += da[t];
            c += d[t] * da[t];
            for (int v = t, u; p[v] != -1; v = u) {
                u = get<0>(e[p[v]].next(v));
                e[p[v]].upd(u,da[t]);
            }
        }
        return {f,c};
    }
} f;
const int T = 100;
int n,m,k,c,d;
int main()
{
    cin >> n >> m >> k >> c >> d;
    f.init(T*n+2,T*n,T*n+1);
    for (int i = 0, a; i < k; ++i) {
        cin >> a;
        --a;
        f.add_edge(f.s,a,1,0,0);
    }
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        --x,--y;
        for (int j = 0; j+1 < T; ++j) {
            f.add_edge(j*n+x,(j+1)*n+y,inf,d,c);
            f.add_edge(j*n+y,(j+1)*n+x,inf,d,c);
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < T; ++j)
            if (i == 0)
                f.add_edge(j*n+i,f.t,inf,0,0);
            else if (j+1 < T)
                f.add_edge(j*n+i,(j+1)*n+i,inf,0,c);
    int mf,mc;
    tie(mf,mc) = f.max_flow();
    assert(mf == k);
    cout << mc << endl;
}
