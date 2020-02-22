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
const int N = 4e5 + 87;
const int D = __lg(N) + 1;
vi g[N];
int pa[N][D], de[N];
void dfs(int u, int p)
{
    de[u] = de[p] + 1;
    pa[u][0] = p;
    for (int i = 1; i < D; ++i)
        pa[u][i] = pa[pa[u][i - 1]][i - 1];
    for (int v : g[u])
        if (v != p)
            dfs(v, u);
}
int la(int v, int d)
{
    for (int k = 0; d; k++, d >>= 1)
        if (d & 1)
            v = pa[v][k];
    return v;
}
int lca(int u, int v)
{
    if (de[u] > de[v])
        swap(u, v);
    v = la(v, de[v] - de[u]);
    if (v == u)
        return u;
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
int walk(int u, int v, int d) // move d steps from u to v
{
    int w = lca(u, v);
    if (d <= de[u] - de[w])
        return la(u, d);
    d -= de[u] - de[w];
    d = de[v] - de[w] - d;
    return la(v, d);
}

int n, k, r, d[N], p[N];
int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}
void meld(int a, int b)
{
    p[find(a)] = find(b);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> r;
    int oldn = n;
    for (int i = 0; i < oldn - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].PB(n);
        g[n].PB(x);
        g[y].PB(n);
        g[n].PB(y);
        ++n;
    }
    fill_n(d, n, N);
    queue<int> q;
    for (int i = 0, s; i < r; ++i) {
        cin >> s;
        --s;
        q.push(s);
        d[s] = 0;
    }
    iota(p, p + n, 0);
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (d[u] == k)
            break;
        for (int v : g[u]) {
            meld(u, v);
            if (d[v] == N) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    fill_n(pa[n], D, n);
    de[n] = 0;
    dfs(0, n);
    int qaq;
    cin >> qaq;
    while (qaq--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (dist(a, b) <= 2 * k || find(walk(a, b, k)) == find(walk(b, a, k)))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
