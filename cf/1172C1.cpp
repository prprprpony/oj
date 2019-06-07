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
const int N = 55, K = 55, M = 998244353;
int n,k,a[N],w[N];
const int V = 3000;
ll fi[V];
void pre()
{
    fi[0] = fi[1] = 1;
    for (int i = 2; i < V; ++i)
        fi[i] = (M-M/i) * fi[M%i] % M;
}
ll inv(ll x)
{
    assert(0 < x && x < V);
    return fi[x];
}
ll dp[K][K][N][K],ans[N];
ll g(ll x,ll y) {return x * inv(y) % M;}
int main()
{
    pre();
    RD(n,k);
    RP(i,n) {
        RD(a[i]);
        if (a[i] == 0)
            a[i] = -1;
    }
    int p=0,q=0;
    RP(i,n) {
        RD(w[i]);
        if (a[i] > 0)
            p += w[i];
        else
            q += w[i];
    }
    for (int i = 0; i < n; ++i) {
        dp[0][0][i][0] = 1;
        ans[i] = w[i];
    }
    for (int x = 0; x <= k; ++x)
        for (int y = 0; x + y <= k && y <= q; ++y)
            if (x || y) {
                for (int i = 0; i < n; ++i) {
                    for (int t = 0; t <= (a[i]>0?x:min(y,w[i])); ++t) {
                        ll & d = dp[x][y][i][t];
                        if (x)
                            d += dp[x-1][y][i][t] * g(p+x-1-(a[i]>0?w[i]+t:0),p+q+x-1-y) % M;
                        if (y)
                            d += dp[x][y-1][i][t] * g(q-(y-1)-(a[i]<0?w[i]-t:0),p+q+x-(y-1)) % M;
                        if (t) {
                            if (a[i] > 0)
                                d += dp[x-1][y][i][t-1] * g(w[i]+t-1,p+x-1+q-y) % M;
                            else
                                d += dp[x][y-1][i][t-1] * g(w[i]-(t-1),p+x+q-(y-1)) % M;
                        }
                        d %= M;
                        if (x + y == k)
                            ans[i] += t * a[i] % M * d % M;
                    }
                }
            }
    RP(i,n) {
        PL((ans[i] % M + M) %M);
    }
}
