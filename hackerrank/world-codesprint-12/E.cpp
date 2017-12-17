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
const int N = 5e4 + 514;
int m,n,s[N];
struct segt
{
    struct node
    {
        int mx,tg;
    } t[N*4];
    void init()
    {
        memset(t+1,0,m*4*sizeof(t[0]));
    }
    void add(int o,int v)
    {
        t[o].tg += v;
        t[o].mx += v;
    }
    void push(int o)
    {
        if (t[o].tg) {
            add(o<<1,t[o].tg);
            add(o<<1|1,t[o].tg);
            t[o].tg = 0;
        }
    }
    void pull(int o)
    {
        t[o].mx = max(t[o<<1].mx, t[o<<1|1].mx);
    }
    void add(int i,int j,int v,int o=1,int l=1,int r=m+1)
    {
        if (j <= l || r <= i)
            return;
        if (i <= l && r <= j) {
            add(o,v);
            return;
        }
        int mi = l + r >> 1;
        push(o);
        add(i,j,v,o<<1,l,mi);
        add(i,j,v,o<<1|1,mi,r);
        pull(o);
    }
    int qry(int i,int j,int o=1,int l=1,int r=m+1)
    {
        if (j <= l || r <= i)
            return 0;
        if (i <= l && r <= j)
            return t[o].mx;
        int mi = l + r >> 1;
        push(o);
        return max(qry(i,j,o<<1,l,mi), qry(i,j,o<<1|1,mi,r));
    }
} dp[2];
bool ty[N];
vi g[N];
int ans[N];
void init()
{
    RP1(i,m) g[i].clear(); 
    fill_n(ans+1,n,-1);
}
void solve()
{
    RD(m,n);
    init();
    RP(i,n) {
        DR(char,c);
        ty[i] = c == 'E' || c == 'C';
    }
    RP(i,n) RD(s[i]);
    RP(i,n) {
        RI(d);
        if (s[i] < d)
            g[d].PB(i);
    }
    RP(k,2) dp[k].init();
    int la = 0;
    REP1(i,2,m) {
        for (int x : g[i])
            dp[ty[x]].add(1,s[x]+1,1);
        int w = 0;
        RP(k,2) cmax(w, dp[k].qry(1,m+1));
        RP(k,2) dp[k].add(i,i+1,w);
        if (w > la) {
            fill(ans+la+1,ans+w+1,i);
            la = w;
        }
    }
    RP1(i,n) PL<0,0>(ans[i]," \n"[i==n]);
}
int main()
{
    RI(T);
    while (T--) solve();
}
