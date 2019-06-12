#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 1e5+87;
int n,pa[N],de[N],f[N],dp[N],cc[N];
vector<int> g[N];
pii md;
void dfs(int p,int u,int d)
{
    md = max(md, pii(d,u));
    pa[u] = p;
    de[u] = d;
    if (d == md.F) {
        dp[u] = 1;
        cc[u] = u;
    } else {
        dp[u] = 0;
        cc[u] = 0;
    }
    for (int v : g[u])
        if (v != p) {
            dfs(u,v,d+1);
            dp[u] += dp[v];
            cc[u] = max(cc[u],cc[v]);
        }
}
bool ok(int p,int u,int d)
{
    if (f[d] == 0)
        f[d] = g[u].size();
    else if (f[d] != g[u].size())
        return 0;
    for (int v : g[u])
        if (v != p && !ok(u,v,d+1))
            return 0;
    return 1;
}
void test(int u)
{
    memset(f,0,sizeof f);
    if (ok(u,u,0)) {
        cout << u << endl;
        exit(0);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if (n <= 3) {
        cout << "1\n";
        return 0;
    }
    for (int i = 0; i < n - 1; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    md = {0,0};
    dfs(0,1,0);
    int a = md.S;
    md = {0,0};
    dfs(0,a,0);
    int b = md.S;
    int d = md.F;
    if (d % 2) {
        test(a);
        test(b);
    } else {
        int k = d/2;
        int c = b;
        for (int i = 0; i < k; ++i)
            c = pa[c];
        md = {k,a};
        test(c); 
        dfs(0,c,0);
        for (int i = 1; i <= n; ++i)
            if (g[i].size() == 1 && de[i] < k) {
                test(i);
                break;
            }
        for (int v : g[c])
            if (dp[v] == 1) {
                test(cc[v]);
                break;
            }
    }
    cout << "-1\n";
}
