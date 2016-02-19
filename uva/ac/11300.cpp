#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAXN (int)1e6 + 42
using namespace std;
typedef long long ll;
ll a[MAXN], c[MAXN];
ll select(int l, int r, int k) {
    while (1) {
        // pivot = c[l]
        swap(c[l], c[l + rand() % (r-l+1)]);
        int i = l + 1, j = r;
        while (1) {
            while (i <= r && c[i] <= c[l])
                i++;
            while (j > l && c[j] > c[l])
                j--;
            if (i < j)
                swap(c[i], c[j]);
            else
                break;
        }
        swap(c[l], c[j]);
        // c[l] is the jth element
        if (j < k) {
            l = j + 1;
        } else if (j > k) {
            r = j - 1;
        } else {
            return c[j];
        }
    }
}
int main()
{
    srand(42);
    int n;
    while (scanf("%d", &n) == 1) {
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", a + i);
            sum += a[i];
        }
        ll m = sum / n;
        c[0] = 0;
        for (int i = 1; i < n; i++)
            c[i] = c[i-1] + a[i] - m;
        ll x = select(0, n-1, n/2);
        ll ans = 0;
        for (int i = 0; i < n; i++)
            ans += abs(x - c[i]);
        printf("%lld\n", ans);
    }
    return 0;
}
