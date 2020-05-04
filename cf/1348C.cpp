#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    if (k == 1) {
        sort(s.begin(), s.end());
        cout << s << '\n';
        return;
    }
    int cnt[26] = {};
    for (char c : s)
        cnt[c - 'a']++;
    int w = k;
    string ans;
    int t = k;
    for (int i = 0; w; ++i) {
        int x = min(cnt[i], w);
        cnt[i] -= x;
        w -= x;
        ans = string(1, i + 'a');
        t = x;
    }
    if (t < k) {
        cout << ans << '\n';
        return;
    }
    //cerr << "QAQ\n";
    int sg = 0, si = -1;
    for (int i = 0; i < 26; ++i)
        if (cnt[i] > 0) {
            sg++;
            si = i;
        }
    if (sg == 1) {
        int q = cnt[si] / t, r = cnt[si] % k;
        for (int j = 0; j < q; ++j)
            ans += char('a' + si);
        if (r)
            ans += char('a' + si);
    } else {
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < cnt[i]; ++j)
                ans += char(i + 'a');
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}
