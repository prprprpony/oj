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
const int N = 1e6 + 87, MOD = 1e9 + 7;
pii a[N];
ll dp[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    ll m;
    cin >> n >> m >> k;
    ll q = m / n, r = m % n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].F;
        a[i].S = i;
    }
    sort(a, a + n);
    ll ans = 0;
    for (int x = 1; x <= k && x <= q + (r > 0); ++x) {
        ll cq1 = x <= q ? (q - x + 1) % MOD : 0;
        ll sum = x == 1 ? 1 : 0;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && a[j].F <= a[i].F)
                (sum += dp[j++]) %= MOD;
            dp[i] = sum;
            ans += dp[i] * cq1 % MOD;
            if (a[i].S < r)
                ans += dp[i];
        }
    }
    cout << ans % MOD << endl;
}
