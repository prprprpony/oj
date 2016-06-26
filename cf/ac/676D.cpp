#include <cstdio>
#include <utility>
#include <vector>
#include <cassert>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 1000 + 64;
int n, m;
int g[maxn][maxn];
vector<int> adj[maxn * maxn * 4];
bool vis[maxn * maxn * 4];
/*
 mask
 8   4    2   1
 ^   <-   |   ->
 |        v
*/
const char ch[] = "*>v <- U^ |L DR+";
const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

inline void read_pii(pii & a)
{
    scanf("%d%d", &a.first, &a.second);
    --a.first;
    --a.second;
}

inline int Hash(int r, int c, int d)
{
    return (r * m + c) * 4 + d;
}

inline int getmask(char c)
{
    for (int i = 0; ch[i]; ++i)
        if (c == ch[i])
            return i;
    assert(0);
}

inline int rotate_mask(int mask, int d)
{
    return ((mask << d) & 0xf) | (mask >> (4 - d));
}

inline bool inrange(int r, int c)
{
    return 0 <= r && r < n && 0 <= c && c < m;
}

int main()
{
    scanf("%d%d ", &n, &m);
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c)
            g[r][c] = getmask(getchar());
        getchar();
    }
    pii ts, mt;

    read_pii(ts);
    read_pii(mt);
    if (ts == mt) {
        puts("0");
        return 0;
    }

    for (int r = 0; r < n; ++r)
        for (int c = 0; c < m; ++c)
            for (int d = 0; d < 4; ++d) {
                int key = Hash(r, c, d);
                int mask = rotate_mask(g[r][c], d);
                adj[key] = {Hash(r, c, (d + 1) % 4)};
                for (int i = 0; i < 4; ++i)
                    if (mask & (1 << i)) {
                        int nr = r + dr[i], nc = c + dc[i];
                        if (inrange(nr, nc) && (rotate_mask(g[nr][nc], d) & (1 << ((i + 2) % 4))))
                            adj[key].push_back(Hash(nr, nc, d));
                    }
            }

    int ans = -1;
    queue<pii> q;
    q.push({0, Hash(ts.first, ts.second, 0)});
    vis[Hash(ts.first, ts.second, 0)] = true;
    while (!q.empty()) {
        pii x = q.front();
        q.pop();
        for (int nxt : adj[x.second])
            if (!vis[nxt]) {
                if (nxt / 4 == Hash(mt.first, mt.second, 0) / 4) {
                    ans = x.first + 1;
                    goto output;
                }
                vis[nxt] = true;
                q.push({x.first + 1, nxt});
            }
    }

output:
    printf("%d\n", ans);
}
