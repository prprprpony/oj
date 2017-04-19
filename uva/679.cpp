#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int D,I;
        cin >> D >> I;
        --D, --I;
        int ans = 1<<D;
        for (int i = D-1; i >= 0; --i,I>>=1)
            ans |= (I&1)<<i;
        cout << ans << '\n';
    }
}
