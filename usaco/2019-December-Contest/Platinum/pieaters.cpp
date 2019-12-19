#include<bits/stdc++.h>
using namespace std;
#ifndef PR3PONY
ifstream _fin("pieaters.in");
ofstream _fout("pieaters.out");
#define cin _fin
#define cout _fout
#endif
const int N = 305;
template<class T>
bool cmax(T & a, const T & b) {return a < b ? a = b, 1 : 0;}
int dp[N][N], f[N][N][N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int w, l, r;
        cin >> w >> l >> r;
        for (int j = l; j <= r; ++j)
            cmax(f[l][r][j], w);
    }
    for (int w = 1; w <= n; ++w) {
        for (int l = 1, r; (r = l + w - 1) <= n; ++l) {
            for (int i = l; i <= r; ++i) {
                cmax(f[l][r][i], max(f[l + 1][r][i], f[l][r - 1][i]));
                cmax(dp[l][r], dp[l][i - 1] + dp[i + 1][r] + f[l][r][i]);   
            }
        }
    }
    cout << dp[1][n] << endl;
}
