#include<bits/stdc++.h>
using namespace std;
#define SZ(a) ((int)(a).size())
#define ALL(a) begin(a),end(a)
void cmin(int & a,int b) {if (b < a) a = b;}
const int N = 78, inf = 0x3f3f3f3f;
int dp[N][N][N][2];
vector<int> a[3];
int cnt(int i,int j,int k,int x)
{
    return max(int(lower_bound(ALL(a[0]),x) - begin(a[0])) - i, 0)
    + max(int(lower_bound(ALL(a[1]),x) - begin(a[1])) - j, 0)
    + max(int(lower_bound(ALL(a[2]),x) - begin(a[2])) - k, 0);
}
int main()
{
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        auto & x = s[i];
        x = x == 'V' ? 1 : x == 'K' ? 2 : 0;
        a[x].push_back(i);
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0][0][0][0] = 0;
    for (int m = 0; m < n; ++m)
        for (int i = 0; i <= min(m,SZ(a[0])); ++i)
            for (int j = 0; j <= min(m-i,SZ(a[1])); ++j) {
                int k = m - i - j;
                for (int b = 0; b <= 1; ++b) {
                    int od = dp[i][j][k][b];
                    if (od == inf)
                        continue;
                    if (i != SZ(a[0]))
                        cmin(dp[i+1][j][k][0], od + cnt(i,j,k,a[0][i]));
                    if (j != SZ(a[1]))
                        cmin(dp[i][j+1][k][1], od + cnt(i,j,k,a[1][j]));
                    if (!b && k != SZ(a[2]))
                        cmin(dp[i][j][k+1][0], od + cnt(i,j,k,a[2][k]));
                }
            }
    cout << min(dp[SZ(a[0])][SZ(a[1])][SZ(a[2])][0],dp[SZ(a[0])][SZ(a[1])][SZ(a[2])][1]) << endl;
}
