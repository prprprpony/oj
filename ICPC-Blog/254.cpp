#include<bits/stdc++.h>
using namespace std;
const int N = 106, M = 1e9 + 7;
typedef long long ll;
vector<int> g[N];
int n,k;
struct dp
{
    vector<ll> d;
    dp operator + (const dp & r) const
    {
        dp ret; 
        ret.d.resize(d.size()+r.d.size());
        for (int i = 0; i < d.size(); ++i)
            for (int j = 0; j < r.d.size(); ++j)
                ret.d[i+j] += d[i] * r.d[j] % M;
        ret.norm();
        return ret;
    }
    void norm()
    {
        for (auto & x : d)
            x %= M;
    }
    void up()
    {
        vector<ll> r;
        for (int s = 0; s < d.size(); ++s)
            for (int i = 1; i <= k; ++i)
                if (s % i == 0) {
                    if (s + i >= r.size())
                        r.resize(s + i + 1);
                    r[s+i] += d[s];
                }
        d = r;
        norm();
    }
}; 
dp dfs(int u)
{
    dp a;
    a.d = {1};
    for (int v : g[u])
        a = a + dfs(v);
    a.up();
    return a;
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    const auto & a = dfs(0);
    cout << accumulate(begin(a.d),end(a.d),0LL)%M << endl;
}
