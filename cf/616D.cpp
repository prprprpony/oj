#include <bits/stdc++.h>
using namespace std;
int a[(int)5e5 + 426];
int main()
{
    int n, k, len = 0, al, ar;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    map<int, int> num;
    for (int l = 1, r = 1; r <= n; r++) {
        if (!num.count(a[r]))
            num[a[r]] = 1;
        else
            num[a[r]]++;
        while (num.size() > k && l <= r) {
            if (--num[a[l]] == 0)
                num.erase(a[l]);
            l++;
        }
        if (r - l + 1 > len) {
            len = r - l + 1;
            al = l;
            ar = r;
        }
    }
    printf("%d %d\n", al, ar);
    return 0;
}
