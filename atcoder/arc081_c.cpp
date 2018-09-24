#include<bits/stdc++.h>
using namespace std;
const int N = 212345;
int dp[N][26];
char s[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int n = strlen(s);
    for (int i = n-1; i >= 0; --i) {
        copy_n(dp[i+1],26,dp[i]);
        dp[i][s[i]-'a'] = max(dp[i][s[i]-'a'], *min_element(dp[i],dp[i]+26)+1);
    }
    int c = min_element(dp[0],dp[0]+26)-dp[0], i = 0;
    int w = dp[0][c];
    while (w--) {
        cout << char(c+'a');
        while (s[i] != c+'a')
            ++i;
        ++i;
        c = min_element(dp[i],dp[i]+26)-dp[i];
    }
    cout << char(c+'a') << '\n';
}
