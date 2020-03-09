#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 87;
vector<int> g[N], s[2], c[3];
int p[N];
void dfs(int u, int p, int d)
{
    s[d % 2].push_back(u);
    for (int v : g[u])
        if (v != p)
            dfs(v, u, d + 1);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 1, 1);
    if (s[1].size() < s[0].size())
        swap(s[0], s[1]);
    for (int i = 1; i <= n; ++i)
        c[i % 3].push_back(i);
    if (s[0].size() <= c[0].size()) {
        while (s[0].size()) {
            int x = s[0].back();
            s[0].pop_back();
            int y = c[0].back();
            c[0].pop_back();
            p[x] = y;
        }
        while (s[1].size()) {
            int x = s[1].back();
            s[1].pop_back();
            int y = -1;
            for (int i = 0; i < 3; ++i)
                if (c[i].size()) {
                    y = c[i].back();
                    c[i].pop_back();
                    break;
                }
            p[x] = y;
        }
    } else {
        while (s[0].size()) {
            int x = s[0].back();
            s[0].pop_back();
            int y = -1;
            for (int i : {2, 0})
                if (c[i].size()) {
                    y = c[i].back();
                    c[i].pop_back();
                    break;
                }
            p[x] = y;
        }
        while (s[1].size()) {
            int x = s[1].back();
            s[1].pop_back();
            int y = -1;
            for (int i : {1, 0})
                if (c[i].size()) {
                    y = c[i].back();
                    c[i].pop_back();
                    break;
                }
            p[x] = y;
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << p[i] << " \n"[i == n];
}
