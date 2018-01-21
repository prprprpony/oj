#include <bits/stdc++.h>
using namespace std;
// nichijou
#define REP(i,a,b) for (int i(a); i < (b); ++i)
#define RP(i,n) REP(i,0,n)
#define PER(i,a,b) for(int i((a)-1); i >= (b); --i)
#define PR(i,n) PER(i,n,0)
#define REP1(i,a,b) REP(i,a,(b)+1)
#define RP1(i,n) REP1(i,1,n)
#define PER1(i,a,b) PER(i,(a)+1,b)
#define PR1(i,n) PER1(i,n,1)
#define DO(n) RP(__i,n)
template<class T,class U>
bool cmax(T & a, const U & b) {return a < b ? a = b, 1 : 0;}
template<class T,class U>
bool cmin(T & a, const U & b) {return b < a ? a = b, 1 : 0;}

// data type
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define F first
#define S second

// STL container
typedef vector<int> vi;
typedef vector<ll> vll;
#define SZ(a) ((int)(a).size())
#define ALL(a) begin(a), end(a)
#define CLR(a) (a).clear()
#define BK(a) ((a).back())
#define FT(a) ((a).front())
#define DB(a) (a).pop_back()
#define DF(a) (a).pop_front()
#define PB push_back
#define EB emplace_back

/* I gave you my heart and then you turned around. */
void _BG(const char * s) {cerr<<s<<endl;};
template<class T, class ... TT>
void _BG(const char * s,T a, TT...b)
{
	for (int c = 0; *s && (c || *s != ','); ++s) {
		cerr<<*s;
		for (char x : "([{") c += *s == x;
		for (char x : ")]}") c -= *s == x;
	}
	cerr<<" = "<<a;
	if (sizeof...(b)) {
		cerr<<", ";
        ++s;
    }
    _BG(s,b...);
}
#define BG(...) do { \
	cerr << __PRETTY_FUNCTION__ << ':' << __LINE__ << ": "; \
	_BG(#__VA_ARGS__,__VA_ARGS__); \
} while(0)

/* Reading input is now 20% cooler! */
bool RD() {return 1;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(int & a) {return scanf("%d", &a) == 1;}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}

template<class T, class ... TT>
bool RD(T & a, TT & ... b) {return RD(a) && RD(b...);}

/* Do princesses dream of magic sheep? */
#define DR(T,...) T __VA_ARGS__; RD(__VA_ARGS__)
#define RI(...) DR(int,__VA_ARGS__)

/* For it's time for you to fulfill your output. */
void PT(const char & a) {putchar(a);}
void PT(char const * const & a) {fputs(a, stdout);}
void PT(const double & a) {printf("%.16f", a);}
void PT(const int & a) {printf("%d", a);}
void PT(const ll & a) {printf("%lld", a);}

/* The line will last forever! */
template<char s = ' ', char e = '\n'>
void PL() {if (e) PT(e);}
template<char s = ' ', char e = '\n', class T, class ... TT>
void PL(const T & a, const TT & ... b)
{PT(a); if (sizeof...(b) && s) PT(s); PL<s,e>(b...);}

/* Good Luck && Have Fun ! */
const int N = 1e5 + 987;
struct node
{
    ll s,tg;
} t[N*4];
int a[N],sz[N],de[N],pa[N],tp,hd[N],hc[N],n,q,rt=1;
vi g[N],hv[N];
pii rg[N];
#define LC o<<1,l,m
#define RC o<<1|1,m,r
#define T t[o]
#define L t[o<<1]
#define R t[o<<1|1]
void dat(int o,int l,int r,ll x)
{
    T.tg += x;
    T.s += (r - l) * x;
}
void push(int o,int l,int m,int r)
{
    if (T.tg) {
        dat(LC,T.tg);
        dat(RC,T.tg);
        T.tg = 0;
    }
}
void pull(int o)
{
    T.s = L.s + R.s;
}
void add(int i,int j,ll x,int o = 1,int l = 0,int r = n)
{
    if (j <= l or r <= i)
        return;
    if (i <= l and r <= j) {
        dat(o,l,r,x);
        return;
    }
    int m = l + r >> 1;
    push(o,l,m,r);
    add(i,j,x,LC);
    add(i,j,x,RC);
    pull(o);
}
ll qry(int i,int j,int o = 1,int l = 0,int r = n)
{
    if (j <= l or r <= i)
        return 0;
    if (i <= l and r <= j)
        return T.s;
    int m = l + r >> 1;
    push(o,l,m,r);
    return qry(i,j,LC) + qry(i,j,RC);
}
void gsz(int p,int u)
{
    pa[u] = p;
    sz[u] = 1;
    de[u] = de[p] + 1;
    RP(i,SZ(g[u])) {
        int & v = g[u][i];
        if (v == p) {
            v = BK(g[u]);
            DB(g[u]);
            --i;
            continue;
        }
        gsz(u,v);
        sz[u] += sz[v];
        if (sz[v] > sz[g[u][0]])
            swap(v, g[u][0]);
    }
}
void dfs(int u)
{
    add(tp,tp+1,a[u]);
    rg[u].F = tp++;
    hd[u] = u == g[pa[u]][0] ? hd[pa[u]] : u;
    hc[hd[u]] = tp;
    hv[hd[u]].PB(u);
    for (int v : g[u])
        dfs(v);
    rg[u].S = tp;
}
int lca(int u,int v)
{
    while (hd[u] != hd[v]) {
        if (de[hd[u]] < de[hd[v]])
            swap(u,v);
        u = pa[hd[u]];
    }
    return de[u] < de[v] ? u : v;
}
int up(int u,int k)
{
    while (de[u] - de[hd[u]] + 1 <= k) {
        k -= de[u] - de[hd[u]] + 1;
        u = pa[hd[u]];
    }
    return hv[hd[u]][de[u] - de[hd[u]] - k];
}
int main()
{
    RD(n,q);
    RP1(i,n) RD(a[i]);
    RP(i,n-1) {
        RI(u,v);
        g[u].PB(v);
        g[v].PB(u);
    }
    g[0] = {0};
    gsz(0,1);
    dfs(1);
    while (q--) {
        RI(ty,u);
        if (ty == 1) {
            rt = u;
        } else if (ty == 2) {
            RI(v,x);
            int w = lca(u,v);
            if (!(rg[w].F <= rg[rt].F and rg[rt].S <= rg[w].S)) {
                add(rg[w].F,rg[w].S,x);
            } else {
                u = lca(rt,u), v = lca(rt,v);
                if (de[u] < de[v])
                    swap(u,v);
                add(0,n,x);
                if (u != rt) {
                    v = up(rt, de[rt] - de[u] - 1);
                    add(rg[v].F,rg[v].S,-x);
                }
            }
        } else {
            int p = lca(rt,u);
            if (p == u) {
                if (u == rt)
                    PL(qry(0,n));
                else {
                    int v = up(rt, de[rt] - de[p] - 1);
                    PL(qry(0,n) - qry(rg[v].F,rg[v].S));
                }
            } else {
                PL(qry(rg[u].F,rg[u].S));
            }
        }
    }
}
