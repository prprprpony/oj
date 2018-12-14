#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second
const ll N = 1e5 + 87, M = 1e9 + 7;
pll a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,x,y,ans = 0;
    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].F >> a[i].S;
        ans += (a[i].S - a[i].F) * y % M;
    }
    sort(a,a+n);
    multiset<ll> st;
    for (int i = 0; i < n; ++i) {
        auto it = st.lower_bound(a[i].F);
        if (it != st.begin()) {
            --it;
            if (y * (a[i].F - *it) < x) {
                ans += y * (a[i].F - *it);
                st.erase(it);
                st.insert(a[i].S);
                continue;
            }
        }
        ans += x;
        st.insert(a[i].S);
    }
    cout << ans % M << endl;
}
