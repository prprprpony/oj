#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+87, M=1e9+7;
int c[N],la[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    n = unique(c,c+n) - c;
    int*a=c-1,dp=1;
    for (int i = 1; i <= n; ++i) {
        (la[a[i]] += dp) %= M;
        dp = la[a[i]];
    }
    cout << dp << endl;
}
