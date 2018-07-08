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
const int N = 1e6 + 87;
vector<pii> g[N],sg[N];
int tin[N],low[N],dfn,st[N],tp,ons[N],scn,sid[N];
vi scc[N];
ll dp[N],wt[N];
void dfs(int u)
{
    tin[u] = low[u] = ++dfn;
    ons[st[tp++] = u] = 1;
    for (pii e : g[u]) {
        int v = e.F;
        if (tin[v]) {
            if (ons[v]) {
                cmin(low[u],tin[v]);
            }
        } else {
            dfs(v);
            cmin(low[u],low[v]);
        }
    }
    if (low[u] == tin[u]) {
        int v;
        int k = ++scn;
        do {
            v = st[--tp];
            ons[v] = 0;
            sid[v] = k;
            scc[k].PB(v);
        } while (v != u);
    }
}
ll gg(ll x)
{
    return x * (x + 1) / 2;
}
ll f(ll x)
{
    ll lo = 0, hi = 1;
    while (gg(hi) <= x)
        hi <<= 1;
    while (lo <= hi) {
        ll mi = (lo + hi) / 2;
        if (gg(mi) <= x)
            lo = mi + 1;
        else
            hi = mi - 1;
    }
//    BG(x,hi,gg(hi));
    ll n = hi;
    return x * (n + 1) - ((n+1)*(n+1)*n/2 - n*(n+1)*(2*n+1)/6);
}
int main()
{
    RI(n,m);
    RP(i,m) {
        RI(x,y,w);
        g[x].EB(y,w);
    }
    RI(s);
    dfs(s);
    RP1(i,scn) {
        for (int u : scc[i])  {
            for (pii e : g[u]) {
                int v = e.F;
                int j = sid[v];
                if (!j)
                    continue;
                if (i == j) {
                    wt[i] += f(e.S);
 //                   BG(e.S,f(e.S));
                } else {
                    cmax(dp[i], e.S + dp[j]);
                }
            }
        }
        dp[i] += wt[i];
    }
    PL(dp[scn]);
}
