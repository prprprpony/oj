#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 500;

int gcd(int a, int b)
{
    return b != 0 ? gcd(b, a % b) : a;
}

struct fraction
{
    int m;
    int s;
    fraction(int a, int b) : s(a), m(b)
    {
        int g = gcd(s, m);
        s /= g;
        m /= g;
    }
    friend bool operator < (const fraction &a, const fraction &b)
    {
        int g = gcd(a.m, b.m);
        return b.m / g * a.s < a.m / g * b.s;
    }
};
int main()
{
    int t, n, m;
    int a[maxn][maxn];
    scanf("%d", &t);
    while (t--) {
        fraction ans(0, 1);
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &a[i][j]);
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
                for (int k = 2, sum = a[i][j]; j-k+1 >= 0 && k <= 3; k++) {
                    sum += a[i][j-k+1];
                    ans = max(ans, fraction(sum, k));
                }
        for (int i = 1; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 2, sum = a[i][j]; i-k+1 >= 0 && k <= 3; k++) {
                    sum += a[i-k+1][j];
                    ans = max(ans, fraction(sum, k));
                }
        printf("%d/%d\n", ans.s, ans.m);
    }
    return 0;
}
