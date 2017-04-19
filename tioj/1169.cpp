#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+87;
int a[N];
struct ev
{
    int k,t,l,r;
    ev() {}
    ev(int z,int x,int c,int v) : k(z), t(x), l(c), r(v) {}
    bool operator < (const ev & x) const
    {
        return k < x.k;
    }
} e[N*4];
struct node
{
    int pre,post,len;
} tr[N*4];
void meld(int n,const node & x,int m,const node & y,node & z)
{
    z.len = max(x.post+y.pre,max(x.len,y.len));
    z.pre = x.pre == n ? n + y.pre : x.pre;
    z.post = y.post == m ? x.post + m : y.post;
}
void bld(int o,int l,int r)
{
    if (r-l==1) {
        tr[o].pre = tr[o].post = tr[o].len = 1;
        return;
    }
    int m=l+((r-l)>>1);
    bld(o+o+1,l,m);
    bld(o+o+2,m,r);
    meld(m-l,tr[o+o+1],r-m,tr[o+o+2],tr[o]);
}
void chg(int o,int l,int r,int i,int v)
{
    if (r-l==1) {
        tr[o].pre = tr[o].post = tr[o].len = v;
        return;
    }
    int m=l+((r-l)>>1);
    if (i < m)
        chg(o+o+1,l,m,i,v);
    else
        chg(o+o+2,m,r,i,v);
    meld(m-l,tr[o+o+1],r-m,tr[o+o+2],tr[o]);
}
node qry(int o,int l,int r,int i,int j)
{
    if (i <= l && r <= j)
        return tr[o];
    int m=(l+r)>>1;
    if (j <= m)
        return qry(o+o+1,l,m,i,j);
    if (m <= i)
        return qry(o+o+2,m,r,i,j);
    node t;
    meld(m-i,qry(o+o+1,l,m,i,m),j-m,qry(o+o+2,m,r,m,j),t);
    return t;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,q,c,m=0,w=0;
    cin >> n >> q >> c;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        e[m++] = {a[i],-2,i,87};
    }
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (!t) {
            int p,k;
            cin>>p>>k;
            e[m++] = {a[p],-1,p,87};
            e[m++] = {a[p]=k,-2,p,87};
        } else {
            int x,y,k;
            cin>>x>>y>>k;
            e[m++] = {k,w++,x,y};
        }
    }
    for (int i = 0; i < n; ++i)
        e[m++] = {a[i],-1,i,87};
    stable_sort(e,e+m);
    bld(0,0,n);
    for (int i = 0; i < m; ++i)
        if (e[i].t >= 0)
            a[e[i].t] = qry(0,0,n,e[i].l,e[i].r).len;
        else
            chg(0,0,n,e[i].l,e[i].t+2);
    for (int i = 0; i < w; ++i)
        cout << a[i] << '\n';
}
