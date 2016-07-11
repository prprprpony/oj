#include <bits/stdc++.h>
using namespace std;
int f[64];
int main()
{
    ios_base::sync_with_stdio(false);
    f[1] = 1;
    int n;
    for (n = 2; (f[n] = f[n-2] + f[n-1]) <= 1e6; ++n);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        int i, j, k;
        for (i = lower_bound(f, f + n, a) - f, j = upper_bound(f, f + n, b) - f, k = j - i; i < j; ++i)
            cout << f[i] << '\n';
        cout << k << '\n';
        if (t)
            cout << "------\n";
    }
}
