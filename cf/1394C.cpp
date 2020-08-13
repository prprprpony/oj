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
const int inf = 1e7;
pii ans;
struct pos
{
    int xl, xr;
    int yl, yr;
    int xyl, xyr;
    pos() {}
    pos(int a, int b, int c, int d, int e, int f) : xl(a), xr(b), yl(c), yr(d), xyl(e), xyr(f) {}
    pos operator + (const pos & r) const
    {
        return pos(max(xl, r.xl), min(xr, r.xr),
                   max(yl, r.yl), min(yr, r.yr),
                   max(xyl, r.xyl), min(xyr, r.xyr));
    }
    bool ok()
    {
        if (xl > xr || yl > yr || xyl > xyr)
            return 0;
        for (int x : {xl, xr}) {
            int l=max(yl,x-xyr);
            int r=min(yr, x-xyl);
            if (l <= r) {
                ans={x,l}; return 1;
            }
        }
        for (int y : {yl, yr})  {
            int l=max(xl,y+xyl);
            int r=min(xr, y+xyr);
            if (l <= r) {
                ans={l,y}; return 1;
            }
        }
        return 0;
    }
};
int n;
vector<pii> p;
pos va,vb;
bool ok(int d)
{
    va = pos(1, inf, 0, inf, -inf, inf);
    vb = pos(0,inf,1,inf,-inf,inf);
    for (auto [x, y] : p) {
        pos t(x - d, x + d, y - d, y + d, x - y - d, x - y + d);
        va = va + t;
        vb = vb + t;
    }
    return va.ok() || vb.ok();
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int x = 0, y = 0;
        for (char c : s)
            if (c == 'B')
                ++x;
            else
                ++y;
        p.emplace_back(x, y);
    }
    int lo = 0, hi = 1e7;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        if (ok(mi))
            hi = mi - 1;
        else
            lo = mi + 1;
    }
    cout << lo << endl << string(ans.F, 'B') + string(ans.S, 'N') << endl;
}

