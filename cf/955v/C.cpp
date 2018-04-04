#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
#define ALL(a) begin(a),end(a)

const int C = 61;
const ll inf = 1e18;
vector<int> p;
bitset<C> sev;
vector<pii> op;
vector<ll> ta[C];
void precal(int i = 0,int s = 0,int e = 1)
{
    if (e >= C)
        return ;
    if (i == p.size()) {
        if (e > 1)
            op.push_back({e,s?1:-1});
        return;
    }
    precal(i+1,s,e);
    precal(i+1,s^1,e*p[i]);
}
ll qpow(ll a,ll b)
{
    ll r = 1;
    for (;b;b>>=1,a*=a)
        if (b&1)
            r*=a;
    return r;
}
typedef long double ld;
ld qpow(ld a,ll b)
{
    ld r = 1;
    for (;b;b>>=1,a*=a)
        if (b&1)
            r*=a;
    return r;
}
void pre()
{
    for (int i = 2; i < C; ++i) {
        if (!sev[i]) {
            for (int j = i * i; j < C; j += i)
                sev[j] = 1;
            p.push_back(i);
        }
    }
    precal();
    for (const auto & x : op) {
        int e = x.F;
        if (e > 3) {
            for (ll i = 2; qpow(ld(i),e) <= inf; ++i)
                ta[e].push_back(qpow(i,e));
        }
    }
/*
    for (int i = 0; i < C; ++i)
        for (int j = 1; j < ta[i].size(); ++j) {
            cerr << i << ' ' << j << ' ' << ta[i][j] << endl;
            assert(ta[i][j-1] < ta[i][j]);
        }
        */
}
ll f(ll x)
{
    if (!x)
        return 0;
    ll sum = 0;
    for (const auto & t : op) {
        int e,s;
        ll w;
        tie(e,s) = t;
        if (e <= 3) {
            w = powl(x, 1.0 / e);
            while (qpow(w,e) < x)
                ++w;
            while (qpow(w,e) > x)
                --w;
            if (w)
                --w;
        } else {
            w = upper_bound(ALL(ta[e]),x) - begin(ta[e]);
        }
        sum += s * w;
    }
    return sum + 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    pre();
    //cerr << op.size() << endl;
    int q;
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        cout << f(r) - f(l - 1) << '\n';
    }
}
