#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+87, inf = 1e9;
namespace seg
{
    int n;
    int a[N];
    struct node
    {
        int tag; // range add
        int a; // max(a[l,r])
        int b; // min(a[l,r])
        int ab, bc; 
        int abc;
        node(int x = 0)
        : tag(0),
        a(x), b(x),
        ab(x - 2 * x), bc(-2 * x + x),
        abc(0) {}
        node operator + (const node & r)
        {
            node ret;
            ret.a = max(a, r.a);
            ret.b = min(b, r.b);
            ret.ab = max({ab,r.ab,a-2*r.b});
            ret.bc = max({bc,r.bc,r.a-2*b});
            ret.abc = max({abc,r.abc,ab+r.a,a+r.bc});
            return ret;
        }
        void da(int w)
        {
            tag += w;
            a += w;
            b += w;
            ab -= w;
            bc -= w;
        }
        void print()
        {
            cerr << a << ' ' << b << ' ' << abc << endl;
        }
    } t[N*2];
    void bld(int o=0,int l=1,int r=n+1)
    {
        if (r - l == 1) {
            t[o] = node(a[l]);
            return;
        }
        const int m = l + (r - l) / 2;
        const int lc = o + 1;
        const int rc = o + (r - l) / 2 * 2;
        bld(lc,l,m);
        bld(rc,m,r);
        t[o] = t[lc] + t[rc];
    }
    void push(int o,int lc,int rc)
    {
        if (t[o].tag) {
            t[lc].da(t[o].tag);
            t[rc].da(t[o].tag);
            t[o].tag = 0;
        }
    }
    void upd(int i,int j,int w,int o=0,int l=1,int r=n+1)
    {
        if (j <= l || r <= i)
            return;
        if (i <= l && r <= j) {
            t[o].da(w);       
    //cerr << "l,r " << l << ' ' << r << endl;
    //t[o].print();
            return;
        }
        const int m = l + (r - l) / 2;
        const int lc = o + 1;
        const int rc = o + (r - l) / 2 * 2;
        push(o,lc,rc);
        upd(i,j,w,lc,l,m);
        upd(i,j,w,rc,m,r);
        t[o] = t[lc] + t[rc];
    //cerr << "l,r " << l << ' ' << r << endl;
    //t[o].print();
    }
}
char s[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q >> (s+1);
    seg::n = 2*(n-1);
    seg::a[0] = 0;
    for (int i = 1; i <= seg::n; ++i)
        seg::a[i] = seg::a[i-1] + (s[i] == '(' ? 1 : -1);
    seg::bld();
    cout << seg::t[0].abc << '\n';
    while (q--) {
        int i,j;
        cin >> i >> j;
        if (i > j)
            swap(i,j);
        if (s[i] != s[j]) {
            seg::upd(i,j,s[i]=='('?-2:2);
            swap(s[i],s[j]);
        }
        cout << seg::t[0].abc << '\n';
        //cout << flush;
    }
}
