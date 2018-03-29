#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 87, inf = 0x3f3f3f3f;
typedef long long ll;
#define F first
#define S second
pair<ll,ll> a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,T,s = 0, w = 0;
    cin >> n >> T;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].S;
        w += a[i].S;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i].F;
        a[i].F -= T;
        s += a[i].F * a[i].S;
    }
    if (s < 0) {
        s = -s;
        for (int i = 0; i < n; ++i)
            a[i].F *= -1;
    }
    sort(a,a+n);
    for (int i = n - 1; i >= 0 && a[i].F > 0 && s > 0; --i) {
        if (a[i].F * a[i].S <= s) {
            s -= a[i].F * a[i].S;
            w -= a[i].S;
        } else {
            double t = s * 1.0 / a[i].F;
            cout << setprecision(16) << w - t << '\n';
            return 0;
        }
    }
    cout << w << '\n';
}
