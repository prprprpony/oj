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
    int n, m, a;
    cin >> n >> m >> a;
    vector<int> b(n), p(m);
    for (int & x : b)
        cin >> x;
    for (int & x : p)
        cin >> x;
    sort(b.rbegin(), b.rend());
    sort(p.begin(), p.end());
    int l = 0, r = min(n, m);
    while (l <= r) {
        int k = (l + r) / 2;
        ll w = 0;
        for (int i = 0; i < k; ++i) {
            int pm = b[k - 1 - i];
            if (pm < p[i])
                w += p[i] - pm;
        }
        if (w <= a) 
            l = k + 1;
        else 
            r = k - 1;
    }
    const int R = r;
    ll w = 0, wp = 0;
    for (int i = 0; i < R; ++i) {
        int pm = b[R - 1 - i];
        if (pm < p[i]) {
            w += p[i] - pm;
            wp += pm;
        } else {
            wp += p[i];
        }
    }
    a -= w;
    wp = max(0ll, wp - a);
    cout << R << ' ' << wp << endl;
}
