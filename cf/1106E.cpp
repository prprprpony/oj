#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 1e5+87;
vector<pii> a[N],b[N];
pii f[N];
ll dp[2][N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i)
    {
        int s,t,d,w;
        cin >> s >> t >> d >> w;
        ++d;
        a[s].emplace_back(w,d);
        b[t].emplace_back(w,d);
    }
    multiset<pii> st;
    for (int i = 1; i <= n; ++i) {
        for (const auto & p : a[i])
            st.insert(p);
        if (st.size())
            f[i] = *prev(end(st));
        else
            f[i] = {0,i+1};
        for (const auto & p : b[i])
            st.erase(st.lower_bound(p));
    }
    for (int j = n; j >= 1; --j)
        dp[0][j] = f[j].F + dp[0][f[j].S];
    for (int i = 1; i <= m; ++i) {
        int b = i & 1;
        for (int j = n; j >= 1; --j)
            dp[b][j] = min(f[j].F + dp[b][f[j].S], dp[b^1][j+1]);
    }
    cout << dp[m&1][1] << endl;
}
