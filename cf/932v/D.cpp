#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5 + 87;
const int D = __lg(N) + 1;
int mx[N][D],d1[N],p1[N][D],d2[N],p2[N][D];
ll s[N][D];
void add(int u,int v,int w)
{
    d1[v] = d1[u] + 1;
    p1[v][0] = u;
    for (int i = 1; i < D; ++i)
        p1[v][i] = p1[p1[v][i-1]][i-1];
    mx[v][0] = w;
    for (int i = 1; i < D; ++i)
        mx[v][i] = max(mx[v][i-1], mx[p1[v][i-1]][i-1]);
    int t = u;
    for (int i = D - 1; i >= 0; --i)
        if (mx[t][i] < w) 
            t = p1[t][i];
    d2[v] = d2[t] + 1;
    p2[v][0] = t;
    for (int i = 1; i < D; ++i)
        p2[v][i] = p2[p2[v][i-1]][i-1];
    s[v][0] = w;
    for (int i = 1; i < D; ++i)
        s[v][i] = s[v][i-1] + s[p2[v][i-1]][i-1];
}
int qry(int u,ll x)
{
    int ans = 0;
    for (int i = D - 1; i >= 0; --i)
        if ((1<<i) <= d2[u] && s[u][i] <= x) {
            x -= s[u][i];
            u = p2[u][i];
            ans |= (1<<i);
        }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int Q,ans=0,cnt=1;
    add(0,1,0);
    cin >> Q;
    while (Q--) {
        ll t,r,x;
        cin >> t >> r >> x;
        r ^= ans, x ^= ans;
        if (t == 1)
            add(r,++cnt,x);
        else
            cout << (ans = qry(r,x)) << '\n';
    }
}
