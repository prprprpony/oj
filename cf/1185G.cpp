#include<bits/stdc++.h>
using namespace std;
void gao()
{
    int mx = 0;
    for (int a=0;a<=50;++a)
        for (int b=0;a+b<=50;++b) {
            int c=50-a-b;
            mx = max(mx, (a + 1) * (b + 1) * (c + 1));
        }
    cout << mx << endl;
    exit(0);
}
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 51, C = 2501, M = 1e9+7, S = 5508;
int n,T,t[N],g[N],ct[3];
typedef array<int,3> a3;
int encode(a3 a)
{
    int r = 0;
    for (int i = 2; i >= 0; --i)
        r = r * (ct[i] + 1) + a[i];
    return r;
}
a3 decode(int p)
{
    a3 a;
    for (int i = 0; i < 3; ++i) {
        a[i] = p % (ct[i] + 1);
        p /= (ct[i] + 1);
    }
    return a;
}
int dp[C][S]; // s,a,b,c: number of set with sum s and a 0 b 1 c 2
int f[N][N][N][3]; // f(a,b,c,x) number of good sequence with a 0, b 1, c 2, that ends with x
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> T;
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> g[i];
        ct[--g[i]]++;
    }
    dp[0][0] = 1;
    a3 cur = {0,0,0};
    for (int i = 0; i < n; ++i) {
        for (int s = T-t[i]; s >= 0; --s)
            for (int a = 0; a <= cur[0]; ++a)
                for (int b = 0; b <= cur[1]; ++b)
                    for (int c = 0; c <= cur[2]; ++c) {
                        a3 p = {a,b,c};
                        int & now = dp[s][encode(p)];
                        p[g[i]]++;
                        int & nxt = dp[s+t[i]][encode(p)];
                        (nxt += now) %= M;
                    }
        cur[g[i]]++;
    }
    f[1][0][0][0] = f[0][1][0][1] = f[0][0][1][2] = 1;
    for (int k = 1; k < n; ++k)
        for (int a = 0; a <= k; ++a)
            for (int b = 0; a + b <= k; ++b) {
                int c = k - a - b;
                int & d0 = f[a+1][b][c][0];
                d0 = (d0 + (f[a][b][c][1] + f[a][b][c][2]) * (a+1ll)) % M;
                int & d1 = f[a][b+1][c][1];
                d1 = (d1 + (f[a][b][c][0] + f[a][b][c][2]) * (b+1ll)) % M;
                int & d2 = f[a][b][c+1][2];
                d2 = (d2 + (f[a][b][c][0] + f[a][b][c][1]) * (c+1ll)) % M;
            }
    ll ans = 0;
    for (int a = 0; a <= ct[0]; ++a)
        for (int b = 0; b <= ct[1]; ++b)
            for (int c = 0; c <= ct[2]; ++c)
                ans += dp[T][encode({a,b,c})] * (0ll+f[a][b][c][0]+f[a][b][c][1]+f[a][b][c][2]) % M;
    cout << ans % M << endl;
}
