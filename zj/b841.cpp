#include <iostream>
using namespace std;
const int maxn = 7;
int mat[maxn][maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    int R, C;
    cin >> R >> C;
    int ans = 0;
    for (int r = 1; r <= R; ++r)
        for (int c = 1; c <= C; ++c) {
            cin >> mat[r][c];
            if (mat[r][c] == mat[r-1][c]) {
                mat[r][c] = mat[r-1][c] = -1;
                ++ans;
            } else if (mat[r][c] == mat[r][c-1]) {
                mat[r][c] = mat[r][c-1] = -1;
                ++ans;
            }
        }
    cout << ans << '\n';
}
