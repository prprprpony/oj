#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        ll n,k,s=1,w=1;
        cin >> n >> k;
        while (n >= 1 && s <= k) {
            n -= 1;
            k -= s;
            s *= 4;
            w *= 2;
        }
        if (n == 0 && k > 0) {
            cout << "NO\n";
            continue;
        }
        if (k >= 2*w-1)
            cout << "YES " << n - 1 << '\n';
        else {
            s-=2*w-1;
            for (ll i=n;i>0&&k>0;--i,s*=4)
                k -= min(s,k);
            if (k == 0)
                cout << "YES " << n << '\n';
            else
                cout << "NO\n";
        }
    }
}
