#include<bits/stdc++.h>
using namespace std;
const int dr[] = {-1, -1, 0, 0, 1, 1};
const int dc[] = {0, 1, -1, 1, -1, 0};
const int N = 305, inf = 1e9;
char g[N][N];
int d[N][N];
void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", g[i]);
        fill_n(d[i], m, inf);
    }
    deque<pair<int, int>> dk;
    for (int j = 1; j < m; ++j) {
        if (g[0][j] == 'O') {
            d[0][j] = 0;
            dk.emplace_front(0, j);
        } else {
            d[0][j] = 1;
            dk.emplace_back(0, j);
        }
    }
    for (int i = 1; i + 1 < n; ++i) {
        if (g[i][m - 1] == 'O') {
            d[i][m - 1] = 0;
            dk.emplace_front(i, m - 1);
        } else {
            d[i][m - 1] = 1;
            dk.emplace_back(i, m - 1);
        }
    }
    while (dk.size()) {
        int i, j;
        tie(i, j) = dk.front();
        dk.pop_front();
        if (i == n - 1 || j == 0) {
            printf("%d\n", d[i][j]);
            return;
        }
        for (int k = 0; k < 6; ++k) {
            int x = i + dr[k], y = j + dc[k];
            if (min(x, y) < 0 || x >= n || y >= m || d[x][y] != inf)
                continue;
            if (make_pair(x, y) == make_pair(0, 0) || make_pair(x, y) == make_pair(n - 1, m - 1))
                continue;
            if (g[x][y] == 'O') {
                d[x][y] = d[i][j];
                dk.emplace_front(x, y);
            } else {
                d[x][y] = d[i][j] + 1;
                dk.emplace_back(x, y);
            }
        }
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
}
