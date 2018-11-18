#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
typedef long long ll;
const int N = 2e5 + 87;
vector<pii> g[N];
bool vis[N];
void add(int a,int b,int w)
{
    g[a].emplace_back(b,w);
    g[a].emplace_back(N-b,w);
    g[N-a].emplace_back(b,w);
    g[N-a].emplace_back(N-b,w);
}
ll dfs(int u)
{
    ll r = 0;
    vis[u] = 1;
    for (const auto & e : g[u]) {
        r += e.S;
        if (vis[e.F])
            continue;
        r += dfs(e.F);
    }
    return r;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        for (int j = 2; i * j <= n; ++j) {
            int a = i, b = i * j, w = j;
            add(a,b,w);
            add(b,a,w);
        }
    }
    ll ans = 0;
    for (int i = 2; i < N; ++i) {
        if (vis[i])
            continue;
        ans = max(ans,dfs(i));
    }
    cout << ans/2 << endl;
}
