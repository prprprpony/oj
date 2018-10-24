#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 1000000 + 87, C = 100000 + 87;
int nx[N], la[C], a[N];
void solve()
{
    int n,m;
    cin >> n >> m;
    memset(la,0x3f,sizeof(la));
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = n; i >= 1; --i) {
        nx[i] = la[a[i]];
        la[a[i]] = i;
    }
    int ans = 0;
    set<pii> st;
    for (int i = 1; i <= n; ++i) {
        auto it = st.find({i,a[i]});
        if (it != end(st)) {
            st.erase(it);
        } else if (st.size() == m) {
            st.erase(prev(end(st)));
            ++ans;
        }
        st.insert({nx[i],a[i]});
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}
