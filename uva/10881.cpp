#include <cstdio>
#include <cstring>
using namespace std;
int l, t, n;

struct Ant 
{
    int x;
    int d;
    bool turn;
    bool fell;
};

bool inrange(int x)
{
    return x >= 0 && x <= l;
}

int main(void)
{
    int N, case_num;
    int i, j, k, m;
    char c;
    int p;
    scanf("%d", &N);
    for (case_num = 1; case_num <= N; ++case_num) {
        scanf("%d%d%d", &l, &t, &n);
        Ant a[n+1];
        int pole[l+1] = {0};
        bool vis[n+1];
        for (i = 1; i <= n; ++i) {
            scanf("%d %c", &a[i].x, c);
            a[i].d = (c == 'R') ? 1 : -1;
            a[i].turn = false;
            a[i].fell = false;
            pole[a[i].x] = i;
        }

        for (i = 0; i < t; ++i) {
            memset(vis, 0, sizeof(vis));
            for (j = 1; j <= n; ++j) {
                if (a[j].turn)
                    a[j].turn = false;
                if (!vis[j]) {
                    if (inrange(k = a[j].x + a[j].d) && p = pole[k]) {
                        if (a[p].d == -a[j].d) {
                            a[p].turn = a[j].turn = true;
                            vis[p] = vis[j] = true;
                            a[p].d *= -1;
                            a[j].d *= -1;
                        }
                    }
                    else if (inrange(k = a[j].x + a[j].d * 2) &&  p = pole[k]) {
                        if (a[p].d == -a[j].d) {
                            a[p].turn = a[j].turn = true;
                            vis[p] = vis[j] = true;
                            m = (k + a[j].x) >> 1;
                            pole[m+1] = pole[m-1] = 0;
                            a[p].x = a[j].x = m;
                            pole[m] = p;
                            a[p].d *= -1;
                            a[j].d *= -1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
