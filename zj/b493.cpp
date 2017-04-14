#include<bits/stdc++.h>
using namespace std;
#define PB push_back
const int N = 50087;
const int D = __lg(N)+1;
const int M = N * D * D;
int n,a[N],dep[N],p[N],sz[N],pa[N][D];
vector<int> g[N];
struct node
{
    int s;
    node*l,*r;
} mem[M],*ptr,*sg[N];
node*insert(node*t,int l,int r,int i)
{
    t=t?new(ptr++)node(*t):new(ptr++)node();
    ++t->s;
    if (r-l>1) {
        int m=(l+r)>>1;
        if (i<m)
            t->l=insert(t->l,l,m,i);
        else
            t->r=insert(t->r,m,r,i);
    }
    return t;
}
void init()
{
    ptr=mem;
    fill_n(dep,n,0);
    fill_n(sz,n,1);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
        g[i].clear();
        fill_n(pa[i],D,-1);
        sg[i] = insert(NULL,1,n+1,a[i]);
    }
}
int qry(node*t,int l,int r,int i)
{
    if (!t)
        return 0;
    if (r-l == 1)
        return t->s;
    int m=(l+r)>>1;
    if (i<m)
        return qry(t->l,l,m,i);
    return (t->l?t->l->s:0) + qry(t->r,m,r,i);
}
int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
int lca(int x,int y)
{
    if (dep[x] < dep[y])
        swap(x,y);
    int d = dep[x] - dep[y];
    for (int k = 0; d; ++k,d>>=1)
        if (d&1)
            x = pa[x][k];
    if (x == y)
        return x;
    for (int k = __lg(dep[x]); k >= 0; --k)
        if (pa[x][k] != pa[y][k]) {
            x = pa[x][k];
            y = pa[y][k];
        }
    return pa[x][0];
}
void dfs(int p,int u)
{
    sg[u] = insert(sg[p],1,n+1,a[u]);
    dep[u] = dep[p] + 1;
    pa[u][0] = p;
    int k;
    for (k = 1; pa[u][k-1] != -1 && k < D; ++k)
        pa[u][k] = pa[pa[u][k-1]][k-1];
    for (; k < D; ++k)
        pa[u][k] = -1;
    for (int v : g[u])
        if (v != p)
            dfs(u,v);
}
void meld(int x,int y)
{
    int a=find(x),b=find(y);
    if (a==b)
        return;
    if (sz[a] < sz[b]) {
        swap(x,y);
        swap(a,b);
    }
    sz[a]+=sz[b];
    p[b]=a;
    g[x].PB(y);
    g[y].PB(x);
    dfs(x,y);
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int q;
    while (cin>>n>>q) {
        for (int i = 0; i < n; ++i)
            cin>>a[i];
        init();
        int ans = 0;
        while (q--) {
            int c,x,y,k;
            cin>>c>>x>>y;
            x^=ans,y^=ans;
            --x,--y;
            if (!c) {
                meld(x,y);
            } else {
                cin>>k;
                k^=ans;
                if (find(x) == find(y)) {
                    int z = lca(x,y);
                    ans=qry(sg[x],1,n+1,k) + qry(sg[y],1,n+1,k) - 2*qry(sg[z],1,n+1,k) + (a[z]<=k);
                    cout << ans << '\n';
                } else {
                    cout << (ans=0) << '\n';
                }
            }
        }
    }
}
