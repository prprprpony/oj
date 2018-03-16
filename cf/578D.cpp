#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 87;
int n,m;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s;
    ll ans = 1;
    for (int i = 1; i < n; ++i)
        ans += s[i] != s[i-1];
    ans *= m * n - n;
    for (int i = 0, j; i < n - 1; i = j - 1) {
        for (j = i + 2; j < n && s[j] == s[j-2]; ++j);
        if (s[i] == s[i+1])
            continue;
        ans -= (j - i) * (j - i - 1LL) / 2;
    }
    cout << ans << endl;
}
