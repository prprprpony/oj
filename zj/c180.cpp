#include<bits/stdc++.h>
using namespace std;
#define EB emplace_back

const int N = 3e5+87,inf=1e9;
typedef pair<int,int> pii;
#define F first
#define S second
typedef long long ll;
int a[N];
vector<pii> p[N];
pair<ll,ll> t[N<<2];
void add(int o,ll v)
{
    t[o].F+=v;
    t[o].S+=v;
}
void push(int o)
{
    if (t[o].S) {
        add(o+o+1,t[o].S);
        add(o+o+2,t[o].S);
        t[o].S=0;
    }
}
void pull(int o)
{
    t[o].F = max(t[o+1+o].F,t[o+2+o].F);
}
void add(int o,int l,int r,int i,int j,int v)
{
    if (r <= i || j <= l)
        return;
    if (i <= l && r <= j) {
        add(o,v);
        return;
    }
    int m=(l+r)/2;
    push(o);
    add(o+o+1,l,m,i,j,v);
    add(o+o+2,m,r,i,j,v);
    pull(o);
}
ll qry(int o,int l,int r,int i,int j)
{
    if (r <= i || j <= l)
        return -inf;
    if (i <= l && r <= j)
        return t[o].F;
    int m=(l+r)/2;
    push(o);
    return max(qry(o+o+1,l,m,i,j),qry(o+o+2,m,r,i,j));
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;++i)
        scanf("%d",a+i);
    for (int i=0;i<m;++i) {
        int l,r,v;
        scanf("%d%d%d",&l,&r,&v);
        --l,--r;
        p[r].EB(l,v);
    }
    ll ans=-inf;
    for (int i=0;i<n;++i) {
        add(0,0,n,0,i+1,a[i]);
        for (pii x:p[i])
            add(0,0,n,0,x.F+1,x.S);
        ans=max(ans,qry(0,0,n,0,i+1));
    }
    printf("%lld\n",ans);
}
