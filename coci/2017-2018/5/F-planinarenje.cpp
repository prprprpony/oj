#include<bits/stdc++.h>
using namespace std;
const int N = 5056;
vector<int> gy[N];
bitset<N> vis;
int n,m,mx[N];
bool dfs(int y)
{
    for (int x : gy[y]) {
        if (vis[x])
            continue;
        vis[x] = 1;
        if (!mx[x] || dfs(mx[x])) {
            mx[x] = y;
            return 1;
        }
    }
    return 0;
}
int mat()
{
    int ans = 0;
    for (int i = 1; i <= n; ++i)  {
        vis.reset();
        ans += dfs(i);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u,v;
        cin >> u >> v;
        gy[v].push_back(u);
    }
    int a = mat();
    for (int i = 1; i <= n; ++i) {
        int b = a;
        if (mx[i]) {
            int y = mx[i];
            mx[i] = 0;
            --b;
            vis.reset();
            vis[i] = 1;
            b += dfs(y);
            if (b < a)
                mx[i] = y;
        }
        cout << (b == a ? "Mirko\n" : "Slavko\n");
    }
}
