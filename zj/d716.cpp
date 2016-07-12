#include <cstdio>
#include <unordered_set>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 228;
int a[maxn];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        unordered_set<int> s;
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            if (!s.count(a[i]))
                s.insert(a[i]);
            else {
                for (int j = i - s.size(); j < i && a[j] != a[i]; ++j)
                    s.erase(a[j]);
            }
            ans = max(ans, (int)s.size());
        }
        printf("%d\n", ans);
    }
}
