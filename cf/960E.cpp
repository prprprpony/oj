#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll M = 1e9 + 7;
void norm(ll &s)
{
    s=((s%M)+M)%M;
}
struct dp
{
    ll v,s,w[2],c[2];
    dp(ll k) : v(k), s(k), w{0,k}, c{0,1} {}
    dp operator += (const dp & r) 
    {
        norm(s += r.s + w[0] * r.c[1] + w[1] * r.c[0] + r.w[0] * c[1] + r.w[1] * c[0]);
        norm(w[0] += r.w[1] - v * r.c[1]);
        norm(w[1] += r.w[0] + v * r.c[0]);
        norm(c[0] += r.c[1]);
        norm(c[1] += r.c[0]);
        return *this;
    }
};
const int N = 2e5 + 98;
ll v[N];
vector<int> g[N];
dp dfs(int p,int u)
{
    dp now(v[u]);
    for (int w : g[u])
        if (w != p) 
            now += dfs(u,w);
    return now;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        norm(v[i]);
    }
    for (int i = 0; i < n-1; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    ll ans = dfs(0,1).s;
    norm(ans = ans * 2 - accumulate(v+1,v+n+1,0LL));
    cout << ans << endl;
}
