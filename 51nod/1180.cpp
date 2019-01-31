#include<bits/stdc++.h>
using namespace std;
const int N = 5e6+87;
int mu[N],lp[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,n;
    cin >> m >> n;
    if (n > m)
        swap(n,m);
    --m, --n;
    if (!m) {
        cout << "0\n";
        return 0;
    }
    if (!n) {
        cout << "1\n";
        return 0;
    }
    vector<int> p;
    mu[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (lp[i] == 0) {
            lp[i] =  i;
            p.push_back(i);
            mu[i] = -1;
        }
        for (int j : p) {
            if (i * j >= N)
                break;
            lp[i * j] = j;
            mu[i * j] = -mu[i];
            if (j == lp[i]) {
                mu[i * j] = 0;
                break;
            }
        }
    }
    long long ans = 2;
    for (long long i = 1; i <= n; ++i)
        ans += (m/i) * (n/i) * mu[i];
    cout << ans << endl;
}
