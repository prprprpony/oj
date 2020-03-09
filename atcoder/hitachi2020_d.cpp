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
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll T;
    cin >> n >> T;
    vector<pll> p;
    vector<ll> vs = {0};
    for (int i = 0; i < n; ++i) {
        pll a;
        cin >> a.F >> a.S;
        if (a.F == 0)
            vs.push_back(a.S + 1);
        else
            p.push_back(a);
    }
    sort(ALL(p), [] (pll a, pll c) {
        ll d = c.F * (a.S + 1) - a.F * (c.S + 1);
        if (d) return d < 0;
        return a < c;
    });
    sort(ALL(vs));
    for (int i = 1; i < vs.size(); ++i)
        vs[i] += vs[i - 1];
    n = p.size();
//    for (int i = 0; i < n; ++i) BG(i, p[i].F, p[i].S, p[i].F / (p[i].S + 1.));
    auto f = [] (pll a, ll x) {return (x + 1) * (a.F + 1) + a.S;};
    vector<ll> dp = {0};
    for (auto a : p) {
        dp.push_back(T + 1);
        for (int i = dp.size() - 2; i >= 0; --i)
            cmin(dp[i + 1], f(a, dp[i]));
        if (dp.back() > T)
            dp.pop_back();
    }
    int ans = 0;
    for (int i = 0; i < dp.size(); ++i)
        ans = max(ans, (int)(upper_bound(ALL(vs), T - dp[i]) - begin(vs)) - 1 + i);
    cout << ans << endl;
}
