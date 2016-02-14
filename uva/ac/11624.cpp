#include <bits/stdc++.h>
#define MAXN (1000 + 42)
#define R first
#define C second
using namespace std;
typedef pair<int, int> pii;
char g[MAXN][MAXN];
int b[MAXN][MAXN];
int w[MAXN][MAXN];
int R, C;
pii d[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

pii walk(pii a, pii b) {
    a.R += b.R;
    a.C += b.C;
    return a;
}

bool inrange(pii p) {
    return 0 <= p.R && p.R < R && 0 <= p.C && p.C < C;
}

bool block(pii p) {
    return g[p.R][p.C] == '#';
}

int& burn_t(pii p) {
    return b[p.R][p.C];
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        queue<pii> f, j;
        scanf("%d%d ", &R, &C);
        for (int r = 0; r < R; r++)
            memset(b[r], -1, C * sizeof(int));
        for (int r = 0; r < R; r++)
            memset(w[r], -1, C * sizeof(int));
        for (int r = 0; r < R; r++) {
            fgets(g[r], sizeof(g[r]), stdin);
            for (int c = 0; c < C; c++)
                switch (g[r][c]) {
                    case 'F':
                        b[r][c] = 0;
                        f.push({r, c});
                        break;
                    case 'J':
                        w[r][c] = 0;
                        j.push({r, c});
                        break;
                }
        }
        while (!f.empty()) {
            pii p = f.front();
            f.pop();
            int t = burn_t(p) + 1;
            for (pii x : d) {
                pii n = walk(p, x);
                if (inrange(n) && !block(n) && burn_t(n) == -1) {
                    burn_t(n) = t;
                    f.push(n);
                }
            }
        }
        int fin = -1;
        while (!j.empty()) {
            pii p = j.front();
            j.pop();
            int t = w[p.R][p.C] + 1;
            for (pii x : d) {
                pii n = walk(p, x);
                if (inrange(n)) {
                    if (!block(n) && (burn_t(n) > t || burn_t(n) == -1) && w[n.R][n.C] == -1) {
                        w[n.R][n.C] = t;
                        j.push(n);
                    }
                } else {
                    fin = t;
                    goto output;
                }
            }
        }
output:
        if (fin != -1)
            printf("%d\n", fin);
        else
            puts("IMPOSSIBLE");
    }
}    
