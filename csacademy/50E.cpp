#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87;
int a[N], b[N], n;
int cl(int o)
{
    copy_n(a+1,n,b+1);
    int x = 0;
    for (int i = 1; i <= n; ++i) 
        if (b[i] == n/2) {
            int j = (o ? n : 1);
            if (i != j) {
                swap(b[i], b[j]);
                ++x;
            }
            break;
        }
    for (int i = 1; i <= n; ++i)
        if (b[i] == n/2 +1) {
            int j = (o ? 1 : n);
            if (i != j) {
                swap(b[i], b[j]);
                ++x;
            }
            break;
        }
    for (int i = 3^o, j = 2^o; i <= n; i += 2) {
        if (b[i] <= n/2)
            continue;
        while (j <= n && b[j] > n/2)
            j += 2;
        assert(j <= n);
        swap(b[i], b[j]);
        ++x;
    }
    return x;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cout << min(cl(0), cl(1)) << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
}
