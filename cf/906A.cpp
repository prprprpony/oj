#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int full = (1 << 26) - 1;
    int n;
    cin >> n;
    int mask = full, cnt = 0;
    --n;
    while (n--) {
        char c;
        string s;
        cin >> c >> s;
        int t = 0;
        for (char x : s)
            t |= 1 << (x - 'a');
        if (c == '!') {
            if ((mask & (mask - 1)) == 0)
                ++cnt;
            mask &= t;
        } else if (c == '.') {
            mask &= full ^ t;
        } else {
            if ((mask & (mask - 1)) == 0)
                ++cnt;
            mask &= full ^ t;
        }
    }
    cout << cnt << '\n';
}
