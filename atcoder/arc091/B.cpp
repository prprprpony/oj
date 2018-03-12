#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,ans;
int main()
{
    cin >> n >> k;
    for (ll a=max(k,1LL),rt=1;a<=n;++a) {
        while ((rt+1) * (rt+1) <= a)
            ++rt;
        for (ll b = 1; b <= rt; ++b)
            ans += a % b >= k;
        for (ll x = 1; x <= rt; ++x) {
            ll l = a / (x+1) + 1, r = (a - k) / x;
            l = max(l, rt+1);
            if (l <= r)
                ans += r - l + 1;
        }
        ans += n-a;
    }
    cout << ans << endl;
}
