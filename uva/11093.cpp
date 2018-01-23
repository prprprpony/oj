#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 87;
ll a[N*2];
int st[N*2];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        ll x;
        cin >> x;
        a[i] -= x;
    }
    copy_n(a+1,n-1,a+n+1);
    int m = n + n - 1, ans = 0, tp = 0;
    for (int i = 1; i <= m; ++i)
        a[i] += a[i-1];
    a[m+1] = -9e18;
    st[tp++] = m+1;
    for (int i = m; i >= 0; --i) {
        while (a[i] <= a[st[tp-1]])
            --tp;
        if (st[tp-1] - i >= n + 1)
            ans = i + 1;
        st[tp++] = i;
    }
    if (ans)
        cout << "Possible from station " << ans << '\n';
    else
        cout << "Not possible\n";
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cout << "Case " << i << ": ";
        solve();
    }
}
