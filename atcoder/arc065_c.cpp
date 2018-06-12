#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;
#define X first
#define Y second
const int N = 1e5 + 87;
pii p[N];
mt19937 ran(time(0));
struct treap
{
    int p,s,k,l,r;
} t[N * 2];
int mem_ptr;
int new_treap(int k)
{
    int o = ++mem_ptr;
    t[o].p = ran();
    t[o].s = 1;
    t[o].k = k;
    t[o].l = t[o].r = 0;
    return o;
}
void pull(int o)
{
    t[o].s = t[t[o].l].s + 1 + t[t[o].r].s;
}
int meld(int a,int b)
{
    if (!a || !b)
        return a ? a : b;
    if (t[a].p > t[b].p) {
        t[a].r = meld(t[a].r, b);
        pull(a);
        return a;
    } else {
        t[b].l = meld(a,t[b].l);
        pull(b);
        return b;
    }
}
void split(int o,int k,int & a,int & b)
{
    if (!o) {
        a = b = 0;
        return;
    }
    if (p[t[o].k].X < k) {
        a = o;
        split(t[o].r,k,t[a].r,b);
        pull(a);
    } else {
        b = o;
        split(t[o].l,k,a,t[b].l);
        pull(b);
    }
}
void insert(int & r,int k)
{
    int a,b;
    split(r,p[k].X,a,b);
    r = meld(meld(a,new_treap(k)),b);
}

map<int,int> ma,ms;
queue<int> q;
bitset<N> vis;
int w[N];
int cal(int & o,int l,int r)
{
    int a,b,c;
    split(o,l,a,b);
    split(b,r+1,b,c);
    int ret = t[b].s;
    o = meld(meld(a,b),c);
    return ret;
}
void walk(int o)
{
    if (!o)
        return;
    if (!vis[t[o].k]) {
        q.push(t[o].k);
        vis[t[o].k] = 1;
    }
    walk(t[o].l);
    walk(t[o].r);
}
void upd(int & o,int l,int r)
{
    int a,b,c;
    split(o,l,a,b);
    split(b,r+1,b,c);
    walk(b);
    o = meld(a,c);
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,a,b;
    cin >> n >> a >> b;
    --a,--b;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].X >> p[i].Y;
        insert(ma[p[i].X+p[i].Y], i);
        insert(ms[p[i].X-p[i].Y], i);
    }
    int d = abs(p[a].X - p[b].X) + abs(p[b].Y - p[a].Y);
    for (int i = 0; i < n; ++i) {
        w[i] = cal(ma[d + p[i].X + p[i].Y], p[i].X, p[i].X+d-1)
            + cal(ms[d + p[i].X - p[i].Y], p[i].X+1, p[i].X+d)
            + cal(ma[-d + p[i].X + p[i].Y], p[i].X-d+1, p[i].X)
            + cal(ms[-d + p[i].X - p[i].Y], p[i].X-d, p[i].X-1);
    }
    q.push(a);
    vis[a] = 1;
    int ans = 0;
    while (q.size()) {
        int i = q.front();
        q.pop();
        ans += w[i];
        upd(ma[d + p[i].X + p[i].Y], p[i].X, p[i].X+d-1);
        upd(ms[d + p[i].X - p[i].Y], p[i].X+1, p[i].X+d);
        upd(ma[-d + p[i].X + p[i].Y], p[i].X-d+1, p[i].X);
        upd(ms[-d + p[i].X - p[i].Y], p[i].X-d, p[i].X-1);
    }
    cout << ans / 2 << endl;
}
