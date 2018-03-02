#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int p, q;
        cin >> p >> q;
        if (q < 0) {
            p *= -1;
            q *= -1;
        }
        int ans = p < 0 ? -((-p+q-1)/q) : p/q;
        if (p%q == 0)
            --ans;
        cout << ans << '\n';
    }
}
