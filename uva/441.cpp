#include <bits/stdc++.h>
#define MAXK 49
#define LEN 6
using namespace std;
int k;
int v[MAXK];
int p[LEN];
void dfs(int i, int j) {
    if (j == LEN) {
        for (int n = 0; n < LEN; n++)
            printf("%d%c", p[n], n != LEN - 1 ? ' ' : '\n');
        return;
    }
    for (; i <= k - (LEN - j); i++) {
        p[j] = v[i];
        dfs(i + 1, j + 1);
    }
}
int main()
{
    bool first = true;
    while (scanf("%d", &k) == 1 && k) {
        if (!first)
            putchar('\n');
        else
            first = false;
        for (int i = 0; i < k; i++)
            scanf("%d", v + i);
        dfs(0, 0);
    }
}
