#include <iostream>
#include <algorithm>
#define MAXN 101
using namespace std;
int d[MAXN][MAXN];
int main()
{
    int R, C;
    char ch;
    int ans = 0;
    cin >> R >> C;

    for (int c = 0; c <= C; c++)
        d[0][c] = 0;
    for (int r = 1; r <= R; r++)
        d[r][0] = 0;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> ch;
            d[r][c] = (ch == '0' ? min(min(d[r][c-1], d[r-1][c]), d[r-1][c-1]) + 1 : 0);
            ans = max(ans, d[r][c]);
        }
    }

    cout << ans * ans << endl;

    return 0;
}
