#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin >> a >> b;
    int m = a.size(), n = b.size();
    a = "x" + a; b = "x" + b;
    vector<array<int,2>> f(m+1);
    for (int i = 0; i < m; ++i) {
        f[i][0] = f[i][1] = 0;
        auto s = a.substr(1,i) + 'A';
       // cerr << s << endl;
        for (int j = 1; j <= i+1; ++j) {
            //cerr << "suba " <<a.substr(0,j) << " subs " << s.substr(i+1-j) << endl;
            if (a.substr(1,j) == s.substr(i+1-j))
                f[i][0] = j;
        }
        s = a.substr(1,i) + 'B';
        //cerr << s << endl;
        for (int j = 1; j <= i+1; ++j)
            if (a.substr(1,j) == s.substr(i+1-j))
                f[i][1] = j;
        //cerr << i << ' ' << f[i][0] << ' ' << f[i][1] << endl;
    } 
    // dp[i][j]: suffix of b[1:i] after deletion matchs a[1:j]
    vector<vector<int>> dp(n+1,vector<int>(m,n));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
            int k = f[j][b[i+1]=='B'];
            if (k < m)
                dp[i+1][k] = min(dp[i+1][k], dp[i][j]);
        }
    }
    cout << *min_element(begin(dp[n]),end(dp[n])) << endl;
}
