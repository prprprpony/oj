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
int ca, n, m;
vector<string> ans, g;
vector<pii> p[4] = {
    {{0,0}, {0,1}, {0,2}, {1,1}, {2,1}},
    {{0,2}, {1,0}, {1,1}, {1,2}, {2,2}},
    {{0,1}, {1,1}, {2,0}, {2,1}, {2,2}},
    {{0,0}, {1,0}, {1,1}, {1,2}, {2,0}},
};
void dfs(int dep = 0, int i = 0, int j = 0) 
{
    if (dep > ca) {
        ca = dep;
        ans = g;
    }
    if (j + 2 >= m)
        ++i, j = 0;
    if (i + 2 >= n)
        return;
    int rm = (n - (i + 1)) * m + (m - j);
    if (dep + rm / 6 <= ca)
        return;
    if (g[i + 1][j + 1] == '.') {
        for (int k = 0; k < 4; ++k) {
            bool ok = 1;
            for (const auto & o : p[k])
                ok = ok && g[i + o.F][j + o.S] == '.';
            if (ok) {
                for (const auto & o : p[k]) g[i + o.F][j + o.S] = 'A' + dep;
                dfs(dep + 1, i, j + 1);
                for (const auto & o : p[k]) g[i + o.F][j + o.S] = '.';
            }
        }
    }
    dfs(dep, i, j + 1);
}
void solve(int _n, int _m)
{
    n = _n, m = _m;
    g.assign(n, string(m, '.'));
    ca = 0;
    ans = g;
    dfs();
}
void test()
{
    for (int n = 1; n <= 9; ++n)
        for (int m = 1; m <= n; ++m) {
            solve(n, m);
            BG(n, m, clock() * 1. / CLOCKS_PER_SEC);
        }
    exit(0);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //test();
    cin >> n >> m;
    solve(n, m);
    cout << ca << endl;
    for (auto s : ans)
        cout << s << endl;
}
