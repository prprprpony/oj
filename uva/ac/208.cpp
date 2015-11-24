#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxv = 20;
vector<bool> vis(maxv + 1, false);
vector<int> edges[maxv + 1];
int t;
int r[maxv + 1];
bool to_t[maxv + 1];

void mark_to_t(int s)
{
    to_t[s] = true;
    for (int i = 0; i < edges[s].size(); i++)
        if (!to_t[edges[s][i]])
            mark_to_t(edges[s][i]);
}

int dfs(int d, int s)
{
    r[d] = s;

    if (s == t) {
        for (int i = 0; i <= d; i++)
            printf("%d%c", r[i], i != d ? ' ' : '\n');
        return 1;
    }

    int n = 0;
    for (int i = 0; i < edges[s].size(); i++) {
        if (!vis[edges[s][i]] && to_t[edges[s][i]]) {
            vis[edges[s][i]] = true;
            n += dfs(d + 1, edges[s][i]);
            vis[edges[s][i]] = false;
        }
    }
    return n;
}

int main()
{
    int cases = 0;
    while (scanf("%d", &t) == 1) {
        int u, v, n;
        while (scanf("%d%d", &u, &v) == 2 && u > 0) {
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        memset(to_t, 0, sizeof(to_t));
        mark_to_t(t);

        printf("CASE %d:\n", ++cases);
        if (to_t[1]) {
            for (int i = 1; i <= maxv; i++)
                sort(edges[i].begin(), edges[i].end());
            vis[1] = true;
            n = dfs(0, 1);
        } else {
            n =0;
        }

        printf("There are %d routes from the firestation to streetcorner %d.\n", n, t);

        for (int i = 1; i <= maxv; i++) {
            vis[i] = false;
            edges[i].clear();
        }
    }
    return 0;
}
