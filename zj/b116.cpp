/* the same as tcfsh's d014
 * and I put test data there
*/ 
#include <cstdio>
#include <algorithm>
#include <functional>
#define MAXN 110
using namespace std;

int m, n;
int a[MAXN];
int s[MAXN];

#ifdef DEBUG
int tot;
#endif

bool dfs(int k, int sum)
{
#ifdef DEBUG
tot++;
#endif
    if (s[n-1] == (sum << 1))
        return true;
    if (s[n-1] < (sum << 1))
        return false;
    int maxsum = sum + s[n-1] - s[k-1];
    if ((maxsum << 1) < s[n-1])
        return false;
    else if ((maxsum << 1) == s[n-1])
        return true;
    for (int i = k; i < n; i++)
        if (i == k || a[i] != a[i-1])
            if (dfs(i + 1, sum + a[i]))
                return true;
    return false;
}

int main()
{
    while (scanf("%d%d", &m, &n) == 2) {
        while (m--) {
            if (n == 1) {
                scanf("%*d");
                puts("No");
                continue;
            }

            for (int i = 0; i < n; i++)
                scanf("%d", &a[i]);
#ifdef SUCKER
sort(a, a+n);
#else
            sort(a, a+n, greater<int>());
#endif
            for (int i = 0; i < n; i++)
                s[i] = i ? s[i-1] + a[i] : a[0];
#ifdef DEBUG
tot = 0;
#endif
            if (s[n-1] & 1)
                puts("No");
            else
                puts(dfs(1, a[0]) ? "Yes" : "No");
#ifdef DEBUG
printf("tot = %d\n", tot);
#endif
        }
    }

    return 0;
}
