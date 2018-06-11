#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87;
const int D = __lg(N) + 1;
int x[N],pa[N][D];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    int l,q;
    cin >> l >> q;
    for (int i = 1, j = 0; i < n; ++i) {
        while (x[i] - x[j] > l)
            ++j;
        pa[i][0] = j;
        for (int k = 1; k < D; ++k)
            pa[i][k] = pa[pa[i][k-1]][k-1];
    }
    for (int i = 0; i < q; ++i) {
        int a,b;
        cin >> a >> b;
        if (b < a)
            swap(a,b);
        --a,--b;
        int ans = 0;
        for (int j = D-1; j >= 0; --j)
            if (pa[b][j] > a) {
                ans |= 1<<j;
                b = pa[b][j];
            }
        if (b > a)
            ++ans;
        cout << ans << '\n';
    }
}
