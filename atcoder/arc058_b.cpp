#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 98, M = 1e9 + 7;
ll f[N], fi[N];
void pre()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = i * f[i-1] % M;
    fi[0] = fi[1] = 1;
    for (int i = 2; i < N; ++i)
        fi[i] = (M-M/i) * fi[M%i] % M;
    for (int i = 2; i < N; ++i)
        fi[i] = fi[i] * fi[i-1] % M;
}
ll C(int n,int k)
{
    return f[n] * fi[k] % M * fi[n-k] % M;
}
int main()
{
    pre();
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    a = n - a;
    b--;
    --n,--m;
    ll ans = C(n+m,m);
    for (int i = a; i <= n; ++i) 
        ans -= C(b+i,i) * C(m-b-1 + n-i, n-i) % M;
    cout << (ans % M + M) % M << endl;
}
