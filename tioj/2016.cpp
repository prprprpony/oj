#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second
#define ALL(a) begin(a), end(a)
#define SZ(a) ((int)(a).size())
const int N = 1e5 + 87;
struct fen
{
    vector<ll> v;
    vector<int> f;
    void val(ll x)
    {
        v.push_back(x);
    }
    void bld()
    {
        sort(ALL(v));
        v.erase(unique(ALL(v)),end(v));
        f.clear();
        f.resize(SZ(v)+1,0);
    }
    int gi(ll x)
    {
        return upper_bound(ALL(v), x) - begin(v);
    }
    void add(ll x,int t)
    {
         int i = gi(x);
         for (; i <= SZ(v); i += i & -i)
             f[i] += t;
    }
    int qry(ll x)
    {
        int i = gi(x), ans = 0;
        for (; i; i ^= i & -i)
            ans += f[i];
        return ans;
    }
    int qry(ll x, ll y)
    {
        return qry(y) - qry(x-1);
    }
};
int a[N];
pll p[N];
ll calc(int n)
{
    fen f;
    sort(p,p+n);
    for (int i = 0; i < n; ++i)
        f.val(p[i].S);
    f.bld();
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += f.qry(p[i].S - 1);
        f.add(p[i].S, 1);
    }
    return ans;
}
int main()
{
    int n;
    ll l,u;
    scanf("%d%lld%lld",&n,&l,&u);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    for (int i = 0; i < n; ++i)
        p[i] = {a[i] + i * l, -(a[i] + i * u)};
    ll ans = calc(n);
    for (int i = 0; i < n; ++i)
        p[i] = {a[i] - i * l, -(a[i] - i * u)};
    ans += calc(n);
    if (l <= 0 && 0 < u) {
        map<int,int> m;
        for (int i = 0; i < n; ++i)
            ans -= m[a[i]]++;
    }
    printf("%lld\n", ans);
}
