#include <stdio.h>
const int M = 1e4 + 7;
inline int mul(int a, int b) {return a * b % M;}
int qpow(int x, int n)
{
    int ans = 1;
    x %= M;
    for ( ; n; n >>= 1, x = mul(x, x))
        if (n & 1)
            ans = mul(ans, x);
    return ans;
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", qpow(a, b));
}
