#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
struct segment_tree
{
    struct node
    {
        ll w,s,b;
        void apply(int l,int r,ll v)
        {
            s += v;
            b = min(w,s);
        }
    };
    node meld(const node & a,const node & b,int l,int m,int r)
    {
        node ret;
        ret.w = a.w + b.w;
        ret.s = a.s + b.s;
        ret.b = a.b + b.b + min(a.w-a.b,b.s-b.b);
        return ret;
    }
    vector<node> t;
    int n;
    template<class T>
    void bld(int o,int l,int r, const vector<T>& v)
    {
        if (r - l == 1) {
            t[o] = {v[l].F - (l?v[l-1].F:0), 0, 0};
            return;
        }
        int m = l + ((r - l) >> 1);
        int z = o + ((r - l) & ~1);
        bld(o+1,l,m,v);
        bld(z,m,r,v);
        pull(o,z,l,m,r);
    }
    template<class T>
    void init(int _n,const vector<T>&v)
    {
        n = _n;
        t.resize(2 * n - 1);
        bld(0,0,n,v);
    }
    void push(int o,int z,int l,int m,int r)
    {
        /*
        if (t[o].tag) {
            t[o+1].apply(l,m,t[o].tag);
            t[z].apply(m,r,t[o].tag);
            t[o].tag = 0;
        }
        //*/
    }
    void pull(int o,int z,int l,int m,int r)
    {
        t[o] = meld(t[o+1],t[z],l,m,r);
    }
    template <typename...T>
    void upd(int o,int l,int r,int i,int j,const T&... v)
    {
        if (i <= l && r <= j) {
            t[o].apply(l,r,v...);
            return;
        }
        int m = l + ((r - l) >> 1);
        int z = o + ((r - l) & ~1);
        push(o,z,l,m,r);
        if (i < m)
            upd(o+1,l,m,i,j,v...);
        if (j > m)
            upd(z,m,r,i,j,v...);
        pull(o,z,l,m,r);
    }
    template <typename...T>
    void upd(int i,int j,const T&... v)
    {
        assert(0 <= i && i < j && j <= n);
        upd(0,0,n,i,j,v...);
    }
    template <typename...T>
    void upd1(int i,const T&... v)
    {
        assert(0 <= i && i < n);
        upd(0,0,n,i,i+1,v...);
    }
    node qry(int o,int l,int r,int i,int j)
    {
        if (i <= l && r <= j)
            return t[o];
        int m = l + ((r - l) >> 1);
        int z = o + ((r - l) & ~1);
        push(o,z,l,m,r);
        if (j <= m)
            return qry(o+1,l,m,i,j);
        if (i >= m)
            return qry(z,m,r,i,j);
        return meld(qry(o+1,l,m,i,m),qry(z,m,r,m,j),l,m,r);
    }
    node qry(int i,int j)
    {
        return qry(0,0,n,i,j);
    }
} tree;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<ll> k(n);
    vector<pair<ll,int>> d(m);
    ll tot=0;
    for (auto & x : k) cin >> x, tot += x;
    ll ans=tot*2;
    for (auto & x : d) cin >> x.F >> x.S, --x.S;
    sort(begin(d),end(d));
    tree.init(m,d);
    vector<int> la(n,-1);
    for (int i = 0; i < m; ++i) {
        ll w = d[i].F;
        int t = d[i].S;
        if (la[t] != -1)
            tree.upd1(la[t],-k[t]);
        tree.upd1(la[t] = i,k[t]);
        ll b=tree.t[0].b;
        ll r=max((tot-b)*2-(w-b),0ll);
        ans = min(ans, w+r);
    }
    cout << ans << endl;
}
