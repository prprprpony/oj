#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int C = 301, M = 1e9+7, N = 4e5+87, PS = 62;
ll qpow(ll a,ll b)
{
    ll r = 1;
    for (;b;b>>=1,a=a*a%M)
        if (b&1)
            r=r*a%M;
    return r;
}
int n,a[N];
ll ma[C];
struct node
{
    ll mask, val, tag, tm;
    node operator + (const node & x) const
    {
        return {mask | x.mask, val * x.val % M, 1, 0};
    }
    void upd(int k,int v,ll m)
    {
        tag = tag * v % M;
        val = val * qpow(v,k) % M;
        mask |= m;
        tm |= m;
    }
} t[N*4];
void init(int o=1,int l=0,int r=n)
{
    if (r - l == 1) {
        t[o] = {ma[a[l]],a[l],1,0};
        return;
    }
    int m = (l + r) / 2;
    init(o+o,l,m);
    init(o+o+1,m,r);
    t[o] = t[o+o] + t[o+1+o];
}
void push(int o,int l,int m,int r)
{
    t[o+o].upd(m-l,t[o].tag,t[o].tm);
    t[o+o+1].upd(r-m,t[o].tag,t[o].tm);
    t[o].tag = 1;
    t[o].tm = 0;
}
void upd(int i,int j,int v,int o=1,int l=0,int r=n)
{
    if (r <= i || j <= l)
        return;
    if (i <= l && r <= j) {
        t[o].upd(r-l,v,ma[v]);
        return;
    }
    int m = (l + r) / 2;
    push(o,l,m,r);
    upd(i,j,v,o+o,l,m);
    upd(i,j,v,o+o+1,m,r);
    t[o] = t[o+o] + t[o+o+1];
}
node qry(int i,int j,int o=1,int l=0,int r=n)
{
    if (i <= l && r <= j) 
        return t[o];
    int m = (l + r) / 2;
    push(o,l,m,r);
    if (j <= m)
        return qry(i,j,o+o,l,m);
    if (i >= m)
        return qry(i,j,o+o+1,m,r);
    return qry(i,m,o+o,l,m) + qry(m,j,o+o+1,m,r);
}
vector<int> p;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i < C; ++i)
        if (!ma[i]) {
            ll o = 1LL<<p.size();
            p.push_back(i);
            for (int j = i; j < C; j += i)
                ma[j] |= o;
        }
    for (int i = 0; i < PS; ++i)
        p[i] = (p[i]-1) * qpow(p[i],M-2) % M;
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    init();
    while (q--) {
        string s;
        int l,r,x;
        cin >> s >> l >> r;
        if (s[0] == 'M') {
            cin >> x;
            upd(l-1,r,x);
        } else {
            node ret = qry(l-1,r);
            for (int i = 0; i < PS; ++i)
                if (ret.mask>>i&1)
                    ret.val = ret.val * p[i] % M;
            cout << ret.val << '\n';
        }
    }
}
