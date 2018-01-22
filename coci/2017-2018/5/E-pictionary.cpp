#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87;
int p[N],s[N],a[N],n,m,q;
int find(int x) {return p[x] == x ? x : find(p[x]);}
void meld(int u,int v,int w)
{
    u = find(u);
    v = find(v);
    if (u == v) 
        return;
    if (s[u] < s[v])
        swap(u,v);
    p[v] = u;
    s[u] += s[v];
    a[v] = w;
}
int qry(int u,int v)
{
    int ans = m + 1;
    while (u != v) {
        if (s[u] < s[v])
            swap(u,v);
        ans = min(ans, a[v]);
        v = p[v];
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        s[i] = 1;
    }
    for (int i = m ; i >= 1; --i)
        for (int j = i; j <= n; j += i)
            meld(i,j,i);
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << m + 1 - qry(u,v) << '\n';
    }
}
