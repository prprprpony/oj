#include <bits/stdc++.h>
#define MAXN (int)2e5
#define MAXA (int)1e6
using namespace std;
int a[MAXN];
int main()
{
    srand(time(NULL));
    int n = MAXN;
    int m = MAXN;
    printf("%d %d\n", n, m);
    for (int i = 0, j; i < n; i += j) { // srqt(n) different elements
        a[i] = rand() % MAXA + 1;
        for (j = 1; j * j < n && i + j < n; j++)
            a[i + j] = a[i];
    }
    for (int i = 0; i < n; i++) {
        swap(a[i], a[i + rand() % (n - i)]);
        printf("%d ", a[i]);
    }
    putchar('\n');
    while (m--) {
        int l, r;
        l = rand() % n;
        r = rand() % n;
        if (l > r)
            swap(l, r);
        int x = a[l + rand() % (r - l + 1)];
        printf("%d %d %d\n", l + 1, r + 1, x);
    }

    return 0;
}
