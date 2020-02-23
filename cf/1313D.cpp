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
    int n, m, k;
    cin >> n >> m >> k;
    vector<pii> s(n);
    vector<int> v;
    for (auto & p : s) {
        cin >> p.F >> p.S;
        v.PB(p.F);
        v.PB(++p.S);
    }
    sort(ALL(v));
    v.resize(unique(ALL(v)) - begin(v));
    sort(ALL(s));
    int vn = v.size();
    vector<vector<int>> covid(vn);
    for (int i = 0; i < n; ++i)
        for (int j = lower_bound(ALL(v), s[i].F) - begin(v); v[j] < s[i].S; ++j)
            covid[j].push_back(i);
    array<int, (1 << 8) > dp, nxt;
    nxt.fill(0);
    vector<int> vis(n);
    int vcnt = 0;
    int ans = 0;
    for (int i = 0; i < vn; ++i) {
        int w = covid[i].size();
        if (w == 0) {
            ans += nxt[0];
            nxt.fill(0);
            continue;
        }
        swap(dp, nxt);
        nxt.fill(0);
        {
            int j;
            for (j = 0; j < w; ++j)
                if (s[covid[i][j]].F == v[i])
                    break;
            if (j < w)
                for (int s = 0; s < (1 << j); ++s)
                    for (int t = 0; t < (1 << (w - j)); ++t)
                        cmax(dp[t << j | s], dp[s]);
        }
        for (int s = 0; s < (1 << w); ++s) {
            dp[s] += __builtin_popcount(s) % 2 * (v[i + 1] - v[i]);
            ++vcnt;
            for (int j = 0; j < w; ++j)
                if (s >> j & 1)
                    vis[covid[i][j]] = vcnt;
            int t = 0;
            for (int j = 0; j < covid[i + 1].size(); ++j)
                t |= vis[covid[i + 1][j]] == vcnt ? 1 << j : 0;
            cmax(nxt[t], dp[s]);
        }
    }
    cout << ans << endl;
}
