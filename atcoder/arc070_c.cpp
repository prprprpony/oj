#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll base = 0, ld = 0, rd = 0, wo, w, x;
    cin >> wo >> x;
    wo = x - wo;
    multiset<ll> ls{x}, rs{x};
    for (int i = 0; i < n - 1; ++i) {
        cin >> w >> x;
        w = x - w;
        ld -= wo;
        rd += w;
        wo = w;
        ll bl = *prev(end(ls)) + ld, br = *begin(rs) + rd;
        if (bl <= x && x <= br) {
            ls.insert(x - ld);
            rs.insert(x - rd);
        } else if (x < bl) {
            base += bl - x;
            ls.insert(x - ld);
            ls.insert(x - ld);
            ls.erase(prev(end(ls)));
            rs.insert(bl - rd);
        } else {
            base += x - br;
            rs.insert(x - rd);
            rs.insert(x - rd);
            rs.erase(begin(rs));
            ls.insert(br - ld);
        }
    }
    cout << base << '\n';
}
