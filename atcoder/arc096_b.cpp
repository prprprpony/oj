#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 87;
ll x[N],v[N],n,c;
ll pr[N],po[N];
ll solve()
{
    ll su = 0;
    for (int i = 1; i <= n; ++i) {
        su += v[i];
        pr[i] = max(pr[i-1], su - 2 * x[i]);
    }
    su = 0;
    for (int i = n; i >= 1; --i) {
        su += v[i];
        po[i] = max(su - (c - x[i]), po[i+1]);
    }
    ll ans = 0;
    for (int i = 0; i <= n; ++i)
        ans = max(ans, pr[i]+po[i+1]);
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> v[i];
    ll ans = max(0LL,solve());
    for (int i = 1; i <= n; ++i)
        x[i] = c - x[i];
    reverse(x+1,x+n+1);
    reverse(v+1,v+n+1);
    cout << max(ans, solve()) << endl;
}
