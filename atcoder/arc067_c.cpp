#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9 + 7, N = 1087;
ll dp[N],f[N],fi[N];
int main()
{
    f[0] = f[1] = fi[0] = fi[1] = 1;
    for (int i = 2; i < N; ++i) 
        f[i] = i * f[i-1] % M;
    for (int i = 2; i < N; ++i) 
        fi[i] = (M-M/i) * fi[M%i] % M;
    for (int i = 2; i < N; ++i)
        fi[i] = fi[i] *  fi[i-1] % M;

    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,a,b,c,d;    
    cin >> n >> a >> b >> c >> d;
    dp[0] = 1;
    for (ll i = a; i <= b; ++i)
        for (ll j = n; j >= i * c; --j) {
            ll t = fi[i];
            for (ll k = 1; k <= min(d,j/i); ++k) {
                if (k >= c) {
                    (dp[j] += t * f[j] % M * fi[j - k * i] % M * fi[k] % M *  dp[j - k * i] % M) %= M;
                }
                (t *= fi[i]) %= M;
            }
        }
    cout << dp[n] << endl;
}
