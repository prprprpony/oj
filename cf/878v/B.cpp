#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 1e5 + 87;
pii a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,k,m,w=0,c=0;
    cin >> n >> k >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (!w || a[w-1].F != x)
            a[w++] = {x,1};
        else
            a[w-1].S++;
        c += a[w-1].S / k;
        if (!(a[w-1].S %= k))
            --w;
    }
    c *= m;
    if (m >= 2) {
        int l = 0, r = w-1;
        for (;r - l + 1 >= 2; ++l,--r) {
            if (a[l].F != a[r].F)
                break;
            ll s = a[l].S + a[r].S;
            c += s / k * (m - 1);
            if (s % k)
                break;
        }
        if (r - l + 1 == 1) {
            ll s = a[l].S * m;
            c += s / k;
            if (s % k == 0) {
                while (--l >= 0 && ++r < w) {
                   if (a[l].F != a[r].F)
                       break;
                   s = a[l].S + a[r].S;
                   c += s / k;
                   if (s % k)
                       break;
                }
            }
        }
    }
    cout << n * m - c * k << endl;
}
