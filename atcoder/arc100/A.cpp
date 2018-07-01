#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 87;
ll a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] -= i + 1;
    }
    sort(a,a+n);
    ll b = a[n/2], ans = 0;
    for (int i = 0; i < n; ++i)
        ans += abs(b - a[i]);
    cout << ans << endl;
}
