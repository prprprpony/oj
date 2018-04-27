#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 87;
vector<int> g[N];
int v[N],l[N];
struct cmp
{
    bool operator () (int i,int j)
    {
        return v[i] > v[j];
    }
};
typedef priority_queue<int,vector<int>,cmp> pq;
void dfs(int u,pq & pa)
{
    pq me;
    for (int x : g[u])
        dfs(x,me);
    while (me.size() && v[me.top()] < v[u]) {
        int x = me.top();
        me.pop();
        l[x] = v[u];
    }
    me.push(u);
    if (pa.size() < me.size())
        pa.swap(me);
    for (;me.size();pa.push(me.top()), me.pop());
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) g[i].clear();
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    fill_n(l,n,n);
    pq dummy;
    dfs(0,dummy);
    const int M = 1000000007;
    long long a = 0;
    for (int i = 0; i < n; ++i)
        a += l[i] * (i + 1LL) % M;
    cout << a % M << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}
