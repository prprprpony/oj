#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Q = 5e4 + 87, inf = 2e9;
ll sumq(ll a,ll d,ll b,ll n)
{
	ll ans = 0;
	if (a >= b) {
		ans += a/b * n;
		a %= b;
	}
	if (d >= b) {
		ans += d/b * (n*(n-1)/2);
		d %= b;
	}
	if (!d)
		return ans;
	ll t = (a+(n-1)*d)/b;
	if (t)
		ans += n*t - sumq(b-a+d-1,b,d,t);
	return ans;
}
ll sumr(ll a,ll d,ll b,ll n)
{
	return n > b ? n/b * sumr(a,d,b,b) + sumr(a,d,b,n%b) : (n ? a*n + n*(n-1)/2*d - b * sumq(a,d,b,n) : 0);
}
struct evt
{
	int l,r,a,d,b;
	ll u;
	evt(int _l,int _r,int _a,int _d,int _b) : l(_l), r(_r), a(_a), d(_d), b(_b), u(sumr(_a,_d,_b,_r-_l+1)) {}
	bool operator < (int x) const 
	{
		return l < x;
	}
	int at(int i) const // l <= i <= r
	{
		return (a+(i-l)*1LL*d%b)%b;
	}
	evt sub(int x,int y)
	{
		return evt(x,y,at(x),d,b);
	}
	ll qry(int x,int y) const
	{
		x = max(x,l);
		y = min(r,y);
		if (x > y)
			return 0;
		return sumr(at(x),d,b,y-x+1);
	}
};
struct node
{
	evt k;
	ll s;
	node * c[2];
	node(const evt & a) : k(a), s(a.u), c{nullptr,nullptr} {}
	void pull()
	{
		s = k.u;
		if (c[0])
			s += c[0]->s;
		if (c[1])
			s += c[1]->s;
	}
	int cmp(int v)
	{
		int d = k < v;
		return c[d] ? d : -1;
	}
};
void rot(node*&t,int d)
{
	node*k=t->c[d];
	t->c[d]=k->c[d^1];
	t->pull();
	k->c[d^1]=t;
	(t=k)->pull();
}
void splay(node*&t,int v)
{
	int d = t->cmp(v);
	if (~d) {
		node*&p=t->c[d];
		int d1=p->cmp(v);
		if (~d1) {
			splay(p->c[d1],v);
			if (d == d1)
				rot(t,d);
			else
				rot(p,d1);
		}
		rot(t,d);
	}
}
void split(node*t,int v,node*&l,node*&r)
{
	if (!t) {
		l = r = nullptr;
		return;
	}
	splay(t,v);
	if (t->k < v) {
		r = t->c[1];
		t->c[1] = nullptr;
		t->pull();
		l = t;
	} else {
		l = t->c[0];
		t->c[0] = nullptr;
		t->pull();
		r = t;
	}
}
void cut(node*t,int x,int y,node*&l,node*&m,node*&r)
{
	split(t,x,l,m);
	split(m,y+1,m,r);
	if (l)
		splay(l,inf);
	if (m) {
		splay(m,inf);
		if (m->k.r > y) {
			m->c[1] = r;
			r = m;
			m = r->c[0];
			r->c[0] = nullptr;
			r->pull();
		}
	}
	if (r)
		splay(r,-inf);
}
node * meld(node * l,node * r)
{
	if (!l || !r)
		return l ? l : r;
	splay(l,inf);
	l->c[1]=r;
	l->pull();
	return l;
}
node * rt = nullptr;
void insert(const evt & e)
{
	node*l,*m,*r;
	cut(rt,e.l,e.r,l,m,r);
	if (l) {
		evt & w = l->k;
		if (w.r > e.r) {
			node * x = new node(w.sub(e.r+1,w.r));
			x->c[1] = r;
			x->pull();
			r = x;
		}
		if (w.r >= e.l) {
			w = w.sub(w.l,e.l-1);
			l->pull();
		}
	}
	if (r) {
		evt & w = r->k;
		if (w.l <= e.r) {
			w = w.sub(e.r+1,w.r);
			r->pull();
		}
	}
	rt = new node(e);
	rt->c[0] = l;
	rt->c[1] = r;
	rt->pull();
// node * m: memory leak, but doesn't matter
}
ll qry(int x,int y)
{
	node *l, *m, *r;
	cut(rt,x,y,l,m,r);
	ll ans = m ? m->s : 0;
	if (l)
		ans += l->k.qry(x,y);
	if (r)
		ans += r->k.qry(x,y);
	rt = meld(meld(l,m),r);
	return ans;
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	while (q--) {
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		if (t == 1) {
			int a,b;
			scanf("%d%d",&a,&b);
			a %= b;
			insert(evt(l,r,a,a,b));
		} else {
			printf("%lld\n",qry(l,r));
		}
	}
}
