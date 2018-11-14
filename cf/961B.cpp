#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> v(n+1);
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        if (t) {
            ans += v[i];
            v[i] = 0;
        }
    }
    partial_sum(begin(v),end(v),begin(v));
    int mx = 0;
    for (int i = k; i <= n; ++i)
        mx = max(mx, v[i] - v[i-k]);
    cout << ans + mx << endl;
}
