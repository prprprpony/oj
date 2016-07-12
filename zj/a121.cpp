#include <cstdio>
bool isprime(int x)
{
    if (x == 1 || (x > 2 && !(x & 1)))
        return false;
    for (int i = 3; i * i <= x; i += 2)
        if (!(x % i))
            return false;
    return true;
}
int main()
{
    int a, b;
    while (scanf("%d%d", &a, &b) == 2) {
        int ans = 0;
        for ( ; a <= b; ++a)
            if (isprime(a))
                ++ans;
        printf("%d\n", ans);
    }
}
