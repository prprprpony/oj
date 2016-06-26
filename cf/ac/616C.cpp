#include <bits/stdc++.h>
using namespace std;
int n, m;
typedef pair<int, int> pii;
char g[1000][1000 + 42];
bool vis[1000][1000];
int w[1000][1000];
int idx[1000][1000];
int __idx = 1;
int dr[] = {0, 1, -1, 0}; // hjkl
int dc[] = {-1, 0, 0, 1};
inline bool inrange(const pii &p)
{
    return p.first >= 0 && p.first < n && p.second >= 0 && p.second < m;
}
void bfs(int r, int c)
{
    queue<pii> q;
    vector<pii> done;
    q.push(pii(r, c));
    vis[r][c] = true;
    while (!q.empty()) {
        pii t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pii nxt(t.first + dr[i], t.second + dc[i]);
            if (inrange(nxt) && g[nxt.first][nxt.second] == '.' && !vis[nxt.first][nxt.second]) {
                vis[nxt.first][nxt.second] = true;
                q.push(nxt);
            }
        }
        done.push_back(t);
    }
    for (int i = 0; i < done.size(); i++) {
        w[done[i].first][done[i].second] = done.size();
        idx[done[i].first][done[i].second] = __idx;
    }
    __idx++;
}
int main()
{
    scanf("%d%d ", &n, &m);
    for (int i = 0; i < n; i++)
        fgets(g[i], sizeof(g[i]), stdin);
    for (int i = 0; i < n; i++) {
        memset(vis[i], 0, m * sizeof(bool));
        memset(w[i], 0, m * sizeof(int));
        memset(idx[i], 0, m * sizeof(int));
    }
    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
            if (g[r][c] == '.' && !vis[r][c])
                bfs(r, c);
    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
            if (g[r][c] == '*') {
                set<int> used;
                int x = 1;
                for (int i = 0; i < 4; i++) {
                    pii nxt(r + dr[i], c + dc[i]);
                    if (inrange(nxt) && !used.count(idx[nxt.first][nxt.second])) {
                        x = (x + w[nxt.first][nxt.second]) % 10;
                        used.insert(idx[nxt.first][nxt.second]);
                    }
                }
                g[r][c] = x + '0';
            }
    for (int r = 0; r < n; r++)
        fputs(g[r], stdout);
    return 0;
}
