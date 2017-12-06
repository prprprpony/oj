#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 5e4 + 87, C = 1e6 + 87;
const int K = pow(N,2.0/3);
int a[N],g[N],ans[N],cnt[C],num;
pair<int,pii> u[N];
struct qry
{
    int l, r, v, i;
    bool operator < (const qry & x)
    {
        if (g[l] != g[x.l])
            return g[l] < g[x.l];
        if (g[r] != g[x.r])
            return g[r] < g[x.r];
        return v < x.v;
    }
} mo[N];
void pre()
{
    for (int i = 0; i * K < N; ++i)
        fill(g + i * K, g + min(N, (i + 1) * K), i);
}
void add(int x)
{
    if (!cnt[x]++)
        ++num;
}
void sub(int x)
{
    if (!--cnt[x])
        --num;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    pre();
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int q=0,j=0;
    for (int i = 0; i < m; ++i) {
        char o;
        int x, y;
        cin >> o >> x >> y;
        if (o == 'M') {
            u[j++] = {x, {a[x], y}};
            a[x] = y;
        } else {
            mo[q] = {x,y,j,q};
            ++q;
        }
    }
    sort(mo,mo+q);
    int l=0,r=0;
    for (int i = 0; i < q; ++i) {
        while (j < mo[i].v) {
            if (l <= u[j].F && u[j].F < r) {
                sub(u[j].S.F);
                add(u[j].S.S);
            }
            a[u[j].F] = u[j].S.S;
            ++j;
        }
        while (j > mo[i].v) {
            --j;
            if (l <= u[j].F && u[j].F < r) {
                sub(u[j].S.S);
                add(u[j].S.F);
            }
            a[u[j].F] = u[j].S.F;
        }
        while (r < mo[i].r)
            add(a[r++]);
        while (l > mo[i].l)
            add(a[--l]);
        while (r > mo[i].r)
            sub(a[--r]);
        while (l < mo[i].l)
            sub(a[l++]);
        ans[mo[i].i] = num;
    }
    for (int i = 0; i < q; ++i)
        cout << ans[i] << '\n';
}
