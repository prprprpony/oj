#include <cstdio>
using namespace std;
int gcd(int a, int b)
{
    int t;
    while (b) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int C(int n, int k)
{
    if (k > n - k)
        k = n - k;
    int ret = 1;
    for (int i  = 1; i <= k; ++i) {
        int g = gcd(ret, i);
        ret = ret / g * ((n - k + i) / (i / g));
    }
    return ret;
}
int main()
{
    int n, k;
    while (scanf("%d%d", &n, &k) == 2 && n)
        printf("%d\n", C(n, k));
}
