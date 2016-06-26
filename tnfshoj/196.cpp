#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 228;
int k[maxn];
int N;
bool ok(int w)
{
    if (k[0] * 2 > w || k[N-1] * 2 < w)
        return false;
    if (!(w & 1) && binary_search(k, k + N, w / 2))
        return true;
    if (N < 2 || k[0] + k[1] > w || k[N-2] + k[N-1] < w)
        return false;
    int j = upper_bound(k, k + N, w) - k - 1;
    int i = lower_bound(k, k + j - 1, w - k[j]) - k;
    for (; i < j; ++i) {
        while (i < j && k[i] + k[j] > w)
            --j;
        if (i < j && k[i] + k[j] == w)
            return true;
    }
    return false;
}
int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d", k + i);
    sort(k, k + N);
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int w;
        scanf("%d", &w);
        puts(ok(w) ? "yes" : "no");
    }
}
