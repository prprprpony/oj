#include <bits/stdc++.h>
#define MAXR 11
#define MAXC 110
using namespace std;
int R, C;
int m[MAXR][MAXC];
int dp[MAXC][MAXR];
int p[MAXC][MAXR];
int pre[3];

int main()
{
    while (cin >> R >> C) {
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                cin >> m[r][c];
        for (int r = 0; r < R; r++)
            dp[C-1][r] = m[r][C-1];

        for (int c = C - 2; c >= 0; c--) {
            for (int r = 0; r < R; r++) {
                for (int i = -1; i <= 1; i++)
                    pre[i + 1] = (r + i + R) % R;
                sort(pre, pre + 3);

                dp[c][r] = dp[c+1][pre[0]];
                p[c][r] = pre[0];
                for (int i = 1; i < 3; i++) {
                    if (dp[c+1][pre[i]] < dp[c][r]) {
                        dp[c][r] = dp[c+1][pre[i]];
                        p[c][r] = pre[i];
                    }
                }
                dp[c][r] += m[r][c];
            }
        }
        
        int ar = 0, w = dp[0][0];
        for (int r = 1; r < R; r++)
            if (dp[0][r] < w) {
                w = dp[0][r];
                ar = r;
            }

        for (int c = 0; c < C; ar = p[c][ar], c++)
            cout << ar + 1 << (c != C - 1 ? ' ' : '\n');

        cout << w << '\n';
    }

    return 0;
}
