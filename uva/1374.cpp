#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#define MAXN 1000
using namespace std;

int maxd;
int *a = NULL;
bool have[MAXN<<2];
int n;

int hypo(int n)
{
    int lead_pos = -1;
    int one_num = 0;
    for (int i = (sizeof(int) << 3) - 1; i >= 0; i--) {
        if ((1 << i) & n) {
            if (lead_pos == -1)
                lead_pos =  i;
            else
                one_num++;
        }
    }
    return min(lead_pos + one_num, lead_pos + 2 + (lead_pos - one_num));
//             n^lgn * n^i ....    n^(lgn + 1) / n / n^i ....
}

bool dfs(int d)
{
    if (have[n])
        return true;
    if (d > maxd)
        return a[d-1] == n;
    if ((a[d-1] << (maxd - d + 1)) < n)
        return false;
    else if ((a[d-1] << (maxd - d + 1)) == n)
        return true;

    for (int i = d - 1; i >= 0; i--) {
        a[d] = a[d-1] + a[i];
        if (!have[a[d]]) {
            have[a[d]] = true;
            if(dfs(d+1))
                return true;
            have[a[d]] = false;
        }
    }

    for (int i = 0; i < d; i++) {
        a[d] = a[d-1] - a[i];
        if (!have[a[d]]) {
            have[a[d]] = true;
            if(dfs(d+1))
                return true;
            have[a[d]] = false;
        }
    }

    return false;
}

int main()
{
    int h;
    while (scanf("%d", &n) == 1 && n > 0) {
        h = hypo(n);
        if (h > 1) {
            memset(have, 0, sizeof(have));
            a = (int *)realloc(a, h * sizeof(int));
            a[0] = 1;
            a[1] = 2;
            have[0] = have[1] = have[2] = true;
        }
printf("a = %x\n", a);
printf("h(%d) = %d\n", n, h);
        for (maxd = 2; maxd < h; maxd++) // maxd = 0 -> n = 1, maxd = 1, n = 2
            if(dfs(2))
                break;
        printf("%d\n", min(maxd, h));
    }

    return 0;
}
