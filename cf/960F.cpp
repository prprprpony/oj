#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 87;
map<int,int> dp[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a,b,w,s=1;
        cin >> a >> b >> w;
        auto it = dp[a].lower_bound(w);
        if (it != dp[a].begin()) {
            it = prev(it);
            s = it->second + 1;
        }
        it = dp[b].lower_bound(w);
        if (it != dp[b].begin() && prev(it)->second >= s)
            continue;
        while (it != end(dp[b]) && it->second <= s)
            dp[b].erase(it++);
        dp[b].insert(it,{w,s});
        ans = max(ans, s);
    }
    cout << ans << endl;
}
