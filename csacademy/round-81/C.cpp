#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const ll M = 1e9 + 7;
const int N = 55;
ll f[N], fi[N], pw[N];
int c[10];
void pre()
{
    pw[0] = f[0] = fi[0] = fi[1] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = f[i-1] * i % M;
    for (int i = 2; i < N; ++i)
        fi[i] = (M-M/i) * fi[M%i] % M;
    for (int i = 2; i < N; ++i)
        fi[i] = fi[i] * fi[i-1] % M;
    for (int i = 1; i < N; ++i)
        pw[i] = pw[i-1] * 10 % M;
}
int main()
{
    pre();
    int n;
    cin >> n;
    if (n == 1) {
        int x;
        cin >> x;
        cout << x << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++c[x];
    } 
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < 10; ++j) {
            ll t = f[n-1], w = f[n-2];
            for (int k = 0; k < 10; ++k) {
                t = t * fi[c[k] - (k==j)] % M;
                w = w * fi[c[k] - (k == j) - (k == 0)] % M;
            }
            if (i != n-1)
                t = t + M - w;
            ans += t * pw[i] % M * j;
        }
    }
    cout << ans % M << endl;
}
