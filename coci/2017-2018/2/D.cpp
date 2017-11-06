#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define ALL(a) begin(a), end(a)
#define SZ(a) ((int)(a).size())
typedef pair<int,int> pii;
#define F first
#define S second
/*>_<*/
const int inf = 1e9 + 87;
pii p[21];
struct fen
{
    vector<ll> val;
    vector<int> f;
    void init()
    {
        sort(ALL(val));
        val.erase(unique(ALL(val)), end(val));
        f.clear();
        f.resize(SZ(val)+1,0);
    }
    int gi(ll x)
    {
        return upper_bound(ALL(val), x) - begin(val);
    }
    void add(ll x)
    {
        for (int i = gi(x); i < SZ(f); i += i & -i)
            ++f[i];
    }
    int qry(ll x)
    {
        int ret = 0;
        for (int i = min(gi(x), SZ(f) - 1); i; i ^= i & -i)
            ret += f[i];
        return ret;
    }
};
template<class T>
void bf(int n, T & v,int d)
{
    v.PB({d == 1 ? -inf : inf, 0});
    for (int i = 0; i < n; ++i) {
        int m = SZ(v);
        for (int j = 0; j < m; ++j)
            if (p[i].F == v[j].F || ((0 > p[i].F - v[j].F) == (0 > d)))
                v.PB({p[i].F, v[j].S + p[i].S});
    }
    sort(ALL(v));
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    vector<pair<int,ll>> a, b;
    a.reserve(1<<((n+1)/2));
    b.reserve(1<<((n+1)/2));
    for (int i = 0; i < n/2; ++i)
        cin >> p[i].F >> p[i].S;
    bf(n/2,b,1);
    for (int i = n-1; i >= n/2; --i)
        cin >> p[i-n/2].F >> p[i-n/2].S;
    bf(n-n/2,a,-1);
/*
cerr << "SZ(b):" << SZ(b) << endl;
cerr << "SZ(a):" << SZ(a) << endl;
*/
    fen f;
    f.val.reserve(SZ(b));
    for (const auto & x : b)
        f.val.PB(x.S);
    f.init();
    ll ans = 0;
    int t = 0;
    for (int i = 0, j = 0; j < SZ(a); ++j) {
        for (; i < SZ(b) && b[i].F <= a[j].F; ++i) {
//cerr << "b["<< i << "]=" << b[i].F << ',' << b[i].S << endl;
            f.add(b[i].S);
            ++t;
        }
        int ta = t - f.qry(k - a[j].S - 1);
/*
cerr << "a["<< j << "]=" << a[j].F << ',' << a[j].S << endl;
cerr << "ta = " << ta << endl;
*/
        ans += ta;
    }
    cout << ans << '\n';
}
