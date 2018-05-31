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
const int N = 1e5 + 87, C = 1e7 + 87, M = 1e9 + 7;
int lp[C];
vector<int> pm;
void pre()
{
    for (int i = 2; i < C; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pm.PB(i);
        }
        for (int j : pm) {
            if (i * j >= C)
                break;
            lp[i * j] = j;
            if (j == lp[i])
                break;
        }
    }
}
int qpow(ll a,int b)
{
    ll r = 1;
    for (; b; b>>=1, a = a * a % M)
        if (b&1)
            r = r * a % M;
    return r;
}
void dec(int x,vector<pii> & v)
{
    v.clear();
    for (; x > 1; x /= lp[x]) {
        if (!SZ(v) || v.back().F != lp[x]) {
            v.EB(lp[x],1);
        } else {
            ++BK(v).S;
        }
    }
}
int a[N],n,ans[N];
pii qr[N];
vi g[N];
int sz[N],pa[N],idx[N],tp,hd[N],de[N],fen[N];
void dfs(int p,int u)
{
    sz[u] = 1;
    pa[u] = p;
    de[u] = de[p] + 1;
    int mx = 0;
    for (int & v : g[u]) {
        if (v == p)
            continue;
        dfs(u,v);
        sz[u] += sz[v];
        if (sz[v] > mx) {
            mx = sz[v];
            swap(g[u][0],v);
        }
    }
}
void bld(int u)
{
    idx[u] = ++tp;
    if (!hd[u])
        hd[u] = u;
    for (int v : g[u]) if (v != pa[u]) {
        if (v == g[u][0])
            hd[v] = hd[u];
        bld(v);
    }
}
void add(int u,int x)
{
    for (int i = idx[u]; i <= n; i += i & -i)
        fen[i] += x;
}
int sum(int i)
{
    int ret = 0;
    for (; i; i ^= i & - i)
        ret += fen[i];
    return ret;
}
int sum(int u,int v)
{
    return sum(idx[v]) - sum(idx[u]-1);
}
int qry(int u,int v)
{
    int ret = 0;
    while (hd[u] != hd[v]) {
        if (de[hd[u]] < de[hd[v]])
            swap(u,v);
        ret += sum(hd[u],u);
        u = pa[hd[u]];
    }
    if (de[u] < de[v])
        swap(u,v);
    ret += sum(v,u);
    return ret;
}
int main()
{
    pre();
    RD(n);
    RP(i,n-1) {
        RI(u,v);
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs(1,1);
    bld(1);
    vector<pair<int, pii> > ev;
    vector<pii> tm;
    RP1(i,n) {
        RD(a[i]);
        dec(a[i],tm);
        for (auto & x : tm) {
            x.F *= 100;
            RP(j,x.S) {
                ev.EB(x.F+j, pii(1,i));
                ev.EB(x.F+j, pii(-1,i));
            }
        }
    }
    RI(q);
    fill_n(ans,q,1);
    RP(i,q) {
        int x;
        RD(qr[i].F,qr[i].S,x);
        dec(x,tm);
        for (auto & e : tm) {
            e.F *= 100;
            RP(j,e.S) {
                ev.EB(e.F+j, pii(0,i));
            }
        }
    }
    sort(ALL(ev));
    reverse(ALL(ev));
    for (const auto & e : ev) {
        int ty, u;
        tie(ty,u) = e.S;
        if (ty != 0) {
            add(u,ty);
        } else {
            int w = qry(qr[u].F,qr[u].S);
            ans[u] = ans[u] * 1LL * qpow(e.F/100,w) % M;
        }
    }
    RP(i,q) PL(ans[i]);
}
