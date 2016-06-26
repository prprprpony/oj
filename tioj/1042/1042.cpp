#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <queue>
using namespace std;

const int inf = 2e9;
const int maxn = 104;
int N;
int w[maxn][maxn];

int mx[maxn], my[maxn];
int lx[maxn], ly[maxn];
bool vx[maxn], vy[maxn];

int pre[maxn]; // for bfs

bool bfs(int x)
{
    bool ret = false;
    queue<int> q;
    q.push(x);
    memset(pre, -1, N * sizeof(int));

    int y;
    while (!q.empty() && !ret) {
        x = q.front();
        q.pop();
        vx[x] = true;
        for (y = 0; y < N; ++y)
            if (!vy[y] && lx[x] + ly[y] == w[x][y]) {
                vy[y] = true;
                if (my[y] == -1) {
                    ret = true;
                    break;
                } else {
                    pre[my[y]] = x;
                    q.push(my[y]);
                }
            }
    }

    if (ret)
        while (x != -1) {
            int tmp = mx[x];
            mx[x] = y;
            my[y] = x;

            y = tmp;
            x = pre[x];
        }

    return ret;
}

//DFS
bool dfs(int x)
{
    vx[x] = true;
    for (int y = 0; y < N; ++y)
        if (!vy[y] && lx[x] + ly[y] == w[x][y]) {
            vy[y] = true;
            if (my[y] == -1 || dfs(my[y])) {
                mx[x] = y;
                my[y] = x;
                return true;
            }
        }
    return false;
}

int KM()
{
    memset(lx, 0, N * sizeof(int));
    memset(ly, 0, N * sizeof(int));
    for (int x = 0; x < N; ++x)
        for (int y = 0; y < N; ++y)
            lx[x] = max(lx[x], w[x][y]);

    memset(mx, -1, N * sizeof(int));
    memset(my, -1, N * sizeof(int));
    for (int x = 0; x < N; ++x) {
        while (1) {
            memset(vx, 0, N * sizeof(bool));
            memset(vy, 0, N * sizeof(bool));
            if (bfs(x))
                break;
            int d = inf;

            for (int i = 0; i < N; ++i)
                if (vx[i])
                    for (int j = 0; j < N; ++j)
                        if (!vy[j])
                            d = min(d, lx[i] + ly[j] - w[i][j]);

            // assert(d != inf);
            for (int i = 0; i < N; ++i)
                if (vx[i])
                    lx[i] -= d;
            for (int y = 0; y < N; ++y)
                if (vy[y])
                    ly[y] += d;
        }
    }

    int ret = 0;

    for (int x = 0; x < N; ++x) {
        ret += w[x][mx[x]];
#ifdef PP
        printf("(%d,%d) = %d\n", x, mx[x], w[x][mx[x]]);
        printf("sum = %d\n", ret);
#endif
    }
    return ret;
}

int main()
{
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j) {
                scanf("%d", &w[i][j]);
                if (w[i][j] < 0)
                    w[i][j] = 0;
            }
        printf("%d\n", KM());
    }
}
