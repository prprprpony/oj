#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 2e5+87;
vector<pii> g[N];
long long dp[N][4],ans;
void dfs(int u,int p = 0)
{
    for (auto e : g[u]) {
        int v,c;
        tie(v,c) = e;
        if (v == p)
            continue;
        dfs(v,u);
        array<long long,4> w;
        if (c == 0) {
            w = {dp[v][0]+1,0,dp[v][2]+dp[v][3],0};
        } else {
            w = {0,dp[v][0]+dp[v][1],0,dp[v][3]+1};
        }
        ans += dp[u][0] * (2 * w[0] + w[2] + w[3]);
        ans += dp[u][2] * w[0];
        ans += dp[u][3] * (w[0] + w[1] + 2 * w[3]);
        ans += dp[u][1] * w[3];
        for (int i = 0; i < 4; ++i)
            dp[u][i] += w[i];
    }
    ans+=(dp[u][0]+dp[u][3])*2 +dp[u][1]+dp[u][2];
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int x,y,c;
        cin >> x >> y >> c;
        g[x].push_back(pii(y,c));
        g[y].push_back(pii(x,c));
    }
    dfs(1);
    cout << ans << endl;
}
