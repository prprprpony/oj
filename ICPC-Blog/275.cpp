#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        ll ans = 0;
        int w = 0;
        bool h = false;
        for (char c : s) {
            if (c == '9' && h)
                ++w;
            else
                w = 1;
            ans += w;
            h = h || c != '0';
        }
        cout << ans << '\n';
    }
}
