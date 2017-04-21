#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define EB emplace_back
/* I DUCK HORSE */
const int N = 5e5 + 87;
struct hp
{
    size_t operator () (const pii & x) const
    {
        return hash<long long>()(((long long)x.F)<<32 | x.S);
    }
};
unordered_map<pii,pii,hp> la;
struct edge
{
    int u,v,l,r;
    edge(int a,int b,int c,int d) : u(a), v(b), l(c), r(d) {}
};
typedef vector<edge> ve;
typedef vector<int> vi;
vi g[N];
int c[N];
bool d[N];
void dfs(int u,int k)
{
    c[u] = k;
    for (const int & v : g[u])
        if (c[v] == -1)
            dfs(v,k);
}
void gao(const ve & p,int l,int r,int n,int s)
{
    ve e;
    for (int i = 0; i < n; ++i)
        g[i].clear();
    for (const auto & x : p)
        if (x.l <= l && r <= x.r) {
            g[x.u].PB(x.v);
            g[x.v].PB(x.u);
        } else if (x.l < r && x.r > l) {
            e.EB(x);
        }
    int nm = 0;
    memset(c,0xff,n*sizeof(int));
    for (int i = 0; i < n; ++i)
        if (c[i] == -1) {
            d[nm] = 0;
            dfs(i,nm++);
        }
    for (int i = 0; i < e.size(); ++i) {
        auto&x=e[i];
        x.u=c[x.u], x.v=c[x.v];
        if (x.u == x.v) {
            --i;
            x=e.back();
            e.pop_back();
        } else {
            d[x.u] = d[x.v] = 1;
        }
    }
    n = 0;
    for (int i = 0; i < nm; ++i)
        if (d[i])
            c[i] = n++;
        else
            s++;
    for (auto & x : e)
        x.u=c[x.u], x.v=c[x.v];
    if (!e.size()) {
        for (; l<r; ++l)
            cout << n + s << '\n';
    } else {
        int m=l+((r-l)>>1);
        gao(e,l,m,n,s);
        gao(e,m,r,n,s);
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    la.reserve(N*4);
    int T;
    cin>>T;
    ve e;

    while (T--) {
        int n,m,q;
        cin>>n>>m>>q;
        for (int i = 0; i < m; ++i) {
            int u,v;
            cin>>u>>v;
            if (u>v)
                swap(u,v);
            pii x(u,v);
            auto it = la.find(x);
            if (it == la.end() || it->F != x)
                la.insert({x,{0,1}});
            else
                it->S.S++;
        }
        for (int i = 0; i < q; ++i) {
            char c;
            int u,v;
            cin >> c >> u >> v;
            if (u>v)
                swap(u,v);
            pii x(u,v);
            auto it = la.find(x);
            if (c == 'N') {
                if (it == la.end() || it->F != x)
                    la.insert({x,{i,1}});
                else
                    it->S.S++;
            } else {
                if (!--it->S.S) {
                    e.EB(x.F,x.S,it->S.F,i);
                    la.erase(it);
                }
            }
        }
        for (const auto & x : la)
            e.EB(x.F.F,x.F.S,x.S.F,q);
        la.clear();
        gao(e,0,q,n,0);
        e.clear();
    }
}
