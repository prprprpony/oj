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
const double PI = acos(-1);
struct pt
{
    double x, y;
} p[22];
double a[22], ca[22], sa[22], dp[1 << 20];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y >> a[i];
        a[i] = a[i] / 180 * PI;
        ca[i] = cos(a[i]);
        sa[i] = sin(a[i]);
    }
    fill_n(dp, 1 << n, l);
    for (int S = 0; S < (1 << n); ++S) {
        for (int i = 0; i < n; ++i)
            if ((S & (1 << i)) == 0) {
                pt v = {dp[S] - p[i].x, -p[i].y};
                pt u = {ca[i] * v.x - sa[i] * v.y, sa[i] * v.x + ca[i] * v.y};
                if (abs(u.y) < 1e-9 || u.y >= 0) {
                    dp[S | (1 << i)] = r;
                    continue;
                }
                double k = -p[i].y / u.y;
                double x = p[i].x + k * u.x;
                dp[S | (1 << i)] = min(max(dp[S | (1 << i)], x), (double)r);
            }
    }
    cout << fixed << setprecision(16) << dp[(1 << n) - 1] - l << endl;
}
