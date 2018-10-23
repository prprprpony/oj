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
const int N = 1e5 + 87;
const ll inf = 1e16;
struct line
{
    ll m,k;
    ll operator () (ll x)
    {
        return m * x + k;
    }
} dp[N];
struct seg
{
    int sz;
    line f;
    seg * lc, * rc;
    seg(line k) : sz(1), f(k), lc(nullptr), rc(nullptr) {}
};
int sz(seg * t) {return t?t->sz:0;}
void upd(seg*& t,line nf,int l=-N,int r=N)
{
    if (!t) {
        t = new seg(nf);
        return;
    }
    int m = (l + r) / 2;
    if (nf(m) < t->f(m))
        swap(nf,t->f);
    if (r - l == 1)
        return;
    if (nf(l) < t->f(l))
        upd(t->lc,nf,l,m);
    else if (nf(r-1) < t->f(r-1))
        upd(t->rc,nf,m,r);
    t->sz = 1 + sz(t->lc) + sz(t->rc);
}
ll qry(seg * t,int x,int l=-N,int r=N)
{
    if (!t)
        return inf;
    ll ret = t->f(x);
    if (r - l > 1) {
        int m = (l + r) / 2;
        if (x <= m)
            ret = min(ret, qry(t->lc,x,l,m));
        else
            ret = min(ret, qry(t->rc,x,m,r));
    }
    return ret;
}
void meld_walk(seg *& a, seg * b)
{
    if (!b)
        return;
    upd(a,b->f);
    meld_walk(a,b->lc);
    meld_walk(a,b->rc);
    delete b;
}
seg * meld(seg * a,seg * b)
{
    if (!a || !b)   
        return a?a:b;
    if (sz(a) < sz(b))
        swap(a,b);
    meld_walk(a,b);
    return a;
}
int a[N];
vi g[N];
seg* dfs(int p,int u)
{
    seg * rt = nullptr;
    for (int v : g[u])
        if (v != p)
            rt = meld(rt, dfs(u,v));
    dp[u].k = rt ? qry(rt,a[u]) : 0;
    upd(rt,dp[u]);
    return rt;
}
int main()
{
    RI(n);
    RP(i,n) RD(a[i]);
    RP(i,n) RD(dp[i].m);
    RP(i,n-1) {
        RI(u,v);
        --u,--v;
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs(0,0);
    RP(i,n) PL<0,0>(dp[i].k," \n"[i==n-1]);
}
