#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(k), pr(n + 1), nx(n + 1), hb(n + 1);
        auto link = [&] (int x, int y) {
            nx[x] = y;
            pr[y] = x;
        };
        for (int & x : a)
            cin >> x;
        link(0, a[0]);
        link(a.back(), 0);
        for (int i = 1; i < n; ++i)
            link(a[i - 1], a[i]);
        for (int & x : b) {
            cin >> x;
            hb[x] = 1;
        }
        int ans = 1;
        for (int i = 0; i < k; ++i) {
            int c = 0, x = b[i];
            if (pr[x] && !hb[pr[x]])
                ++c;
            if (nx[x] && !hb[nx[x]])
                ++c;
            ans = ans * c % 998244353;
            link(pr[x], nx[x]);
        }
        cout << ans << '\n';
    }
}
