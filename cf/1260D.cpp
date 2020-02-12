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
const int N = 2e5 + 87;
int s[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, n, k, t;
    cin >> m >> n >> k >> t;
    vi a(m);
    for (int & x : a)
        cin >> x;
    sort(ALL(a), greater<int>());
    typedef array<int, 3> nd;
    vector<nd> trap(k);
    for (auto & p : trap)
        cin >> p[1] >> p[2] >> p[0];
    int lo = 1, hi = m;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        fill_n(s, n + 1, 0);
        for (const auto & p : trap)
            if (p[0] > a[mi - 1])
                ++s[p[1] - 1], --s[p[2]];
        int co = n + 1;
        for (int i = 0; i <= n; ++i) {
            s[i + 1] += s[i];
            co += 2 * (s[i] > 0);
        }
        if (co <= t)
            lo = mi + 1;
        else
            hi = mi - 1;
    }
    cout << hi << endl;
}
