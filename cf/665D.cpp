#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e3 + 42;

bool isprime(int x)
{
    if (x < 3)
        return x == 2;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> v[2];
    int num_one = 0;
    for (int i = 0, a; i < n; ++i) {
        scanf("%d", &a);
        if (a == 1)
            ++num_one;
        v[a & 1].push_back(a);
    }

    int ans = 0;
    if (num_one > 1) {
        for (int a : v[0]) {
            if (isprime(a + 1)) {
                ans = a;
                break;
            }
        }
        printf("%d\n", num_one + (ans ? 1 : 0));
        if (ans)
            printf("%d ", ans);
        while (num_one)
            printf("1%c", --num_one ? ' ' : '\n');
    } else {
        for (int x : v[0])
            for (int y : v[1])
                if (isprime(x + y)) {
                    printf("2\n%d %d\n", x, y);
                    return 0;
                }
        printf("1\n%d\n", v[0].size() ? v[0][0] : v[1][0]);
    }

    return 0;
}
