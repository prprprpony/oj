#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
const int maxn = 999;
const int inf = 1e9;
int n, m;
int g[maxn][maxn];
int d[maxn][maxn];
bool vis[maxn][maxn];
int dr[] = {0, 1, -1, 0}; // h, j, k, l
int dc[] = {-1, 0, 0, 1};
struct HeapNode
{
    int r;
    int c;
    int dist;
    HeapNode(int i, int j, int k) : r(i), c(j), dist(k) {}
    friend bool operator > (const HeapNode &a, const HeapNode &b)
    {
        return a.dist > b.dist;
    }
    bool canmove(int dir)
    {
        int nr = r + dr[dir], nc = c + dc[dir];
        return  0 <= nr && nr < n &&  0 <= nc && nc < m && !vis[nr][nc] && d[nr][nc] > dist + g[nr][nc];
    }
    HeapNode move(int dir)
    {
        int nr = r + dr[dir], nc = c + dc[dir], nd = dist + g[nr][nc];
        d[nr][nc] = min(d[nr][nc], nd);
        return HeapNode(nr, nc, nd);
    }
};
int main()
{
#ifdef FILETEST
freopen("929_data", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &g[i][j]);
                d[i][j] = inf;
                vis[i][j] = false;
            }
        }
        priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode> > pq;
        pq.push(HeapNode(0, 0, g[0][0]));
        while (!vis[n-1][m-1]) {
            while (vis[pq.top().r][pq.top().c])
                pq.pop();
            HeapNode nd = pq.top();
            pq.pop();
            d[nd.r][nd.c] = nd.dist;
            vis[nd.r][nd.c] = true;
            for (int i = 0; i < 4; i++)
                if (nd.canmove(i))
                    pq.push(nd.move(i));
        }
        printf("%d\n", d[n-1][m-1]);
    }
    return 0;
}
