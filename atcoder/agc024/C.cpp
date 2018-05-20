#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 87;
int a[N];
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (a[0] != 0) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0;
    int tp = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] < tp) {
            cout << -1 << endl;
            return 0;
        }
        if (a[i] > tp) {
            ans += a[i];
            tp = a[i];
        }
        tp = max(0, tp-1);
    }
    cout << ans << endl;
}
