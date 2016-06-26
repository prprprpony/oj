#include <bits/stdc++.h>
#define MAXN (int)1e4 + 42
using namespace std;
int w[MAXN];
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        double avg = 0.0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> w[i];
            avg += w[i];
        }
        avg /= n;
        double ans = 0.0;
        for (int i = 0; i < n; i++)
            ans += pow(avg - w[i], 2.0);
        ans = sqrt(ans/n);
        int q;
        cin >> q;
        printf("%.2f\n", ans);
        while (q--) {
            int a, b;
            cin >> a >> b;
            printf("%.2f\n", abs(a) * ans);
        }
        putchar('\n');
    }
    return 0;
}
