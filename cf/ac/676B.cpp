#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 11;
const double eps = 1e-6;
double cup[maxn][maxn];
int n, t;

bool equal(double a, double b) {
    return fabs(a-b) < eps;
}

void fill(int i, int j, double v) {
    for (; i < n && (cup[i][j] += v) > 1.0; ++i) {
        v = (cup[i][j] - 1.0) / 2.0;
        cup[i][j] = 1.0;
        fill(i + 1, j + 1, v);
    }
}

int main()
{
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            cup[i][j] = 0.0;
    while (t--)
        fill(0, 0, 1.0);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (equal(cup[i][j], 1.0))
                ++ans;
            // printf("cup[%d][%d] = %f\n", i, j, cup[i][j]);
        }
        // puts("");
    }
    printf("%d\n", ans);
}
