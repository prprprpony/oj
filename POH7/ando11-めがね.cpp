#include <iostream>
using namespace std;
int main(void)
{
    int n, m;
    bool ok;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    cin >> m;
    int b[m][m];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cin >> b[i][j];
    ok = false;
    for (int i = 0; i <= n - m && !ok; i++)
        for (int j = 0; j <= n - m && !ok; j++) {
            ok = true;
            for (int dy = 0; dy < m && ok; dy++)
                for (int dx = 0; dx < m && ok; dx++)
                    if (a[i + dy][j + dx] != b[dy][dx])
                        ok = false;
            if (ok)
                cout << i << ' ' << j << '\n';
        }
    return 0;
}
