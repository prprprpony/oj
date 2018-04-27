#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87;
int a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int w,l,ans=1e9;
    cin >> w >>l;
    for (int i = 1; i < w; ++i) {
        cin >> a[i];
        a[i] += a[i-1];
        if (i >= l)
            ans = min(ans, a[i] - a[i-l]);
    }
    cout << ans << endl;
}
