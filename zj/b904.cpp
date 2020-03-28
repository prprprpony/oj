#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int kN = 300005, kInf = 1e9;
vector<pii> g[kN];
pii d[kN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].emplace_back(y, w);
        g[y].emplace_back(x, w);
    }
    fill_n(d, n + 1, pii(kInf, -1));
    typedef pair<pii, int> nd;
    priority_queue<nd, vector<nd>, greater<nd>> pq;
    for (int i = 0, x; i < k; ++i) {
        cin >> x;
        d[x] = pii(0, x);
        pq.emplace(d[x], x);
    }
    int ans = kInf;
    while (pq.size()) {
        pii w;
        int u;
        tie(w, u) = pq.top();
        pq.pop();
        if (w != d[u])
            continue;
        for (pii p : g[u]) {
            int tw = w.first + p.second;
            int v = p.first;
            if (w.second == -1 || d[v].second == -1 || w.second != d[v].second)
                ans = min(ans, tw + d[v].first);
            if (tw < d[v].first) {
                d[v] = pii(tw, w.second);
                pq.emplace(d[v], v);
            } else if (tw == d[v].first && d[v].second != -1 && w.second != d[v].second) {
                d[v].second = -1;
                pq.emplace(d[v], v);
            }
        }
    }
    if (ans == kInf)
        cout << "zombie\n";
    else
        cout << ans << endl;
}
