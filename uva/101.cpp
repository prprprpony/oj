#include <cstdio>
#include <vector>
#define MAXN 25
using namespace std;
typedef vector<int> vi;
vi pile[MAXN];
int pid[MAXN];
int h[MAXN];

void put(int i, int p)
{
    pile[p].push_back(i);
    pid[i] = p;
    h[i] = pile[p].size() - 1;
}

void clear_up(int a) // return all blocks above t to their initial positions
{
    vi& p = pile[pid[a]];
    for (int i = p.size() - 1; i > h[a]; i--) {
        put(p[i], p[i]);
        p.pop_back();
    }
}

void move_up(int a, int p) // move a and all elements above a to pile[p]
{
    vi& pa = pile[pid[a]];
    int newh = h[a];
    for (int i = newh; i < pa.size(); i++)
        put(pa[i], p);
    pa.resize(newh);
}

int main()
{
    int n;
    char cmd[5], pos[5];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        put(i, i);
    while (scanf("%s", cmd) == 1 && cmd[0] != 'q') {
        int a, b;
        scanf("%d%s%d", &a, pos, &b);
        if (pid[a] == pid[b])
            continue;
        if (cmd[0] == 'm')
            clear_up(a);
        if (pos[1] == 'n')
            clear_up(b);
        move_up(a, pid[b]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        for (int b : pile[i])
            printf(" %d", b);
        putchar('\n');
    }

    return 0;
}
