#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxk = 100000;
pair<int, int> n[maxk];
int a[maxk];
long long ans;

struct BIT
{
    int b[maxk + 1];
    int k;
    void init(int k)
    {
        this->k = k;
        memset(b + 1, 0, k * sizeof(int));
    }
    inline int lowbit(int x)
    {
        return x & -x;
    }
    void add(int x, int v)
    {
        while (x <= k)
        {
            b[x] += v;
            x += lowbit(x);
        }
    }
    int sum(int x)
    {
        int r = 0;
        while (x > 0)
        {
            r += b[x];
            x -= lowbit(x);
        }
        return r;
    }
} B;

bool cmp(const int &x, const int &y)
{
    return (n[x].second > n[y].second) || (n[x].second == n[y].second && x > y);
}

int main()
{
    int k;
    scanf("%d%*d", &k);
    for (int i = 0; i < k; i++)
        scanf("%d", &n[i].first);
    for (int i = 0; i < k; i++)
        scanf("%d", &n[i].second);

    sort(n, n + k);
    for (int i = 0; i < k; i++)
        a[i] = i;
    sort(a, a + k, cmp);
    B.init(k);
    ans = 0;
    for (int i = 0; i < k; i++) {
        B.add(a[i] + 1, 1);
        ans += B.sum(a[i]);
    }

    printf("%lld\n",ans);

    return 0;
}
