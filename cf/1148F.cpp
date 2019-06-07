#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+87, K = 62;
typedef pair<ll,ll> pll;
#define F first
#define S second
vector<pll> a[K];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll tot = 0;
    for (int i = 0; i < n; ++i) {
        ll v,m;
        cin >> v >> m;
        a[__lg(m)].emplace_back(m,v);
        tot += v;
    }
    ll s = 0;
    for (int i = 0; i < K; ++i) {
        ll cur = 0;
        for (auto & p : a[i]) {
            if (__builtin_popcountll(p.F & s) & 1)
                p.S *= -1;
            cur += p.S;
        }
        if ((cur > 0) == (tot > 0))
            s |= 1ll << i;
    }
    cout << s << endl;
}
