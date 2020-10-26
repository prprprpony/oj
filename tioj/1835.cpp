#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
string a, b;
int n, m;
int dp[N][N];
vector<tuple<char, int, int>> pos[N];
string cur;
bool dfs(int len, int i, int j)
{
    if (len == 0)
        return 1;
    for (auto t : pos[len]) {
        char c;
        int x, y;
        tie(c, x, y) = t;
        if (x > i && y > j) {
            cur += c;
            if (dfs(len - 1, x, y))
                return 1;
            cur.pop_back();
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        n = a.size(), m = b.size();
        memset(dp, 0, sizeof dp);
        for (int i = n - 1; i >= 0; --i)
            for (int j = m - 1; j >= 0; --j) {
                if (a[i] == b[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                if (dp[i][j + 1] >= dp[i][j])
                    dp[i][j] = dp[i][j + 1];
                if (dp[i + 1][j] >= dp[i][j])
                    dp[i][j] = dp[i + 1][j];
            }
        for (int i = dp[0][0]; i >= 1; --i)
            pos[i].clear();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (a[i] == b[j])
                    pos[dp[i][j]].emplace_back(a[i], i, j);
        for (int i = dp[0][0]; i >= 1; --i)
            sort(pos[i].begin(), pos[i].end());
        if (dp[0][0]) {
            cur.clear();
            dfs(dp[0][0], -1, -1);
            cout << cur << '\n';
        } else {
            cout << "妹萌えこそ正義なのさ！\n";
        }
    }
}

