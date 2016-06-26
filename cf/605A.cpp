#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 228;
int p;
int pos[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &p);
        pos[p] = i;
    }
    int len = 1;
    for (int a = 2, cnt = 1; a <= n; ++a) {
        if (pos[a] > pos[a - 1])
            len = max(len, ++cnt);
        else
            cnt = 1;
    }
    printf("%d\n", n - len);
}
