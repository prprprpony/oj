#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87, M = 1e9 + 7;
vector<int> g[N];
int f[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    while (m--) {
        int a,b;
        cin >> a >> b;
        --a,--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = f[i-1]*2%M;
    long long ans = 0;
    for (int i = 0; i < n; ++i)
        ans += f[n-1-g[i].size()];
    cout << ans % M << endl;
}
