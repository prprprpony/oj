#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int a[64];
map<int, int> cnt;
int n, m;
int c, maxways;
void dfs(int d, int i, int sum)
{
    if (d == m) {
        int w = ++cnt[sum];
        if (w > maxways || (w == maxways && sum < c)) {
            c = sum;
            maxways = w;
        }
        return;
    }
    for ( ; n - i >= m - d; ++i)
        dfs(d + 1, i + 1, sum + a[i]);
}
int main()
{
    while (scanf("%d%d", &n, &m) == 2 && n) {
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        maxways = 0;
        cnt.clear();
        dfs(0, 0, 0);
        printf("%d %d\n", c, maxways);
    }
}
