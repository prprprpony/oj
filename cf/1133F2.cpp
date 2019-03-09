#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 2e5+87;
vector<int> g[N];
int p[N];
int find(int x) {return p[x]==x?x:p[x]=find(p[x]);}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,d;
    cin >> n >> m >> d;
    while (m--) {
        int u,v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int t = g[1].size();
    queue<int> q;
    for (int u : g[1]) {
        q.push(u);
        p[u] = u;
    }
    vector<pii> ans;   
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (v == 1)
                continue;
            if (!p[v]) {
                p[v] = u;
                ans.emplace_back(u,v);
                q.push(v);
            } else {
                int x = find(v), y = find(u);
                if (x != y && t > d) {
                    p[x] = y;
                    --t;
                    ans.emplace_back(u,v);
                }
            }
        }
    }
    if (t != d) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 2; i <= n; ++i)
        if (find(i) == i)
            ans.emplace_back(1,i);
    cout << "YES\n";
    for (const auto & p : ans)
        cout << p.F << ' ' << p.S << '\n';
}
