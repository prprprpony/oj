#include <bits/stdc++.h>
#define MAXN 1024
#define J first
#define B second
using namespace std;
typedef pair<int, int> pii;
pii s[MAXN];
int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n) {
        for (int i = 0; i < n; i++)
            scanf("%d%d", &s[i].B, &s[i].J);
        sort(s, s + n, greater<pii>());
        int ans = 0;
        int t = 0;
        for (int i = 0; i < n; i++) {
            t += s[i].B;
            ans = max(ans, t + s[i].J);
        }
        static int kase = 0;
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
