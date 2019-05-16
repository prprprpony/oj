#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+87;
ll n,m,a[N],b[N],c[N];
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a,a+n);
    for (int i = 0; i < m; ++i) cin >> b[i];
    sort(b,b+m);
    if (b[0] < a[n-1]) {
        cout << "-1\n";
        return 0;
    }
    ll ans = accumulate(a,a+n,0LL) * m;
    for (int j = 0, i = 0; j < m; ++j) {
        while (i + 1 < n && a[i+1] <= b[j])
            ++i;
        if (a[i] > b[j]) {
            cout << "-1\n";
            return 0;
        }
        ans += b[j] - a[i];
        ++c[i];
    }
    for (int i = 0; i < n; ++i)
        if (c[i] == m && b[0] != a[i]) {
            if (i == 0) {
                cout << "-1\n";
                return 0;
            }
            ans += a[i] - a[i-1];
        }
    cout << ans << endl;
}
