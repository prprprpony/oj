#include <cstdio>
#include <algorithm>
#include <cstring>
#define PN 4
#define MAXH 41
#define BV 5
using namespace std;

int n;
int pile[PN][MAXH];
int d[MAXH][MAXH][MAXH][MAXH];
int h[PN];

int dp(int state, int v)
{
    int &c = d[h[0]][h[1]][h[2]][h[3]];
    if (c != -1)
        return c;
    else
        c = 0;
    if (v == BV)
        return c;
    for (int i = 0, t; i < PN; i++) {
        if (h[i] > 0) {
            t = (1 << (pile[i][h[i]] - 1));
            h[i]--;
            if (state & t)
                c = max(dp(state ^ t, v - 1) + 1, c);
            else
                c = max(dp(state | t, v + 1), c);
            h[i]++;
        }
    }
    return c;
}

int main()
{
    while (scanf("%d", &n) == 1 && n > 0) {
        for (int t = n; t > 0; t--)
            for (int p = 0; p < PN; p++)
                scanf("%d", &pile[p][t]);
        memset(d, -1, sizeof(d));
        for (int i = 0; i < PN; i++)
            h[i] = n;
        printf("%d\n", dp(0, 0));
    }
    return 0;
}
