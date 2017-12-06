#include<bits/stdc++.h>
using namespace std;
const int N = 5066, inf=0x3f3f3f3f;
int fa[26], fb[26], la[26], lb[26], dp[N][N];
string a, b;
template<class T>
bool cmin(T & a,const T & b) {return a>b?a=b,1:0;}
void pre(string & s, int f[], int l[])
{
    memset(f,0x3f,26 * sizeof(int));
    memset(l,-1,26 * sizeof(int));
    for (int i = 0; i < s.size(); ++i) {
        l[s[i] -= 'A'] = i;
        if (f[s[i]] == inf)
            f[s[i]] = i;
    }
}
void solve()
{
    cin >> a >> b;
    int n = a.size(), m = b.size();
    pre(a,fa,la);
    pre(b,fb,lb);
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j) {
            dp[i][j] = (i || j) * inf;
            if (i) {
                cmin(dp[i][j],
                    dp[i-1][j] + (i-1 == fa[a[i-1]] && j-1 < fb[a[i-1]] ? -(i + j) : 0) + (i-1 == la[a[i-1]] && j-1 >= lb[a[i-1]] ? i + j : 0)
                );
            }
            if (j) {
                cmin(dp[i][j],
                    dp[i][j-1] + (i-1 < fa[b[j-1]] && j-1 == fb[b[j-1]] ? -(i + j) : 0) + (i-1 >= la[b[j-1]] && j-1 == lb[b[j-1]] ? i + j : 0)
                );
            }
        }
    cout << dp[n][m] << '\n';
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}
