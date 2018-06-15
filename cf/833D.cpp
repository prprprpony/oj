#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 1e5 + 98, M = 1e9+7;
int add(int a,int b) {return (a += b) >= M ? a - M : a;}
int mul(int a,int b) {return a * 1LL * b % M;}
const pii I(0,1);
pii meld(const pii & a,const pii & b) {return pii(a.F+b.F,mul(a.S,b.S));}
int qpow(int a,int b)
{
    int r = 1;
    for (;b;b>>=1,a=mul(a,a))
        if (b&1)
            r = mul(r,a);
    return r;
}
vector<pii> g[N];
bitset<N> dead;
int sz[N],ans,bns;

struct fen
{
    pii fen[4 * N];
    int base,n;
    void init(int _n)
    {
        n = 4*_n+1;
        base = 2*_n+1;
        fill_n(fen+1,n,I);
    }
    void upd(int x,int v)
    {
        for (int r = x + base; r <= n; r += r & -r)
            fen[r] = meld(fen[r],pii(1,v));
    }
    pii qry(int x)
    {
        pii ret(I);
        for (int r = x + base; r; r ^= r & -r)
            ret = meld(ret,fen[r]);
        return ret;
    }
} fa,fb;
void getsz(int u,int p=0)
{
    sz[u] = 1;
    for (const auto & e : g[u]) {
        int v = e.F;
        if (dead[v] || v == p)
            continue;
        getsz(v,u);
        sz[u] += sz[v];
    }
}
int cent(int u,int n,int p=0)
{
    for (const auto & e : g[u]) {
        int v = e.F;
        if (dead[v] || v == p)
            continue;
        if (sz[v] > n/2)
            return cent(v,n,u);
    }
    return u;
}
/*
 *   Apparently, I misread the problem......
 *   I thought x and y differ at most twice means abs(x-y) <= 2 .....
 *
 *   WLOG, x >= y >= 1
 *   x/y <= 2
 *   y <= x <= 2y
 *   x/2 <= y <= x
 *   x + y = len(path)
 *
 *   x >= e-x >= 1
 *   x >= e/2
 *   x/(e-x) <= 2
 *   x <= 2e-2x
 *   x <= (2/3)e
 *
 *
 *   1 <= y1+y2 <= x1+x2 <= 2(y1+y2)
 *
 *   x2-y2 >= y1-x1
 *   x2-2y2 <= 2y1-x1
 *      
 *   y2-x2 <= x1-y1
 *   x2-2y2 <= 2y1-x1
 *
 *  x = y is conunted twice ==
 *
 *  y1+y2 < x1 + x2
 *  y1 + y2 <= x1 + x2 - 1
 *  y2-x2 <= x1-y1-1
 *
 *  ==========
 *
 *  x <= 2y and y <= 2x 
 *  =>  (x <= 2y) setminus (x < y/2)
 *
 *  x1+x2 <= 2(y1+y2)
 *  x2 - 2y2 <= 2y1 - x1
 *
 *  x1+x2 < (y1+y2)/2
 *  2x2-y2 < y1-2x1
 */
vector<pair<pii,int>> cx;
void dfs(int u,int p,int x1,int y1,int sx)
{
    {
        int a = 2*y1-x1, b = y1-2*x1;
        cx.emplace_back(pii(-a,-b),sx);
        pii ra = fa.qry(a), rb = fb.qry(b-1);
        int aa = mul(qpow(sx,ra.F), ra.S);
        int bb = mul(qpow(sx,rb.F), rb.S);
        ans = mul(ans, aa);
        bns = mul(bns, bb);
    }
    for (const auto & e : g[u]) {
        int v = e.F;
        if (dead[v] || v == p)
            continue;
        int x = e.S >> 1;
        int c = e.S & 1;
        dfs(v,u,x1+c,y1+!c,mul(sx,x));
    }
}
void DC(int u)
{
    getsz(u);
    int n = sz[u];
    u = cent(u,n);
    fa.init(n);
    fb.init(n);
    fa.upd(0,1);
    fb.upd(0,1);
    for (const auto & e : g[u]) {
        int v = e.F;
        if (dead[v])
            continue;
        int x = e.S >> 1;
        int c = e.S & 1;
        cx.clear();
        dfs(v,u,c,!c,x);
        for (const auto & p:cx) {
            fa.upd(p.F.F,p.S);
            fb.upd(p.F.S,p.S);
        }
    }
    dead[u] = 1;
    for (const auto & e : g[u]) {
        int v = e.F;
        if (dead[v])
            continue;
        DC(v);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int u,v,x,c;
        cin >> u >> v >> x >> c;
        g[u].emplace_back(v,x<<1|c);
        g[v].emplace_back(u,x<<1|c);
    }
    ans = bns = 1;
    DC(1);
    cout << mul(ans,qpow(bns,M-2)) << endl;
}
