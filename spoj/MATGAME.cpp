#include <bits/stdc++.h>
#define MAXN 55
using namespace std;
int mat[MAXN][MAXN];
int sg[MAXN][MAXN];
int main()
{
    int t;
    int n, m;
    int ans;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int r = 0; r < n; r++)
            for (int c = 0; c < m; c++)
                cin >> mat[r][c];
        ans = 0;
        for (int r = 0; r < n; r++) {
            sg[r][m-1] = mat[r][m-1];
            for (int c = m - 2; c >= 0; c--) {
                if (mat[r][c] == 0) {
                    sg[r][c] = sg[r][c+1];
                } else {
                    if (mat[r][c] <= sg[r][c+1])
                        sg[r][c] = mat[r][c] - 1;
                    else
                        sg[r][c] = mat[r][c];
                }
            }
            ans ^= sg[r][0];
        }
        cout << (ans ? "FIRST" : "SECOND") << '\n';
    }
}
