#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 3e5+9;
pii s[N];
int t[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i].F;
        s[i].S = i+1;
    }
    for (int i = 0; i < n; ++i)
        cin >> t[i];
    sort(s,s+n);
    sort(t,t+n);
    vector<pair<pii,int>> ans;
    vector<pii> st;
    for (int i = 0; i < n; ++i) {
        int d = s[i].F - t[i];
        if (d < 0)
            st.emplace_back(-d,s[i].S);
        while (d > 0 && st.size()) {
            pii p = st.back();
            st.pop_back();
            int x = min(d,p.F);
            ans.emplace_back(pii(p.S,s[i].S),x);
            d -= x;
            p.F -= x;
            if (p.F)
                st.push_back(p);
        }
        if (d > 0) {
            cout << "NO\n";
            return 0;
        }
    }
    if (st.size()) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n" << ans.size() << '\n';
    for (auto p : ans)
        cout << p.F.F << ' ' << p.F.S << ' ' << p.S << '\n';

}
