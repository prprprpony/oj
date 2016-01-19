#include <bits/stdc++.h>
#define MAXANS 13
using namespace std;
int maxd;
int a[MAXANS + 1];
bool vis[(1 << MAXANS) + 1];
int n;

bool dfs(int d, int maxv)
{
    if (a[d] == n)
        return true;
    else if (d == maxd)
        return false;
    else if ((maxv << (maxd - d)) < n)
        return false;

    vis[a[d]] = true;

    for (int i = d; i >= 0; i--) {
        a[d+1] = maxv + a[i];
        if (dfs(d+1, a[d+1]))
            return true;
    }

    for (int i = 0; i < d; i++) {
        if ((a[d+1] = maxv - a[i]) > 1) {
            if (!vis[a[d+1]] && dfs(d+1, maxv))
                return true;
        }
    }

    vis[a[d]] = false;

    return false;
}

int main()
{
#ifdef TABLE
    puts("#include <cstdio>");
    fputs("int ans[] = {0", stdout);
    for (n = 1; n <= 1000; n++) {
#else
    while (scanf("%d", &n) == 1 && n > 0) {
#endif
        for (maxd = 0; ; maxd++) {
            a[0] = 1;
            memset(vis, 0, sizeof(vis));
            if (dfs(0, 1))
                break;
        }
#ifdef TABLE
        printf(",\n%d", maxd);
#else
        printf("%d\n", maxd);
#endif
    }

#ifdef TABLE
    puts("};");
    puts(
            "int n;\n"
            "int main()\n"
            "{\n"
            "    while (scanf(\"%d\", &n) == 1 && n > 0)\n"
            "        printf(\"%d\\n\", ans[n]);\n"
            "    return 0;\n"
            "}"
        );
#endif

    return 0;
    }
