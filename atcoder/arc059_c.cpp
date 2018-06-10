#include<bits/stdc++.h>
using namespace std;
const int N = 405, M = 1e9 + 7;
typedef long long ll;
ll pw[N][N],dp[N][N];
int A[N],B[N];
int main()
{
    for (int j = 1; j < N; ++j) {
        pw[j][0] = 1;
        for (int i = 1; i < N; ++i)
            pw[j][i] = pw[j][i-1] * j % M;
    }
    for (int j = 1; j < N; ++j)
        for (int i = 0; i < N; ++i)
            (pw[j][i] += pw[j-1][i]) %= M;
    int n,c;
    cin >> n >> c;
    for (int i = 1; i <= n; ++i)
        cin >> A[i];
    for (int i = 1; i <= n; ++i)
        cin >> B[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        int a = A[i], b = B[i];
        for (int j = 0; j <= c; ++j) {
            for (int k = 0; k <= j; ++k)
                dp[i][j] += (pw[b][k] - pw[a-1][k]) * dp[i-1][j-k] % M;
            dp[i][j] %= M;
        }
    }
    cout << (dp[n][c]%M+M)%M << endl;
}
