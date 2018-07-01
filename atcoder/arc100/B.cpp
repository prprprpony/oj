#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 87;
int n;
ll a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    ll ans = a[n];
    for (int i = 2; i <= n - 2; ++i) {
        int j = upper_bound(a+1,a+i,a[i]/2) - a;
        int k = upper_bound(a+i+1,a+n+1,(a[i]+a[n])/2) - a;
        for (int i0 = j - 2; i0 <= j + 2; ++i0)
            for (int i2 = k - 2; i2 <= k + 2; ++i2) {
                if (i <= i0 || i2 <= i || i0 < 1 || i2 >= n)
                    continue;
                ll t[4] = {a[i0],a[i]-a[i0],a[i2]-a[i],a[n]-a[i2]};
                sort(t,t+4);
                ans = min(ans, t[3]-t[0]);
            }
    }
    cout << ans << endl;
}
