#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    while (scanf("%d", &N) == 1) {
        int ans;
        scanf("%d", &ans);
        for (int i = 1; i < N; ++i) {
            int p;
            scanf("%d", &p);
            ans = __gcd(ans, p);
        }
        printf("%d\n", ans);
    }
}
