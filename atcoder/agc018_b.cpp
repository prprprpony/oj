#include<bits/stdc++.h>
using namespace std;
const int N = 305;
int n,m,a[N][N],idx[N],dead[N],cnt[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
        cnt[a[i][0]]++;
    }
    int ans = INT_MAX;
    for (int w = m; w >= 1; --w) {
        int mx = 0, mxi = -1;;
        for (int j = 1; j <= m; ++j)
            if (cnt[j] > mx)
                mx = cnt[j], mxi = j;
        ans = min(ans, mx);
        dead[mxi] = 1;
        cnt[mxi] = 0;
        if (w > 1) {
            for (int i = 0; i < n; ++i)
                if (a[i][idx[i]] == mxi) {
                    while (dead[a[i][idx[i]]])
                        ++idx[i];
                    ++cnt[a[i][idx[i]]];
                }
        }
    }
    cout << ans << endl;
}
