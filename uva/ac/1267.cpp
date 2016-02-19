#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXN 1000 + 42
#define PB(v) push_back(v)
using namespace std;
typedef vector<int> vi;

int n, s, k;
vi E[MAXN];
int p[MAXN];
vi L[MAXN];
bool covered[MAXN];

void dfs(int d, int x, int pa) {
    p[x] = pa;
    for (int c : E[x])
        if (p[c] == -1)
            dfs(d + 1, c, x);
    if (E[x].size() == 1 && d > k)
        L[d].PB(x);
}

void cover(int d, int x, int pa) {
    covered[x] = true;
    if (d == k)
        return;
    for (int c : E[x])
        if (c != pa)
            cover(d + 1, c, x);
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> s >> k;
        for (int i = 1; i <= n; i++) {
            E[i].clear();
            L[i].clear();
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            E[u].PB(v);
            E[v].PB(u);
        }
        memset(p + 1, -1, n * sizeof(int));
        dfs(0, s, 0);
        int ans = 0;
        memset(covered + 1, 0, n * sizeof(bool));
        for (int d = n-1; d > k; d--) {
            for (int u : L[d]) {
                if (!covered[u]) {
                    int v = u;
                    for (int i = 0; i < k; i++)
                         v = p[v];
                    cover(0, v, 0);
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
