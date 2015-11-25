#include <stdio.h>
#include <math.h>
#define MAXN 1000
double x[MAXN], y[MAXN];
double max(double a, double b){return a > b ? a : b;}
int main()
{
    int n, i, j, k;
    double ans = 0.0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%lf%lf", x + i, y + i);
    for (i = 0; i < n - 2; i++)
        for (j = i + 1; j < n - 1; j++)
            for (k = j + 1; k < n; k++)
                ans = max(ans, fabs(((x[i] * y[j] + x[j] * y[k] + x[k] * y[i]) - (x[j] * y[i] + x[k] * y[j] + x[i] * y[k])) / 2.0));
    printf("%.6f\n", ans);
    return 0;
}
