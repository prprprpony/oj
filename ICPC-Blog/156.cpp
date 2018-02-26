#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
#define SZ(a) ((int)(a).size())
#define PB push_back
#define ALL(a) begin(a),end(a)
template<class T,class U>
bool cmin(T & a,const U&b) {return a>b?a=b,1:0;}
template<class T,class U>
bool cmax(T & a,const U&b) {return a<b?a=b,1:0;}
/**/
const int N = 1e6 + 87;
const pii e = {N, -N};
int n,a[N],rt[N];
pii g[N], t[N*4];
pii meld(pii x,pii y)
{
    cmin(x.F,y.F);
    cmax(x.S,y.S);
    return x;
}
void bld(int o=1,int l=0,int r=n)
{
    if (r - l == 1) {
        t[o] = g[a[l]];
        return;
    }
    int m = l + r >> 1;
    bld(o<<1,l,m);
    bld(o<<1|1,m,r);
    t[o] = meld(t[o<<1],t[o<<1|1]);
}
pii qry(int i,int j,int o=1,int l=0,int r=n)
{
    if (j <= l || r <= i)
        return e;
    if (i <= l && r <= j)
        return t[o];
    int m = l + r >> 1;
    return meld(qry(i,j,o<<1,l,m),qry(i,j,o<<1|1,m,r));
}
void upd(int i,pii p,int o=1,int l=0,int r=n)
{
    if (r - l == 1) {
        t[o] = p;
        return;
    }
    int m = l + r >> 1;
    if (i < m)
        upd(i,p,o<<1,l,m);
    else
        upd(i,p,o<<1|1,m,r);
    t[o] = meld(t[o<<1],t[o<<1|1]);
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        g[a[i]] = meld(g[a[i]], {i,i});
    }
    bld();
    ll ans = 0;
    memset(rt,0,(n+1)*sizeof(rt[0]));
    for (int i = n-1; i >= 0; --i)
        if (g[a[i]].F == i) {
            auto b = qry(i,g[a[i]].S+1);
            upd(i,b);
            g[a[i]] = e;
            if (b.F == i)
                ans += (rt[i] = rt[b.S+1] + 1);
        }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    fill_n(g,N,e);
    int T;
    cin >> T;
    while (T--) solve();
}
