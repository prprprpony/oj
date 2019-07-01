#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
/* nichijou */
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
/* data type */
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define F first
#define S second
/* STL container */
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
/* pb_ds */
#define umap_t __gnu_pbds::gp_hash_table
// umap_t<key_type,value_type,key_hasher_functor>
#define heap_t __gnu_pbds::priority_queue
// heap_t<value_type,compare_functor>
// h1.join(h2); assert(h2.empty());
template<class T>
using set_t = __gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
// s.order_of_key(k) number of element less than k
// s.find_by_order(k) 0-based
/* I gave you my heart and then you turned around. */
void _BG(const char * s) {cerr<<s<<endl;}
template<class T, class ... TT>
void _BG(const char * s,T a, TT...b)
{
    for (size_t c = 0; *s && (c || *s != ','); cerr << *s++)
        c += count(ALL("([{"),*s) - count(ALL(")]}"),*s);
    cerr << " = " << a;
    if (*s) {
        cerr << ", ";
        ++s;
    }
    _BG(s,b...);
}
#ifdef PR3PONY
#define BG(...) do { \
    cerr << __PRETTY_FUNCTION__ << ':' << __LINE__ << ": "; \
    _BG(#__VA_ARGS__,__VA_ARGS__); \
} while(0)
#else
#define BG(...)
#endif
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
const ll N = 2e5+87, M=1e9+7;
ll qpow(ll a,ll b)
{
    ll r=1;
    for(;b;b>>=1,a=a*a%M)
        if(b&1)r=r*a%M;
    return r;
}
ll inv[N],n,c[N],l[N],r[N],w[N];
ll eq(int i,int j)
{
    ll x = max(l[i],l[j]);
    ll y = min(r[i],r[j]);
    ll u = max(0ll,y-x+1);
    return u * inv[i] % M * inv[j] % M;
}
ll f(int i,int j,int k)
{
    if (min({i,j,k})<0||max({i,j,k})>=n)
        return 0;
    ll a=1-eq(i,j)-eq(j,k);
    ll x = max({l[i],l[j],l[k]});
    ll y = min({r[i],r[j],r[k]});
    ll u = max(0ll,y-x+1);
    a += u * inv[i] % M * inv[j] % M * inv[k] % M;
    return a%M;
}
int main()
{
    RD(n);
    RP(i,n) RD(l[i]);
    RP(i,n) {
        RD(r[i]);
        w[i] = r[i] - l[i] + 1;
        inv[i] = qpow(w[i], M-2);
    }
    REP(i,1,n)
        c[i] = 1 - eq(i,i-1);
    ll tot = accumulate(c+1,c+n,0ll) % M;
    ll ans = 1 + 2*tot;
    REP(i,1,n) {
        ans += c[i] * (tot - c[i] - c[i-1] - c[i+1] + 1) % M;
        ans += f(i-1,i,i+1) + f(i-2,i-1,i);
    }
    ans = (ans % M + M) % M;
    PL(ans);
}
