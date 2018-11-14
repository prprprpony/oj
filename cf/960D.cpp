#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 62;
ll b[N],m[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; ++i)
        m[i] = 1LL << i;
    int Q;
    cin >> Q;
    while (Q--) {
        int t;
        ll x,k;
        cin >> t >> x;
        int i = __lg(x);
        if (t == 1 || t == 2) {
            cin >> k;
            k = (-k%m[i]+m[i])%m[i];
            for (int j = i; j < N && (j == i || t == 2); ++j, k <<= 1)
                b[j] = (b[j] + k) % m[j];
        } else {
            for (ll v = (x - b[i] + m[i]) % m[i] + m[i]; v >= 1; v >>=1, --i)
                cout << (v + b[i]) % m[i] + m[i]<< " \n"[v == 1];
        }
    }
}
