#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 87, M = 1010101333;
int gcd(int a,int b) {return b?gcd(b,a%b):a;}
int a[N],mu[N],cnt[N],C[N][8];
void pre()
{
    C[0][0] = 1;
    for (int i = 1; i < N; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= 7; ++j)
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % M;
    }
    vector<int> p;
    bitset<N> sev;
    mu[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!sev[i]) {
            mu[i] = -1;
            p.push_back(i);
        }
        for (int j : p) {
            if (i * 1LL * j >= N)
                break;
            sev[i * j] = 1;
            if (i % j == 0) {
                mu[i * j] = 0;
                break;
            }
            mu[i * j] = -mu[i];
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    pre();
    int n,g=0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        g=gcd(g,a[i]);
        for (int j = 1; j * j <= a[i]; ++j)
            if (a[i] % j == 0) {
                ++cnt[j];
                if (j * j != a[i])
                    ++cnt[a[i]/j];
            }
    }
    if (g > 1) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 1; i <= 7; ++i) {
        long long w = 0;
        for (int j = 1; j < N; ++j)
            w += mu[j] * C[cnt[j]][i];
        if (w % M) {
            cout << i << '\n';
            return 0;
        }
    }
}
