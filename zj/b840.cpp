#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 24;
int mat[maxn][maxn];
int sum[maxn][maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int r = 1; r <= N; ++r)
        for (int c = 1; c <= N; ++c) {
            cin >> mat[r][c];
            sum[r][c] = sum[r-1][c] + mat[r][c];
        }
    int ans = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = i; j <= N; ++j)
            for (int c = 1, s = 0; c <= N; ++c) {
                s += sum[j][c] - sum[i-1][c];
                ans = max(ans, s);
                if (s < 0)
                    s = 0;
            }
    cout << ans << '\n';
}
