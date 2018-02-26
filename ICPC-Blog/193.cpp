#include<bits/stdc++.h>
using namespace std;
const int N = 305;
bool s[N][27];
char t[10000 + 987];
bitset<N> dp[N];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        for (int j = 0; j < m; ++j)
            s[i][isalpha(t[j]) ? t[j] - 'a' : 26] = 1;
    }
    dp[0].flip();
    while (q--) {
        cin >> t;
        int w = strlen(t);
        if (w > n) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < w; ++i)
            t[i] -= 'a';
        for (int j = 1; j <= w; ++j)
            for (int i = 1; i <= n; ++i)
                dp[j][i] = (s[i-1][t[j-1]] && dp[j-1][i-1]) || (s[i-1][26] && dp[j][i-1]);
        cout << (dp[w][n] ? "YES\n" : "NO\n");
    }
}
