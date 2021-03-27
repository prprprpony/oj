#include<bits/stdc++.h>
using namespace std;
struct segment_tree
{
    struct node
    {
        void apply(int l,int r,int v)
        {
        }
    };
    node meld(const node & a,const node & b,int l,int m,int r)
    {
        
    }
    vector<node> t;
    int n;
    void bld(int o,int l,int r)
    {
        if (r - l == 1) {
            return;
        }
        int m = l + ((r - l) >> 1);
        int z = o + ((r - l) & ~1);
        bld(o+1,l,m);
        bld(z,m,r);
        pull(o,z,l,m,r);
    }
    template<class T>
    void bld(int o,int l,int r, const vector<T>& v)
    {
        if (r - l == 1) {
            t[o] = node(v[l]);
            return;
        }
        int m = l + ((r - l) >> 1);
        int z = o + ((r - l) & ~1);
        bld(o+1,l,m,v);
        bld(z,m,r,v);
        pull(o,z,l,m,r);
    }
    void init(int _n)
    {
        n = _n;
        t.resize(2 * n - 1);
        bld(0,0,n);
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
} t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}
