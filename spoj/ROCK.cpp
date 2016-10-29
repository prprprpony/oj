#include <iostream>
#include <cstring>
#define MAXN 228
using namespace std;

int d[MAXN][MAXN];
int p[MAXN];

int dp(int l, int r) {
    int& now = d[l][r];
    if (now != -1)
        return now;
    int s = p[r] - p[l-1];
    if (s == 0)
        return now = 0;
    int len = r - l + 1;
    if (s * 2 > len)
        return now = len;
    for (int m = l; m < r; m++)
        now = max(now, dp(l, m) + dp(m + 1, r));
    return now;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 1; i <= n; i++)
            p[i] = p[i-1] + s[i-1] - '0';
        memset(d, -1, sizeof(d));
        cout << dp(1, n) << '\n';
    }

    return 0;
}
