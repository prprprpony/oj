#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int f[N];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = f[i-1] + ((i&1) ? 0 : f[i>>1]);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        assert(x < N);
        cout << i << ' ' << f[x] << '\n';
    }
}
