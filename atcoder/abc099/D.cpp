#include<bits/stdc++.h>
using namespace std;
const int C = 31, N = 521;
int d[C][C];
int g[3][C];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,c;
    cin >> n >> c;
    for (int i = 1; i <= c; ++i)
        for (int j = 1; j <= c; ++j)
            cin >> d[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            int a;
            cin >> a;
            ++g[(i+j)%3][a];
        }
    int w[3];
    int ans = 2e9;
    for (w[0] = 1; w[0] <= c; ++w[0])
        for (w[1] = 1; w[1] <= c; ++w[1]) if (w[1] != w[0])
            for (w[2] = 1; w[2] <= c; ++w[2]) if (w[2] != w[0] && w[2] != w[1]) {
                int s = 0;
                for (int x = 0; x < 3; ++x)
                    for (int i = 1; i <= c; ++i)
                        s += d[i][w[x]] * g[x][i];
                ans = min(ans, s);
            }
    cout << ans << endl;
}
