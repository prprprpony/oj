#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5050;
int d[N];
int main()
{
    int k, q;
    cin >> k >> q;
    for (int i = 0; i < k; ++i)
        cin >> d[i];
    while (q--) {
        ll n, x, m;
        cin >> n >> x >> m;
        x %= m;
        --n;
        ll y = x, s = 0, ans = 0;
        for (int i = 0; i < k; ++i) {
            int t = d[i] % m;
            y += (i < n % k) * t;
            s += t;
            if (!t) {
                ans += n / k + (i < n % k);
            }
        }
        y += n / k * s;
        ans += y / m - x / m;
        cout << n - ans << '\n';
    }
}
