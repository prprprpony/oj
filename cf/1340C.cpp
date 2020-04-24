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
const int N = 1e6 + 87, M = 1e4 + 87, T = 1020;
const ll inf = 0x3f3f3f3f;
int d[M][T];
vector<int> a;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        a.PB(x);
    }
    int G, R;
    cin >> G >> R;
    const int S = G + R;
    sort(ALL(a));
    memset(d, 0x3f, sizeof d);
    d[0][0] = 0;
    deque<tuple<int, int, int>> qu;
    qu.emplace_back(0, 0, 0);
    while (qu.size()) {
        int w, i, j;
        tie(w, i, j) = qu.front();
        qu.pop_front();
        if (w != d[i][j])
            continue;
        if (j == G && cmin(d[i][0], w + R))
            qu.emplace_back(w + R, i, 0);
        auto gao = [&] (int j) {
            int l = w;
            int r = w + abs(a[j] - a[i]);
            if (r - l > G)
                return;
            int lm = l % S, rm = r % S;
            if (lm <= rm && rm <= G && cmin(d[j][rm], r))
                qu.emplace_front(r, j, rm);
        };
        gao(i + 1);
        if (i)
            gao(i - 1);
    }
    int ans = *min_element(d[m - 1], d[m - 1] + G + 1);
    if (ans == inf)
        ans = -1;
    cout << ans << endl;
}
