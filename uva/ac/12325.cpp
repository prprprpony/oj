#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long t, n, s[2], v[2], i, j, k, ans, c, base;
    cin >> t;
    for (int cases = 1; cases <= t; cases++){
        cin >> n;
        ans = 0;
        base = 0;
        for (i = 0; i < 2; i++)
            cin >> s[i] >> v[i];
        if (s[0] == s[1]) {
            ans = n / s[0] * max(v[0], v[1]);
            n = -1;
        } else if (v[0] == v[1]) {
            ans = n / min(s[0], s[1]) * v[0];
            n = -1;
        } else if (n > s[0] * s[1]) {
            c = max(s[0] * v[1], s[1] * v[0]);
            base = (n / (s[0] * s[1])) * c;
            n %= (s[0] * s[1]);
        }
        k = s[1] > s[0] ? 1 : 0;
        for (j = 0; n >= 0; j++, n -= s[k])
            ans = max(ans, j * v[k] + n / s[1-k] * v[1-k]);
        cout << "Case #" << cases << ": " << base + ans << '\n';
    }
    return 0;
}
