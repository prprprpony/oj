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
const int D = __lg(N) + 1;
vi g[N];
int pa[N][D], de[N];
void dfs(int p, int u)
{
    de[u] = de[p] + 1;
    pa[u][0] = p;
    for (int i = 1; i < D; ++i)
        pa[u][i] = pa[pa[u][i - 1]][i - 1];
    for (int v : g[u])
        if (v != p)
            dfs(u, v);
}
int lca(int u, int v)
{
    if (de[u] < de[v])
        swap(u, v);
    for (int d = de[u] - de[v], k = 0; d; d >>= 1, ++k)
        if (d & 1)
            u = pa[u][k];
    if (u == v)
        return v;
    for (int k = D - 1; k >= 0; --k)
        if (pa[u][k] != pa[v][k])
            u = pa[u][k], v = pa[v][k];
    return pa[u][0];
}
int dist(int u, int v)
{
    int w = lca(u, v);
    return de[u] + de[v] - 2 * de[w];
}
bool solve()
{
    int x, y, a, b, k;
    cin >> x >> y >> a >> b >> k;
    int d[3] = {dist(a, b), dist(a, x) + 1 + dist(y, b), dist(b, x) + 1 + dist(y, a)};
    for (int e : d)
        if (k % 2 == e % 2 && k >= e)
            return 1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs(0, 1);
    int q;
    cin >> q;
    while (q--)
        cout << (solve() ? "YES\n" : "NO\n");
}
