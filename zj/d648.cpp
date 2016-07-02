#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2 && n)
        puts(((n & 1) ^ (m & 1)) && __gcd(n, m) == 1 ? "YES" : "Impossible");
}
