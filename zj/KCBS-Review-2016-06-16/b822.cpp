#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int maxi, mini;
    for (int i = 1; i <= n; ++i) {
        int v;
        scanf("%d", &v);
        if (v == 1)
            mini = i;
        if (v == n)
            maxi = i;
    }
    printf("%d\n", max(max(abs(maxi - 1), abs(maxi - n)), max(abs(mini - 1), abs(mini - n))));
}
