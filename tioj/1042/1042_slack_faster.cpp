#include <cstdio>
#include <cstring>
#include <cctype>

const int inf = 2e9;
const int maxn = 104;
int N;
int w[maxn][maxn];

int mx[maxn], my[maxn];
int lx[maxn], ly[maxn];
int px[maxn];

int slack[maxn]; // slack[y] = min{lx[x] + ly[y] - w[x][y] | 0 <= x < N}
int slack_x[maxn];

int qx[maxn]; // queue of vx
int q_size;

struct Node
{
    int nxt;
    int pre;
} node[maxn]; // linked-list of !vy

int cand[maxn]; // new y to connect after updating slack

inline int rin(int & a) // read a natural number
{
    int c;
    a = 0;

    while (!(isdigit(c = getchar()) || c == '-'));

    if (c == '-') {
        while (isdigit(getchar()));
        return 0;
    }

    do {
        a = 10 * a + c - '0';
    } while (isdigit(c = getchar()));

    return a;
}

inline void link(int a, int b)
{
/*
    nxt[a] = b;
    pre[b] = a;
*/
    node[a].nxt = b;
    node[b].pre = a;
}

inline void remove(int a)
{
    // link(pre[a], nxt[a]);
    link(node[a].pre, node[a].nxt);
}

inline void augment(int x, int y)
{
    while (y != -1) {
        int t = mx[x];
        mx[x] = y;
        my[y] = x;
        x = px[x];
        y = t;
    }
}

inline bool branch(int x, int y) 
{
    remove(y);
    if (my[y] == -1) {
        augment(x, y);
        return true;
    } else {
        px[my[y]] = x;
        qx[q_size++] = my[y];
        return false;
    }
}

int KM()
{
    memset(lx, 0, N * sizeof(int));
    memset(ly, 0, N * sizeof(int));
    for (int x = 0; x < N; ++x)
        for (int y = 0; y < N; ++y)
            if (w[x][y] > lx[x])
                lx[x] = w[x][y];

    memset(mx, -1, N * sizeof(int));
    memset(my, -1, N * sizeof(int));

    for (int x = 0; x < N; ++x) {
        int old_size = 0;
        q_size = 1;
        qx[0] = x;

        link(N, 0);
        for (int y = 0; y < N; ++y) {
            link(y, y + 1);
            slack[y] = inf;
        }

        while (1) {
            // bfs
            // branch result from new x
            for (int i = old_size; i < q_size; ++i)
                // for (int j = nxt[N]; j != N; j = nxt[j])
                for (int j = node[N].nxt; j != N; j = node[j].nxt)
                    if (lx[qx[i]] + ly[j] == w[qx[i]][j] && branch(qx[i], j))
                        goto next_x;

            // update slack
            // for (int y = nxt[N]; y != N; y = nxt[y])
            for (int y = node[N].nxt; y != N; y = node[y].nxt)
                for (int i = old_size; i < q_size; ++i) {
                    int v = lx[qx[i]] + ly[y] - w[qx[i]][y];
                    if (slack[y] > v) {
                        slack[y] = v;
                        slack_x[y] = qx[i];
                    }
                }
            old_size = q_size;

            //caculate d
            int d = inf;
            int cand_size = 0;
            // for (int y = nxt[N]; y != N; y = nxt[y]) {
            for (int y = node[N].nxt; y != N; y = node[y].nxt) {
                if (d > slack[y]) {
                    d = slack[y];
                    cand[0] = y;
                    cand_size = 1;
                } else if (d == slack[y])
                    cand[cand_size++] = y;
            }

            // assert(d != inf);

            //reweight
            for (int i = 0; i < q_size; ++i)
                lx[qx[i]] -= d;

            // for (int y = 0, j = nxt[N]; y < N; ++y)
            for (int y = 0, j = node[N].nxt; y < N; ++y)
                if (y != j) {
                    ly[y] += d;
                } else {
                    slack[y] -= d;
                    // j = nxt[j];
                    j = node[j].nxt;
                }
            //branch result from reweight
            for (int j = 0; j < cand_size; ++j)
                if (branch(slack_x[cand[j]], cand[j]))
                    goto next_x;
        }
next_x:;
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
    while (rin(N)) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                rin(w[i][j]);
        printf("%d\n", KM());
    }
}
