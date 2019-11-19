#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 70;
const int C = N / 4;
vector<int> ga[N], gb[N];
int ci[N];
int d[N][1<<C];
int n,m,a,b;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> a >> b;
    vector<pair<int,int>> eb;
    for (int i = 0; i < m; ++i) {
        int u,v,c;
        cin >> u >> v >> c;
        --u, --v;
        if (c == a) {
            ga[u].push_back(v);
            ga[v].push_back(u);
        } else {
            eb.push_back({u,v});
        }
    }
    fill_n(ci,n,-1);
    int tp = 0, ntp = -2;
    for (int i = 0; i < n; ++i) {
        if (ci[i] != -1)
            continue;
        ci[i] = tp;
        vector<int> q = {i};
        for (int l = 0; l < q.size();) {
            int u = q[l++];
            for (int v : ga[u]) {
                if (ci[v] == -1) {
                    ci[v] = tp;
                    q.push_back(v);
                }
            }
        }
        if (q.size() >= 4) {
            ++tp;
        } else {
            for (int u : q)
                ci[u] = ntp;
            --ntp;
        }
    }
    for (auto p : eb) {
        int u,v;
        tie(u,v) = p;
        if (ci[u] != ci[v]) {
            gb[u].push_back(v);
            gb[v].push_back(u);
        }
    }
    memset(d,0x3f,sizeof d);
    typedef tuple<int,int,int> t3;
    priority_queue<t3,vector<t3>,greater<t3>> pq;
    auto upd = [&](int u,int mask,int s) {
        if (d[u][mask] > s) {
            d[u][mask] = s;
            pq.push({s, u, mask});
        }
    };
    upd(0,(ci[0]>=0?1<<ci[0]:0),0);
    while (pq.size()) {
        int s,u,mask;
        tie(s,u,mask) = pq.top();
        pq.pop();
        if (d[u][mask] != s)
            continue;
        for (int v : ga[u]) 
            upd(v,mask, s + a);
        for (int v : gb[u]) {
            if (ci[v] < 0)
                upd(v,mask, s + b);
            else if ((mask >> ci[v] & 1) == 0)
                upd(v,mask|(1<<ci[v]), s + b);
        }
    }
    for (int i = 0; i < n; ++i)
        cout << *min_element(d[i],d[i]+(1<<tp)) << " \n"[i+1==n];
}
