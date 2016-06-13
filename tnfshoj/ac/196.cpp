#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;
const int maxn = 1e5 + 228;
int k[maxn];
int S;
bool ok(int w)
{
    if (S < 2 || k[0] * 2 > w || k[S-1] * 2 < w)
        return false;
    if (!(w & 1) && *lower_bound(k, k + S, w >> 1) == (w >> 1))
        return true;
    int j = upper_bound(k, k + S, w) - k - 1;
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
    scanf("%d", &S);
    for (int i = 0; i < S; ++i)
        scanf("%d", k + i);
    sort(k, k + S);
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int w;
        scanf("%d", &w);
        puts(ok(w) ? "yes" : "no");
    }
}
