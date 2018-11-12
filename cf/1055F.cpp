#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 1e6 + 87, B = 62;
ll a[N];
ll n,k;
pii p[N];
int mi[N];
void pre(int i)
{
    fill_n(mi,n,-1);
    for (int o = 0; o < n; ++o) {
        int l,r;
        tie(l,r) = p[o];
        if (l >= r)
            continue;
        int & x = mi[l];
        if (x != -1)
            continue;
        for (x = l; x < r && (a[x]>>i&1^1); ++x);
    }
}
int mid(pii w,int i)
{
    if (w.F >= w.S)
        return w.F;
    return mi[w.F];
}
int cnt(pii w,int i,int o)
{
    if (w.F >= w.S)
        return 0;
    int l = mid(w,i);
    return o ? w.S - l : l - w.F;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1,p; i < n; ++i) {
        cin >> p >> a[i];
        a[i] ^= a[p-1];
    }
    sort(a,a+n);
    ll ans = 0;
    fill_n(p,n,pii(0,n));
    for (int i = B-1; i >= 0; --i) {
        pre(i);
        ll ct = 0;
        for (int o = 0; o < n; ++o)
            ct += cnt(p[o], i, a[o]>>i&1);
        if (ct < k) {
            k -= ct;
            ans |= 1LL<<i;
            for (int o = 0; o < n; ++o)
                ((a[o]>>i&1) ? p[o].S : p[o].F) = mid(p[o],i);
        } else {
            for (int o = 0; o < n; ++o)
                ((a[o]>>i&1^1) ? p[o].S : p[o].F) = mid(p[o],i);
        }
    }
    cout << ans << '\n';
}
