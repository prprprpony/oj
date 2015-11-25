#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 50000;
int love[maxn];
int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n > 0) {
        for (int i = 0; i < n; i++)
            scanf("%d", love + i);
        sort(love, love + n);
        int d = love[1] - love[0];
        bool yes = true;
        for (int i = 2; i < n; i++)
            if (love[i] - love[i - 1] != d) {
                yes = false;
                break;
            }
        printf(yes ? "Yes\n" : "No\n");
    }
    return 0;
}
