#include <cstdio>
#include <algorithm>
using namespace std;
const int maxstep = 5;
int stat[4];
const int m[][2] = {
    {1, 1},
    {2, 0},
    {0, 2},
    {1, 0},
    {0, 1},
};
int ans;
void dfs(int side, int step)
{
#ifdef PP
puts(side ? "Right" : "Left");
printf("step = %d\n", step);
for (int i = 0; i < 4; ++i)
    printf("%d ", stat[i]);
puts("\n");
#endif
    for (int i = 0; i < 4; ++i)
        if (stat[i] < 0)
            return;
    for (int i = 0; i < 4; i += 2)
        if (stat[i] > 0 && stat[i] < stat[i + 1])
            return;
    if (!stat[2] && !stat[3]) {
        ans = step;
        return;
    }
    for (int i = 0; i < 5; ++i) {
        if (step >= ans - 1)
            return;
        for (int j = 0; j <= 1; ++j)
            stat[side + j] -= m[i][j];
        for (int j = 0; j <= 1; ++j)
            stat[(2 - side) + j] += m[i][j];
        dfs(2 - side, step + 1);
        for (int j = 0; j <= 1; ++j)
            stat[side + j] += m[i][j];
        for (int j = 0; j <= 1; ++j)
            stat[(2 - side) + j] -= m[i][j];
    }
}
int main(void)
{
    int n;
    scanf("%d", &n);
    while (n--) {
        for (int i = 0; i < 4; ++i)
            scanf("%d", stat + i);
        ans = maxstep + 1;
        dfs(2, 0);
        if (ans <= maxstep)
            printf("Cracked in %d steps!!!\n", ans);
        else
            puts("Too hard!!!");
    }
    return 0;
}
