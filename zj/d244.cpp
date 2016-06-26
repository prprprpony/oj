#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 2e6;
int a[maxn];
int main()
{
    int top = 0;
    int v;
    while (scanf("%d", &v) == 1)
        a[top++] = v;
    sort(a, a + top);
    for (int i = 0; i < top; i += 3)
        if (i + 2 == top || a[i] != a[i+2]) {
            printf("%d\n", a[i]);
            break;
        }
    return 0;
}
