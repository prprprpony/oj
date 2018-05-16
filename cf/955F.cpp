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
const int N = 3e5 + 87;
int n;
struct dp
{
    vi v;
    ll s;
    void upd(int i,int x)
    {
        if (SZ(v) <= i)
            v.resize(i+1);
        int y = max(v[i],x);
        s += y - v[i];
        v[i] = y;
    }
    void join(dp & x)
    {
        if (x.v.size() > v.size()) {
            s = x.s;
            v.swap(x.v);
        }
        RP(i,SZ(x.v)) 
            upd(i,x.v[i]);
    }
    ll sum()
    {
        return s + n - SZ(v);
    }
    void dbg(int u)
    {
        RP(i,SZ(v))
            cerr << "dp[" << i+1 << "]["<<u<<"]="<<v[i]<<endl;
        REP(i,SZ(v),n)
            cerr << "dp[" << i+1 << "]["<<u<<"]="<<1<<endl;
    }
} d[N];
vi g[N],ans[N];
ll dfs(int p,int u)
{
    int k = SZ(g[u]) + (p ? -1 : 0);
    vector<priority_queue<int,vi,greater<int>>> pq(k);
    ll sum = 0;
    for (int v : g[u])
        if (v != p) {
            sum += dfs(u,v);
            d[u].join(d[v]);
            RP(i,min(k,SZ(ans[v]))) {
                pq[i].push(ans[v][i]);
                if (SZ(pq[i]) == i + 2)
                    pq[i].pop();
            }
        }
    ans[u].resize(k);
    RP(i,k)
        d[u].upd(i, ans[u][i] = SZ(pq[i]) == i + 1 ? pq[i].top() + 1 : 2);
//    RP(i,k) cerr << "ans[" << i+1 << "]["<<u<<"]="<<ans[u][i]<<endl;
//    d[u].dbg(u);
    return sum + d[u].sum();
}
int main()
{
    RD(n);
    DO(n-1) {
        RI(u,v);
        g[u].PB(v);
        g[v].PB(u);
    }
    PL(dfs(0,1));
}
