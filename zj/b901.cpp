#include<cstdio>
using namespace std;
typedef long long ll;
const ll x[] = {3, 7, 9};
ll c[3];
ll f(ll n, ll k)
{
    return n == 0 ? 0 : n / k + f(n / k, k);
}
void g(ll n)
{
    if (!n)
        return;
    for (ll m = n; m; m /= 5) {
        ll p = m / 10, q = m % 10;
        for (int i = 0; i < 3; ++i)
            c[i] += p + (q >= x[i]);
    }
    g(n / 2);
}
ll qpow(ll a, ll b)
{
    ll ret = 1;
    for (; b; b >>= 1, a = a * a % 10)
        if (b & 1)
            ret = ret * a % 10;
    return ret;
}
ll solve(ll n)
{
    ll a = f(n, 2), b = f(n, 5);
    c[0] = c[1] = c[2] = 0;
    g(n);
    ll ans = qpow(2, a - b);
    for (int i = 0; i < 3; ++i)
        ans = ans * qpow(x[i], c[i]) % 10;
    return ans;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        ll n;
        scanf("%lld", &n);
        printf("%lld\n", solve(n));
    }
}
