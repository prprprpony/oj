#include <bits/stdc++.h>
using namespace std;
/* nichijou */
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
/* Good Luck && Have Fun ! */
const int N = 2e5 + 87, M = 35, MOD = 998244353;
int n, m, r;
ll a[N], b[M];
int p[1 << (M / 2)][M / 2 + 1], ans[M + 1];
void bf()
{
    for (ll v = 0; v < (1 << m); ++v) {
        ll x = v;
        for (int j = m - 1; j >= 0; --j)
            if ((x & (1ll << j)) && b[j])
                x ^= b[j];
        int k = __builtin_popcount(v);
        if (x == 0)
            (ans[k] += 1) %= MOD;
    }
}
void solve()
{
    int t = m / 2;
    for (ll v = 0; v < (1 << t); ++v) {
        ll x = v;
        for (int j = t - 1; j >= 0; --j)
            if ((x & (1ll << j)) && b[j])
                x ^= b[j];
        p[x][__builtin_popcount(v)]++;
    }
    for (ll v = 0; v < (1 << (m - t)); ++v) {
        ll x = v << t;
        for (int j = m - 1; j >= 0; --j)
            if ((x & (1ll << j)) && b[j])
                x ^= b[j];
        int k = __builtin_popcount(v);
        if (x < (1 << t))
            for (int i = 0; i <= t; ++i)
                (ans[i + k] += p[x][i]) %= MOD;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ll x = a[i];
        for (int j = m - 1; j >= 0; --j)
            if (x & (1ll << j)) {
                if (b[j]) {
                    x ^= b[j];
                } else {
                    b[j] = x;
                    ++r;
                    break;
                }
            }
    }
    solve();
    //bf();
    ll p2 = 1;
    for (int i = 0; i < n - r; ++i)
        p2 = p2 * 2 % MOD;
    for (int i = 0; i <= m; ++i)
        cout << ans[i] * p2 % MOD << " \n"[i == m];
}
