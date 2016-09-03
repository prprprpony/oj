#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 5.64e5;
int a[maxn];
int premin[maxn];
int postmax[maxn];
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d", a + i);
    premin[1] = a[1];
    for (int i = 2; i < N; ++i)
        premin[i] = min(premin[i-1], a[i]);
    postmax[N] = a[N];
    for (int i = N - 1; i > 1; --i)
        postmax[i] = max(postmax[i + 1], a[i]);
    int ans = -1;
    for (int i = 2; i < N; ++i)
        if (premin[i - 1] <= a[i] && a[i] <= postmax[i + 1])
            ans = max(ans, (a[i] - premin[i - 1]) * (postmax[i + 1] - a[i]));
    printf("%d\n", ans);
}
