#include<bits/stdc++.h>
using namespace std;
const int N=1e5+6;
int n,m,a[N],c[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>n>>m;
    for (int i=0;i<n;++i) cin>>a[i];
    set<pair<int,int>> st;
    for (int i=0;i<n;++i) {
        cin>>c[i];
        st.emplace(c[i],i);
    }
    while (m--) {
        int t,d;
        long long ans = 0, k;
        cin >> t >> d;
        for(--t;;t=begin(st)->second) {
            k = min(d,a[t]);
            if (!(a[t] -= k))
                st.erase({c[t],t});
            d -= k;
            ans += k * c[t];
            if (!d || st.empty())
                break;
        }
        cout << (!d)*ans << '\n';
    }
}
