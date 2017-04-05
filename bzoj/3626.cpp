#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define REP(i,a,b) for(int i(a),_B(b);i<_B;++i)
#define RP(i,n) REP(i,0,n)
#define PB push_back
#define SZ(a) ((int)a.size())
typedef pair<int,int> pii;
#define F first
#define S second

const int N = 51234, M = 201314;
vi g[N];
pii qr[N<<1],a[N];
int pa[N],sz[N],hc[N],hd[N],hi[N],hs[N];
pii mem[N<<2],*sg[N];
pii*ptr=mem;
void dfs(int u)
{
    sz[u] = 1;
    hc[u] = -1;
    RP(i,SZ(g[u])) {
        int v = g[u][i];
        dfs(v);
        sz[u] += sz[v];
        if (hc[u] < 0 || sz[v] > sz[hc[u]])
            hc[u] = v;
    }
}
void build(int u)
{
    if (hd[u] < 0) {
        int c = 0;
        for (int v = u; v != -1; v = hc[v], ++c) {
            hd[v] = u;
            hi[v] = c;
        }
        sg[u] = ptr;
        hs[u] = c;
        ptr += c<<2;
    }
    RP(i,SZ(g[u])) {
        int v = g[u][i];
        build(v);
    }
}
void add(pii & t,int l,int r,int v)
{
    t.S = (t.S + v) % M;
    t.F = (t.F+(r-l)%M*1LL*v%M)%M;
}
void push(pii*t,int o,int l,int m,int r)
{
    if(t[o].S) {
        add(t[o+o+1],l,m,t[o].S);
        add(t[o+o+2],m,r,t[o].S);
        t[o].S = 0;
    }
}
void pull(pii*t,int o)
{
    t[o].F = (t[o+1+o].F + t[o+2+o].F)%M;
}
void add(pii*t,int o,int l,int r,int i,int j,int v)
{
    if (r <= i || j <= l)
        return;
    if (i <= l && r <= j) {
        add(t[o],l,r,v);
        return;
    }
    int m = (l+r)>>1;
    push(t,o,l,m,r);
    add(t,o+o+1,l,m,i,j,v);
    add(t,o+o+2,m,r,i,j,v);
    pull(t,o);
}
void add(int u)
{
    for (;u != -1; u = pa[hd[u]])
        add(sg[hd[u]],0,0,hs[hd[u]],0,hi[u]+1,1);
}
int qry(pii*t,int o,int l,int r,int i,int j)
{
    if (r <= i || j <= l)
        return 0;
    if (i <= l && r <= j)
        return t[o].F;
    int m = (l+r)>>1;
    push(t,o,l,m,r);
    return (qry(t,o+o+1,l,m,i,j) + qry(t,o+o+2,m,r,i,j))%M;
}
int qry(int u)
{
    int ret = 0;
    for (; u != -1; u = pa[hd[u]])
        ret = (ret + qry(sg[hd[u]],0,0,hs[hd[u]],0,hi[u]+1))%M;
    return ret;
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    pa[0] = -1;
    REP(i,1,n) {
        scanf("%d",pa+i);
        g[pa[i]].PB(i);
    }
    dfs(0);
    RP(i,n) hd[i] = -1;
    build(0);
    RP(i,q) {
        int l,r;
        scanf("%d%d%d",&l,&r,&a[i].F);
        qr[i<<1]=pii(l-1,i<<1);
        qr[i<<1|1]=pii(r,i<<1|1);
    }
    sort(qr,qr+q+q);
    int w=0;
    RP(i,q<<1) {
        if (qr[i].F<0) continue;
        while (w <= qr[i].F)
            add(w++);
        int x = qr[i].S>>1;
        a[x].S = (a[x].S + qry(a[x].F) * ((qr[i].S&1)?1:-1) + M)%M;
    }
    RP(i,q) printf("%d\n",a[i].S);
}
