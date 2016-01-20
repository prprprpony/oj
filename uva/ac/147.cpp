#include <bits/stdc++.h>
using namespace std;

int c[] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000}; // divided by 5c
const int n = 300 * 100 / 5;
const int cn = sizeof(c) / sizeof(int);
long long dp[n + 1];

int main()
{
    for (int i = 0; i <= n; i++)
        dp[i] = 1; // because c[0] = 1, all number can be paid

    for (int i = 1; i < cn; i++)
        for (int j = c[i]; j <= n; j++)
                dp[j] += dp[j-c[i]];

    int a, b;
    while (scanf("%d.%d", &a, &b) == 2 && (a || b))
        printf("%3d.%02d%17lld\n", a, b, dp[(a * 100 + b) / 5]);

    return 0;
}
