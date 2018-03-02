#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
struct node
{
    int i,j;
    ll s;
    bool operator < (const node & x) const
    {
        return x.s < s;
    }
};
typedef __gnu_pbds::priority_queue<node,less<node>,thin_heap_tag> heap;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 514;
const ll inf = 1e18;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int n,m,g[N][N];
ll d[N][N];
heap pq;
void init()
{
    for (int i = 0; i < n; ++i)
        fill_n(d[i],m,inf);
}
void gao()
{
    while (pq.size()) {
        int i,j;
        ll s;
        {
            auto x = pq.top();
            pq.pop();
            i = x.i, j = x.j, s = x.s;
        }
        if (d[i][j] < s)
            continue;
        for (int t = 0; t < 4; ++t) {
            int x = i + dx[t], y = j + dy[t];
            if (0 <= x && x < n && 0 <= y && y < m && (x != i || y != j) && g[x][y] >= 0) {
                ll w = s + g[x][y];
                if (w < d[x][y]) {
                    d[x][y] = w;
                    pq.push({x,y,w});
                }
            }
        }
    }
}
void solve()
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            scanf("%d",g[i]+j);
            if (g[i][j] == 0)
                g[i][j] = -1;
            else if (g[i][j] == -1)
                g[i][j] = 0;
        }
    ll ans = inf;

    init();
    for (int i = 0; i < m; ++i)
        if (g[0][i] >= 0) {
            pq.push({0,i,g[0][i]});
            d[0][i] = g[0][i];
        }
    gao();
    for (int i = 0; i < n; ++i) {
//        cerr  << "d[i][j] "<< i << ' '<< 0 << ' ' <<  d[i][0]  << endl;
        ans = min(ans, d[i][0]);
    }
    for (int i = 0; i < m; ++i)
        ans = min(ans, d[n-1][i]);


    init();
    for (int i = 0; i < n; ++i)
        if (g[i][0] >= 0) {
            pq.push({i,0,g[i][0]});
            d[i][0] = g[i][0];
        }
    gao();
    for (int i = 0; i < n; ++i)
        ans = min(ans, d[i][m-1]);


    init();
    for (int i = 0; i < n; ++i)
        if (g[i][m-1] >= 0) {
            pq.push({i,m-1,g[i][m-1]});
            d[i][m-1] = g[i][m-1];
        }
    gao();
    for (int i = 0; i < m; ++i)
        ans = min(ans, d[n-1][i]);


    printf("%lld\n",ans == inf ? -1 : ans);
}
int main()
{
    int q;
    scanf("%d%d%d",&q,&n,&m);
    while (q--) solve();
}
