#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 87;
int n,k,a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    int w = 0;
    for (int i = 0; i <= n; ++i) {
        cin >> a[i];
        if (w < 0) {
            w = (w-1)/2;
        } else {
            w /= 2;
        }
        w += a[i];
    }
    if (w < 0)
        for (int i = 0; i <= n; ++i)
            a[i] *= -1;
    int fi=-1;
    long long t=0;
    w=0;
    for (int i = 0; i <= n || w; ++i) {
        w += a[i];
        int c = w/2;
        w %= 2;
        if (w < 0) {
            w = 1;
            --c;
        }
        if (w) {
            if (fi < 0)
                fi = i;
            int p = i - fi;
            if (p >= 31) {
                cout << "0\n";
                return 0;
            }
            t|=1<<p;
        }
        w=c;
    }
    int ans = 0;
    for (; fi >= 0 && t <= 2 * k; --fi, t <<= 1) {
        long long b = a[fi] - t;
        ans += b >= -k && (fi < n || (fi == n && b != 0));
    }
    cout << ans << '\n';
}
