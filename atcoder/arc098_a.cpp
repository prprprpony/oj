#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 87;
int po[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    for (int i = n - 1; i >= 0; --i)
        po[i] = (s[i] == 'E') + po[i+1];
    int cu = 0;
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, cu + po[i+1]);
        cu += s[i] == 'W';
    }
    cout << ans << endl;
}
