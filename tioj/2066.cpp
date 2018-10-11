#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87;
typedef long long ll;
const ll M = (1LL<<61)-1;
ll add(ll a,ll b) {return (a += b) < M ? a : a - M;}
int n,k,a[N],b[N];
ll w[N],f[N];
ll qry(int i)
{
    ll r = 0;
    for (; i; i ^= i & -i)
        r = add(r, f[i]);
    return r;
}
void upd(int i,ll v)
{
    for (; i <= n; i += i & -i)
        f[i] = add(f[i], v);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        copy_n(a,n,b);
        sort(b,b+n);
        for (int i = 0; i < n; ++i)
            a[i] = lower_bound(b,b+n,a[i]) - b + 1;
        fill_n(w,n+1,1);
        ll ans = n;
        for (int len = 2; len <= k; ++len) {
            fill_n(f,n+1,0);
            for (int i = 0; i < n; ++i) {
                upd(a[i],w[i]);
                w[i] = qry(a[i]-1);
                ans = add(ans, w[i]);
            }
        } 
        cout << ans << '\n';
    }
}
