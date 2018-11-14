#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+87, M = 1e9+7;
ll f[N],fi[N];
void pre()
{
    f[0]=f[1]=fi[0]=fi[1]=1;
    for (int i = 2; i < N; ++i)
        f[i] = i * f[i-1] % M;
    for (int i = 2; i < N; ++i)
        fi[i] = (M-M/i)*fi[M%i]%M;
    for (int i = 2; i < N; ++i)
        fi[i] = fi[i] * fi[i-1] % M;
}
ll c(int n,int k) {return f[n]*fi[k]%M*fi[n-k]%M;}
ll qpow(ll a,ll b)
{
    ll r=1;
    for (;b;b>>=1,a=a*a%M)
        if (b&1)
            r=r*a%M;
    return r;
}
ll s(int n,int k)
{
    ll r = 0;
    int p = (k&1)?-1:1;
    for (int j = 0; j <= k; ++j,p=-p)
        r += p * c(k,j) * qpow(j,n) % M;
    r = ((r % M * fi[k] % M) + M) % M;
    return r;
}
int n,k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    pre();
    cin >> n >> k;
    ll C = (s(n,k) + (n-1) * s(n-1,k)) % M, a = 0;
    for (int i = 0, w; i < n; ++i) {
        cin >> w;
        a += w;
    }
    cout << a%M*C%M << '\n';
}
