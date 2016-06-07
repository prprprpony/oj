#include <cstdio>
using namespace std;
int C(int n, int k)
{
    if (k > n - k)
        k = n - k;
    long long ret = 1;
    for (int i  = 1; i <= k; ++i)
        ret = ret * (n - k + i) / i;
    return ret;
}
int main()
{
    int n, k;
    while (scanf("%d%d", &n, &k) == 2 && n)
        printf("%d\n", C(n, k));
}
