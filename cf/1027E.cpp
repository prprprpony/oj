#include<bits/stdc++.h>
using namespace std;
const int M = 998244353, N = 566;
void add(int & a,int b)
{
    a += b;
    a %= M;
}
int dp[2][N][N], s[N];
int main()
{
    int n,k;
    cin >> n >> k;
    dp[1][1][1] = 2;
    for (int i = 1; i+1 <= n; ++i) {
        int b = i & 1;
        int c = b ^ 1;
        memset(dp[c],0,sizeof dp[c]);
        for (int j = 1; j <= i; ++j) {
            for (int k = j; k <= i; ++k) {
                add( dp[c][j+1][max(k,j+1)], dp[b][j][k] );
                add( dp[c][1][k] , dp[b][j][k] );
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            add(s[i], dp[n&1][j][i]);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i * j < k)
                add(ans, s[i] * 1LL * s[j] % M);
        }
    }
    cout << (M+1LL)/2 * ans % M << endl;
}
