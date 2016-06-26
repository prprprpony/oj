#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 228;
int c[maxn];
ll sum[maxn];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", c + i);
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i-1] + c[i];

#ifdef PP
for (int i = 1; i <= n; ++i)
    printf("%12d ", c[i]);
puts("");
#endif
    
    ll low = 1, high = 2e9;
    while (low <= high) {
        ll mid = (low + high) / 2;
        int i = lower_bound(c + 1, c + n + 1, mid) - c - 1;
        if (mid * i - sum[i] <= k)
            low = mid + 1;
        else
            high = mid - 1;
    }

    {
        int left = k;
        for (int i = 1; i <= n && c[i] < high; ++i) {
            left -= high - c[i];
            c[i] = high;
        }
        for (int i = upper_bound(c + 1, c + n + 1, high) - c - 1; left; --left, --i)
            ++c[i];
    }

#ifdef PP
for (int i = 1; i <= n; ++i)
    printf("%12d ", c[i]);
puts("");
#endif

    for (int i = n; i >= 1; --i)
        sum[i] = sum[i + 1] + c[i];
    low = 1;
    high = 2e9;
    while (low <= high) {
        int mid = (low + high) / 2;
        int i = upper_bound(c + 1, c + n + 1, mid) - c;
        if (sum[i] - (ll)mid * (n - i + 1) <= k)
            high = mid - 1;
        else
            low = mid + 1;
    }

    {
        int left = k;
        for (int i = n; i >= 1 && c[i] > low; --i) {
            left -= c[i] - low;
            c[i] = low;
        }
        for (int i = lower_bound(c + 1, c + n + 1, low) - c; left; --left, ++i)
            --c[i];
    }

#ifdef PP
for (int i = 1; i <= n; ++i)
    printf("%12d ", c[i]);
puts("");
#endif

    printf("%d\n", c[n] - c[1]);
}
