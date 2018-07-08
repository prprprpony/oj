#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 6e5 + 87;
vector<int> v;
namespace seg {
    pii t[N*4];
    int n;
    void bld(int o=1,int l=0,int r=n-1)
    {
        t[o].F = 0;
        if (l == r) {
        }
        int m = (l + r) >> 1;
    }
    void init()
    {
        n = v.size();
    //    bld();
    }
    int val(int o=1,int l=0,int r=n-1)
    {
        return t[o].F ? v[r] - v[l] : t[o].S;
    }
    void pull(int o,int l,int m,int r)
    {
        t[o].S = val(o<<1,l,m) + val(o<<1|1,m,r);
    }
    void add(int i,int j,int x,int o=1,int l=0,int r=n-1)
    {
        if (j <= l || r <= i)
            return;
        if (i <= l && r <= j) {
            t[o].F += x;
            return;
        }
        int m = (l + r) >> 1;
        add(i,j,x,o<<1,l,m);
        add(i,j,x,o<<1|1,m,r);
        pull(o,l,m,r);
    }
}
pii a[N];
vector<int> ev[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        ++r;
        a[i] = {l,r};
        v.push_back(l);
        v.push_back(r);
    }
    sort(begin(v),end(v));
    v.erase(unique(begin(v),end(v)),end(v));
    seg::init();
    for (int i = 0; i < m; ++i) {
        int kl = lower_bound(begin(v),end(v),a[i].F) - begin(v);
        ev[kl].push_back(i<<1);
        int kr = lower_bound(begin(v),end(v),a[i].S) - begin(v);
        a[i] = {kl,kr};
        ev[kr].push_back(i<<1|1);
        seg::add(kl,kr,1);
    }
    ll ans = 0;
    for (int i = 0; i + 1 < v.size(); ++i) {
        for (int x : ev[i]) {
            int j = x >> 1;
            seg::add(a[j].F,a[j].S, (x & 1) ? 1 : -1);
        }
        ans += (n - seg::val()) * 1LL * (v[i+1] - v[i]);
    }
    cout << ans << '\n';
}

