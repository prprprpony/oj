#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
typedef long long ll;
const int N = 1e5 + 98;
int n,x,a[N];
struct seg
{
    vector<pii> pr, po;
    ll s;
    seg operator + (const seg & r) const
    {
        seg t;
        t.s = s + r.s;
        t.pr = pr;
        int w = t.pr.back().F;
        int rs = 0;
        for (const auto & p : r.pr) {
            rs += p.S;
            w |= p.F;
            if (w != t.pr.back().F)
                t.pr.emplace_back(w,0);
            t.pr.back().S += p.S;
        }
        for (int i = po.size()-1, j = 0; i >= 0 && j < r.pr.size(); --i) {
            while (j < r.pr.size() && (po[i].F | r.pr[j].F) < x)
                rs -= r.pr[j++].S;
            t.s += po[i].S * 1LL * rs;
        }

        t.po = r.po;
        w = t.po.back().F;
        for (const auto & p : po) {
            w |= p.F;
            if (w != t.po.back().F)
                t.po.emplace_back(w,0);
            t.po.back().S += p.S;
        }
        return t;
    }
} t[N * 4];
void bld(int o=1,int l=0,int r=n)
{
    if (r - l == 1) {
        t[o].pr = t[o].po = {{a[l],1}};
        t[o].s = a[l] >= x;
        return;
    }
    int m = l + (r - l) / 2;
    bld(o<<1,l,m);
    bld(o<<1|1,m,r);
    t[o] = t[o<<1] + t[o<<1|1];
}
void upd(int i,int v,int o=1,int l=0,int r=n)
{
    if (r - l == 1) {
        t[o].pr = t[o].po = {{a[l]=v,1}};
        t[o].s = a[l] >= x;
        return;
    }
    int m = l + (r - l) / 2;
    if (i < m)
        upd(i,v,o<<1,l,m);
    else
        upd(i,v,o<<1|1,m,r);
    t[o] = t[o<<1] + t[o<<1|1];
}
seg qry(int i,int j,int o=1,int l=0,int r=n)
{
    if (i <= l && r <= j)
        return t[o];
    int m = l + (r - l) / 2;
    if (j <= m)
        return qry(i,j,o<<1,l,m);
    if (m <= i)
        return qry(i,j,o<<1|1,m,r);
    return qry(i,j,o<<1,l,m) + qry(i,j,o<<1|1,m,r);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> n >> q >> x;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    bld();
    while (q--) {
        int i,l,r;
        cin >> i >> l >> r;
        if (i == 1)
            upd(l-1,r);
        else
            cout << qry(l-1,r).s << '\n';
    }
}
