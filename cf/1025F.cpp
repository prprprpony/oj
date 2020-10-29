#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pt;
#define x first
#define y second
pt operator - (const pt & a, const pt & b) {return pt(a.x - b.x, a.y - b.y);}
ll operator ^ (const pt & a, const pt & b) {return a.x * b.y - b.x * a.y;}
int q(const pt & a) 
{
    if (a.x >= 0 && a.y >= 0) return 1;
    if (a.x < 0 && a.y >= 0) return 2;
    if (a.x < 0 && a.y < 0) return 3;
    return 4;
}
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pt> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].x >> a[i].y;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<pt> b;
        for (int j = 0; j < n; ++j)
            if (j != i)
                b.push_back(a[j] - a[i]);
        sort(begin(b), end(b), [&] (const pt & x, const pt & y) {return q(x) != q(y) ? q(x) < q(y) : (x ^ y) > 0;});
        int w = 0, r = 0;
        for (int j = 0; j < b.size(); ++j, --w) {
            while (((b[j] ^ b[r]) >= 0) && w < (int)b.size()) r = (r + 1) % b.size(), ++w;
            ll k1 = w - 1;
            ll k2 = (int)b.size() - 1 - k1;
            ans += (k1 * (k1 - 1) / 2) * (k2 * (k2 - 1) / 2);
        }
    }
    cout << ans / 2 << '\n';
}
