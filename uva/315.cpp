#include <bits/stdc++.h>
#define MAXN 110
using namespace std;
vector<int> E[MAXN];
bool vis[MAXN];
int low[MAXN];
int dep[MAXN];
bool is_cv[MAXN];
vector<int> cv;
void dfs(int x, int d)
{
    vis[x] = true;
    dep[x] = d;
    low[x] = d;
    is_cv[x] = false;
    int cnt = 0;
    for (int i : E[x]) {
        if (vis[i]) {
            if (dep[i] < low[x])
                low[x] = dep[i];
        } else {
            dfs(i, d + 1);
            cnt++;
            if (low[i] < low[x])
                low[x] = low[i];
            if (low[i] >= dep[x])
                is_cv[x] = true;
        }
    }
    if (d == 0)
        is_cv[x] = cnt > 1;
}
int main()
{
    int n;
    int u, v;
    string buf;
    while (scanf("%d ", &n) == 1 && n > 0) {
        for (int i = 1; i <= n; i++)
            E[i].clear();
        while (getline(cin, buf) && buf[0] != '0') {
            stringstream ss(buf);
            ss >> u;
            while (ss >> v) {
                E[u].push_back(v);
                E[v].push_back(u);
            }
        }
        memset(vis + 1, 0, n * sizeof(bool));
        cv.clear();
        dfs(1,0);
        for (int i = 1; i <= n; i++)
            if (is_cv[i])
                cv.push_back(i);
        cout << cv.size() << '\n';
    }
}
