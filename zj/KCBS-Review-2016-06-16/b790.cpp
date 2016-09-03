#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1.228e5;
int a[maxn];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        bool allneg = true;
        for (int i = 0; i < N; ++i) {
            scanf("%d", a + i);
            if (a[i] >= 0)
                allneg = false;
        }
        if (allneg) {
            int ans = a[0];
            for (int i = 1; i < N; ++i)
                ans = max(a[i], ans);
            printf("%d %d\n", ans, ans);
            continue;
        }
        int ans1 = a[0], ans2 = 0;
        for (int sum = 0, i = 0; i < N; ++i) {
            ans1 = max(ans1, sum += a[i]);
            if (sum < 0)
                sum = 0;
            if (a[i] > 0)
                ans2 += a[i];
        }
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}
