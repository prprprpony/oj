#include<bits/stdc++.h>
using namespace std;
const int N  = 1e6 + 87;
struct Splay
{
    static Splay nil, mem[N], *pmem;
    Splay *ch[2], *f;
    int val, rev, sz;
    Splay(int v = 0) : val(v), rev(0), sz(v)
    {
        f = ch[0] = ch[1] = &nil;
    }
    bool isr()
    {
        return f->ch[0] != this
            && f->ch[1] != this;
    }
    int dir()
    {
        return f->ch[1] == this;
    }
    void setCh(Splay * c, int d)
    {
        ch[d] = c;
        if (c != &nil) c->f = this;
        pull();
    }
    void push()
    {
        if (rev) {
            swap(ch[0], ch[1]);
            ch[0]->rev ^= 1;
            ch[1]->rev ^= 1;
            rev = 0;
        }
    }
    void pull()
    {
        sz = ch[0]->sz + ch[1]->sz + val;
        ch[0]->f = ch[1]->f = this;
    }
    int id()
    {
        return this == &nil ? -1 : this - mem + 1;
    }
    void prt()
    {
        if (this == &nil)
            return;
        cerr << "node:" << this - mem + 1 << endl;
        cerr << "val:"<< val << ",rev:" << rev << ",sz:" << sz  << endl;
        cerr << "f:" << f->id() << ",ch[0]:" << ch[0]->id() << ",ch[1]:" << ch[1]->id() << endl;
    }
    Splay * kth(int k)
    {
        push();
        if (sz < k)
            return &nil;
        int w = ch[0]->sz + val;
        if (w == k && val)
            return this;
        if (w >= k)
            return ch[0]->kth(k);
        return ch[1]->kth(k-w);
    }
} Splay::nil, Splay::mem[N], *Splay::pmem = Splay::mem;
Splay *nil = &Splay::nil;
void rot(Splay * x)
{
    Splay *p = x->f;
    int d = x->dir();
    if (!p->isr()) p->f->setCh(x, p->dir());
    else x->f = p->f;
    p->setCh(x->ch[!d],d);
    x->setCh(p,!d);
    p->pull();
    x->pull();
}
vector<Splay*> splayVec;
void splay(Splay * x)
{
    splayVec.clear();
    for (Splay * q = x; ; q = q->f) {
        splayVec.push_back(q);
        if (q->isr())
            break;
    }
    reverse(begin(splayVec),end(splayVec));
    for (auto it : splayVec) it->push();
    while (!x->isr()) {
        if (x->f->isr()) rot(x);
        else if (x->dir() == x->f->dir()) rot(x->f), rot(x);
        else rot(x), rot(x);
    }
}
Splay * access(Splay * x)
{
    Splay * q = nil;
    for (;x != nil; x=x->f) {
        splay(x);
        x->setCh(q,1);
        q = x;
    }
    return q;
}
void evert(Splay * x)
{
    access(x);
    splay(x);
    x->rev ^= 1;
}
void link(Splay * x, Splay * y)
{
    evert(x);
    evert(y);
    x->setCh(y,1);
}
void cut(Splay * x, Splay *y)
{
    evert(x);
    access(y);
    splay(y);
    y->ch[0] = y->ch[0]->f = nil;
    y->pull();
}
void upd(Splay * x)
{
    evert(x);
    x->val ^= 1;
    x->pull();
}
Splay * ask(Splay *x, Splay *y,int k)
{
    evert(x);
    Splay* z = access(y)->kth(k);
    if (z != nil)
        splay(z);
    return z;
}

int p[N],n,q;
Splay * vt[N];
void dbg(int k = 0)
{
    return ;
    cerr << k << "th print" << endl;
    for (int i = 1; i <=n; ++i) {
        vt[i]->prt();
        cerr << endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)  {
        int x;
        cin >> x;
        vt[i] = new (Splay::pmem++) Splay(x);
    }
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
        link(vt[p[i]], vt[i]);
    }
dbg();
    for (int kase = 1; kase <= q; ++kase) {
        char ty;
        int u,v,k;
        cin >> ty;
        if (ty == 'T') {
            cin >> u;
            upd(vt[u]);
        } else if (ty == 'C') {
            cin >> u >> v;
            cut(vt[p[u]],vt[u]);
            link(vt[p[u] = v], vt[u]);
        } else {
            cin >> u >> v >> k;
            auto w = ask(vt[u],vt[v],k);
            if (w == nil)
                cout << "-1\n";
            else
                cout << (w-Splay::mem+1) << '\n';
        }
dbg(kase);
    }
}
