#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5056, M = 1e9 + 7;
ll n,a[N],pr[N],ans[N*2],h[N*2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    pr[0] = 1;
    for (int i = 1; i <= n - 1; ++i) {
         cin >> a[i];
         pr[i] = a[i] * pr[i-1] % M;
         for (int j = 1; j <= i; ++j)
             ans[j] += pr[i];
    }
    for (int i = n-1; i >= 1; --i) {
        for (int j = n+n-2; j >= 2; --j)
            h[j] = (a[i+1] * a[i+1] % M) * h[j-2] % M;
        ll p = 1;
        for (int j = 2; i+j-1 <= n; ++j) {
            (h[j] += p * (j > 2 ? 2 : 1)) %= M;
            p = (p * a[i+j-1]) % M;
        }
        /*
        cerr << i <<"th loop\n";
        for (int j = 0; j <= 2*n; ++j)
            cerr << "h["<<j<<"]="<<h[j]<<endl;
            */
        for (int j = 2; j <= 2*n-2; ++j)
            ans[j] += a[i] * (a[i] - 1) / 2 % M * pr[i-1] % M * h[j] % M;
    }
    for (int k = 1; k <= n+n-2; ++k)
        cout << ans[k] % M << " \n"[k == n+n-2];
}
