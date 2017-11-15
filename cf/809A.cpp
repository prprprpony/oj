#include<bits/stdc++.h>
using namespace std;
const int N = 3e5, M = 1e9 + 7;
int x[N];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    sort(x,x+n);
    int s = x[0], p = 2;
    long long ans = 0;
    for (int j = 1; j < n; ++j) {
        ans += x[j] * 1LL * (p - 1) % M - s;
        s = (2 * s % M + x[j]) % M;
        p = 2 * p % M;
    }
    cout << (ans % M + M) % M << '\n';
}
