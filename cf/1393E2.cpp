#pragma GCC optimize("Ofast")

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
const int N = 1e6 + 87, MOD = 1e9 + 7;
//const int W = 3; const array<int,W> HMOD = {1010101333, MOD + 2, MOD}, HP = {52127, 12721, 1314127};
//const int W = 2; const array<int,W> HMOD = {1010101333, MOD + 2}, HP = {52127, 12721};
const int W = 1; const array<int,W> HMOD = {1010101333}, HP = {52127};
array<int,W> pw[N];
string s[N];
vector<int> dp[N], nxt[N];
vector< array<int,W> > h[N];
vector<pii> vp[N];

array<int, W> operator * (array<int, W> a, array<int, W> b)
{
    array<int, W> c;
    for (int i = 0; i < W; ++i)
        c[i] = a[i] * 1ll * b[i] % HMOD[i];
    return c;
}
array<int, W> operator + (array<int, W> a, array<int, W> b)
{
    array<int, W> c;
    for (int i = 0; i < W; ++i)
        c[i] = (a[i] + b[i]) % HMOD[i];
    return c;
}
array<int, W> operator - (array<int, W> a, array<int, W> b)
{
    array<int, W> c;
    for (int i = 0; i < W; ++i)
        c[i] = (a[i] + HMOD[i] - b[i]) % HMOD[i];
    return c;
}
array<int, W> operator + (array<int, W> a, int x)
{
    array<int, W> c;
    for (int i = 0; i < W; ++i)
        c[i] = (a[i] + x) % HMOD[i];
    return c;
}

array<int,W> hh(int i, int j, int len)
{
    return h[i][j] - h[i][j + len] * pw[len];
}
array<int,W> f(pii a, int len)
{
    if (len <= a.S)
        return hh(a.F, 0, len);
    else 
        return hh(a.F, 0, a.S) + hh(a.F, a.S + 1, len - a.S) * pw[a.S];
}
char g(pii a, int i)
{
    return i < a.S ? s[a.F][i] : s[a.F][i + 1];
}
bool cmp(pii a, pii b)
{
    if (a.F == b.F) {
        int i = nxt[a.F][a.S], j = nxt[a.F][b.S];
        if (i == j)
            return false;
        if (i < j) 
            return s[a.F][i] < s[a.F][i - 1];
        else
            return s[a.F][j - 1] < s[a.F][j];
    } else {
        int ls = SZ(s[a.F]) - (a.S < SZ(s[a.F]));
        int rs = SZ(s[b.F]) - (b.S < SZ(s[b.F]));
        int len = min(ls, rs);
        if (f(a, len) == f(b, len))
            return ls < rs;
        int lo = 1, hi = len - 1;
        while (lo <= hi) {
            int mi = (lo + hi) / 2;
            if (f(a, mi) == f(b, mi))
                lo = mi + 1;
            else
                hi = mi - 1;
        }
        return g(a, hi) < g(b, hi);
    }
}
string gs(pii a)
{
    return s[a.F].substr(0, a.S) + s[a.F].substr(a.S + 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    assert(HMOD.size() == HP.size());
    pw[0].fill(1);
    for (int i = 1; i < N; ++i)
        pw[i] = pw[i - 1] * HP;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        int m = s[i].size();
        dp[i] = nxt[i] = vector<int>(m + 1);
        nxt[i][m - 1] = m;
        for (int j = m - 2; j >= 0; --j)
            if (s[i][j + 1] == s[i][j])
                nxt[i][j] = nxt[i][j + 1];
            else
                nxt[i][j] = j + 1;
        h[i].assign(m + 1, {});
        for (int j = m - 1; j >= 0; --j)
            h[i][j] = h[i][j + 1] * HP + s[i][j];
        vp[i].resize(m + 1);
        int l = 0, r = m;
        for (int j = 0; j <= m; ++j)
            if (s[i][nxt[i][j]] < s[i][j])
                vp[i][l++] = pii(i, j);
            else
                vp[i][r--] = pii(i, j);

        if (i == 0) {
            fill(ALL(dp[i]), 1);
        } else {
            int su = 0;
            for (int j = 0, k = 0; j <= m; ++j) {
                while (k < vp[i - 1].size() && !cmp(vp[i][j], vp[i - 1][k])) {
                    su = (su + dp[i - 1][k++]) % MOD;
                }
                dp[i][j] = su;
            }
        }
    }
    cout << accumulate(ALL(dp[n - 1]), 0ll) % MOD << endl;
}
