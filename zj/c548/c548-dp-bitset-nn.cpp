#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
bitset<N*2> dp[2];
int a[N],fi[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= k;
    }
    for (int i = 0, b = 0; i < n && !fi[0]; ++i, b ^= 1) {
        dp[b] = (dp[b^1] << a[i]) | dp[b^1];
        dp[b] |= dp[b] >> k;
        dp[b][a[i]] = 1;
        dp[b^1] ^= dp[b];
        for (int j = dp[b^1]._Find_first(); j < k; j = dp[b^1]._Find_next(j))
            fi[j] = i + 1;
    }
    if (!fi[0]) {
        cout << "0\n";
        return 0;
    }
    vector<int> ans;
    for (int x = 0, i = fi[0]; ; ) {
        ans.push_back(i);
        x = (x + k - a[i-1]) % k;
        i = fi[x];
        if (i == 0 || i >= ans.back())
            break;
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " \n"[i+1==ans.size()];
}
