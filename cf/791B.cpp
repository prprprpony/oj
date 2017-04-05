#include <bits/stdc++.h>
using namespace std;
const int N = 150000 + 87;
typedef vector<int> vi;
#define PB push_back

vi g[N];
bool vis[N];
int st[N],tp;
void dfs(int u)
{
    vis[u] = true;
    st[tp++] = u;
    for (int v : g[u]) if (!vis[v]) dfs(v);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i <m ;++i) {
        int u,v;
        scanf("%d%d",&u,&v);
        --u,--v;
        g[u].PB(v);
        g[v].PB(u);
    }
    for(int i=0;i<n;++i) if (!vis[i]) {
        tp = 0;
        dfs(i);
        int s = 0;
        for (int j = 0; j < tp; ++j) s += g[st[j]].size();
        if (s != tp * 1LL * (tp-1)) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}
