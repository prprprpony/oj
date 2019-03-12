#include<bits/stdc++.h>
using namespace std;
struct dinic
{
    static const int N = 3333, inf = INT_MAX;
    struct edge
    {
        int v,r;
        edge(int a,int b) : v(a), r(b) {}
    };
    vector<int> g[N];
    vector<edge> e;
    int n,s,t,lv[N],idx[N];
    void init(int _n,int _s,int _t)
    {
        n = _n;
        s = _s;
        t = _t;
        for (int i = 0; i < n; ++i)
            g[i].clear();
        e.clear();
    }
    void add_edge(int u,int v,int f)
    {
        g[u].emplace_back(e.size());
        e.emplace_back(v,f);
        g[v].emplace_back(e.size());
        e.emplace_back(u,0);
    }
    bool bfs()
    {
        queue<int> q;
        q.push(s);
        fill_n(lv,n,0);
        lv[s] = 1;
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int i : g[u])
                if (!lv[e[i].v] && e[i].r) {
                    lv[e[i].v] = lv[u] + 1;
                    q.push(e[i].v);
                }
        }
        return lv[t];
    }
    int dfs(int u,int a)
    {
        if (!a || u == t)
            return a;
        int f = 0;
        for (int & i = idx[u]; i < g[u].size(); ++i) {
            int v = e[g[u][i]].v, & r = e[g[u][i]].r;
            if (lv[v] == lv[u] + 1) {
                int k = dfs(v, min(a,r));
                r -= k;
                e[g[u][i]^1].r += k;
                f += k;
                a -= k;
            }
            if (!a)
                break;
        }
        return f;
    }
    int max_flow()
    {
        int f = 0;
        while (bfs()) {
            fill_n(idx,n,0);
            f += dfs(s,inf);
        }
        return f;
    }
} flow;
char g[55][55];
void solve()
{
    int w,h,d,f,b;
    cin >> w >> h >> d >> f >> b;
    for (int i = 0; i < h; ++i)
        cin >> g[i];
    int ans = 0;
    flow.init(2+w*h,w*h,w*h+1);
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j) {
            if (i==0||i==h-1||j==0||j==w-1) {
                flow.add_edge(i*w+j,flow.t,flow.inf);
                ans += f * (g[i][j] == '.');
            } else {
                if (g[i][j] == '.')
                    flow.add_edge(flow.s,i*w+j,f);
                else 
                    flow.add_edge(i*w+j,flow.t,d);
            }
            const int dr[]={-1,0,1,0};
            const int dc[]={0,-1,0,1};
            for (int k = 0; k < 4; ++k) {
                int x=i+dr[k],y=j+dc[k];
                if (0<=x&&x<h&&0<=y&&y<w)
                    flow.add_edge(i*w+j,x*w+y,b);
            }
        }
    cout << ans + flow.max_flow() << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}
