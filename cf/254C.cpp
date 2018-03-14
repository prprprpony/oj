#include<bits/stdc++.h>
using namespace std;
int cs[26], ct[26], cur[26];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s,t;
    cin >> s >> t;
    for (char c : t)
        ++ct[c - 'A'];
    for (char c : s)
        ++cs[c - 'A'];
    int ans = 0;
    for (int i = 0; i < 26; ++i)
        ans += max(cs[i] - ct[i], 0);
    for (char & c : s) {
        int i = c - 'A';
        ++cur[i];
        if (cs[i] > ct[i]) {
            int j;
            for (j = 0; j < 26 && cs[j] >= ct[j]; ++j);
            if (j < i || cs[i] - cur[i] + 1 == cs[i] - ct[i]) {
                c = 'A' + j;
                --cs[i];
                ++cs[j];
                --cur[i];
                ++cur[j];
            }
        }
    }
    cout << ans << '\n' << s << '\n';
}
