#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 87;
typedef pair<int,int> pii;
#define F first
#define S second
int n,k;
vector<int> g[N];
pii dfs(int p,int u)
{
    pii ret(-1e9,1);
    int c = 0;
    for (int v : g[u])
        if (v != p) {
            ++c;
            auto x = dfs(u,v);
            ++x.F;
            if (x.F + ret.F <= k) {
                ret.S += x.S - 1;
                ret.F = max(ret.F,x.F);
            } else {
                ret.S += x.S;
                ret.F = min(ret.F,x.F);
            }
        }
    if (!c)
        return {0,1};
    return ret;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n-1; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int r = 1;
    while (g[r].size() == 1)
        ++r;
    cout << dfs(r,r).S << '\n';
}
