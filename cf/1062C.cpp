#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87, M = 1e9 + 7;
typedef long long ll;
char in[N];
ll f[N],s[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q >> (in+1);
    for (int i = 1; i <= n; ++i) {
        s[i] = in[i] - '0' + s[i-1];
        f[i] = (f[i-1] * 2 + 1) % M;
    }
    while (q--) {
        int l,r;
        cin >> l >> r;
        --l;
        int i = s[r] - s[l];
        int o = r - l - i;
        cout << f[i] * (f[o] + 1) % M << '\n';
    }
}
