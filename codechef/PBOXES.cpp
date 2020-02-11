#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define F first
#define S second
#define ALL(a) begin(a), end(a)
template<class T>
bool cmax(T&a,T b){return a < b ? a = b, 1 : 0;}
typedef double val;
const int N = 2e5 + 87;
const ll inf = 1e18;
int n;
vector<pii> p;
struct node
{
    pii best, rbest;
    int mx; // p[mx] is max
    int mi;
    int su;
    int mn_su;
    int po_mx; // su[po_mx: ] != mn_su, p[po_mx] is max
    int pr_mi;
    node() {}
    node(int i, int s) : best{-1, -1}, rbest{-1, -1}, mx(i), mi(i), su(s), mn_su(s), po_mx(-1), pr_mi(-1) {}
} t[N * 2];
int orz(pii a)
{
    if (a.F == -1 || a.S == -1)
        return INT_MIN;
    return p[a.F].S - p[a.S].S;
}
pii tmw(pii a, pii b)
{
    return orz(a) > orz(b) ? a : b;
}
int maxi(int a, int b)
{
    if (a == -1)
        return b;
    if (b == -1)
        return a;
    return p[a].S > p[b].S ? a : b;
}
int mini(int a, int b)
{
    if (a == -1)
        return b;
    if (b == -1)
        return a;
    return p[a].S < p[b].S ? a : b;
}
void pull(int o, int z)
{
    t[o].mx = maxi(t[o + 1].mx, t[z].mx);
    t[o].mi = mini(t[o + 1].mi, t[z].mi);
    t[o].su = t[o + 1].su + t[z].su;
    t[o].mn_su = min(t[o + 1].mn_su, t[o + 1].su + t[z].mn_su);

    if (t[o].mn_su == t[o + 1].su + t[z].mn_su)
        t[o].po_mx = t[z].po_mx;
    else
        t[o].po_mx = maxi(t[z].mx, t[o + 1].po_mx);

    if (t[o].mn_su == t[o + 1].mn_su)
        t[o].pr_mi = t[o + 1].pr_mi;
    else
        t[o].pr_mi = mini(t[o + 1].mi, t[z].pr_mi);

    if (t[o].mn_su == t[o + 1].mn_su && t[o].mn_su == t[o + 1].su + t[z].mn_su)
        t[o].rbest = tmw(tmw(t[o + 1].rbest, t[z].rbest), pii(t[o + 1].po_mx, t[z].pr_mi));
    else if (t[o].mn_su == t[o + 1].mn_su)
        t[o].rbest = tmw(tmw(t[o + 1].rbest, t[z].best), pii(t[o + 1].po_mx, t[z].mi));
    else 
        t[o].rbest = tmw(tmw(t[o + 1].best, t[z].rbest), pii(t[o + 1].mx, t[z].pr_mi));
    t[o].rbest = tmw(t[o].rbest, pii(t[z].mx, t[o + 1].mi));
    t[o].best = tmw(tmw(t[o + 1].best, t[z].best), tmw(pii(t[z].mx, t[o + 1].mi), pii(t[o + 1].mx, t[z].mi)));
}
void bld(int o = 0, int l = 0, int r = n)
{
    if (r - l == 1) {
        t[o] = node(l, 0);
        return;
    }
    int m = l + (r - l) / 2;
    int z = o + (r - l) / 2 * 2;
    bld(o + 1, l, m);
    bld(z, m, r);
    pull(o, z);
}
void upd(int i, int v, int o = 0, int l = 0, int r = n)
{
    if (r - l == 1) {
        t[o] = node(-1, v);
        return;
    }
    int m = l + (r - l) / 2;
    int z = o + (r - l) / 2 * 2;
    if (i < m)
        upd(i, v, o + 1, l, m);
    else
        upd(i, v, z, m, r);
    pull(o, z);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    p.resize(n);
    for (auto & a : p)
        cin >> a.F >> a.S;
    sort(ALL(p));
    bld();
    ll ans = 0, sum = 0;
    for (int i = 1; i <= n / 2; ++i) {
        pii ot = t[0].rbest;
        sum += orz(ot);
        ans = max(ans, sum);
        upd(ot.S, 1);
        upd(ot.F, -1);
        //cerr <<"ot "<< ot.F << ' ' << ot.S << endl;
        cout << ans << '\n';
    }
}
