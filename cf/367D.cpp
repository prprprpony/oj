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
const int N = 1e5 + 87;
const int M = 20;
int n, m, d, a[N], cnt[20];
bool bad[1 << 20];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> d;
    for (int i = 0; i < m; ++i) {
        int w;
        cin >> w;
        for (int j = 0; j < w; ++j) {
            int x;
            cin >> x;
            a[x - 1] = i;
        }
    }
    for (int i = 0; i < d; ++i)
        cnt[a[i]]++;
    for (int i = d; i <= n; ++i) {
        int mask = 0;
        for (int j = 0; j < m; ++j)
            if (cnt[j] == 0)
                mask |= 1 << j;
        bad[mask] = 1;
        if (i < n)
            cnt[a[i]]++;
        cnt[a[i - d]]--;
    }
    int ans = m;
    for (int s = (1 << m) - 1; s; s--) {
        if (!bad[s]) {
            ans = min(ans, __builtin_popcount(s));
            continue;
        }
        for (int j = 0; j < m; ++j)
            if (s >> j & 1)
                bad[s ^ (1 << j)] = 1;
    }
    cout << ans << endl;
}
