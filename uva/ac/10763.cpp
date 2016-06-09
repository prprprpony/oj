#include <cstdio>
#include <utility>
#include <map>
#include <cassert>
#define A first
#define B second
using namespace std;
typedef pair<int, int> pii;
const int maxn = 5e5 + 228;
pii c[maxn];

int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n > 0) {
        if (n & 1) {
            while (n--)
                scanf("%*d%*d");
            puts("NO");
            continue;
        }
        map<pii, int> cnt;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &c[i].A, &c[i].B);
            ++cnt[c[i]];
        }
        bool ok = true;
        for (int i = 0; ok && i < n; ++i)
            ok = cnt[c[i]] == cnt[pii(c[i].B, c[i].A)];
        puts(ok ? "YES" : "NO");
    }
}
