#include <iostream>
#include <functional>
#include <iterator>
using namespace std;
template<typename It, typename Cmp>
void Ford_Johnson(It first, It last, Cmp cmp)
{
	typedef typename iterator_traits<It>::value_type T;
	struct node
	{
		It k;
		node * p;
		node * c[2];
		size_t s;
		node * lc; // use c[1] as right-sibling pointwr
		node * merge(node * t)
		{
			if (Cmp()(*k, *(t->k))) {
				c[1] = t->lc;
				t->lc = this;
				return t;
			}
			t->c[1] = lc;
			lc = t;
			return this;
		}
		void walk(node **& x)
		{
			if (c[0])
				c[0]->walk(x);
			*(x++) = this;
			if (c[1])
				c[1]->walk(x);
		}
		node * pop()
		{
			node * t = lc;
			lc = lc->c[1];
			return t;
		}
		node * kth(size_t i)
		{
			size_t w = 1 + (c[0] ? c[0]->s : 0);
			if (i == w)
				return this;
			if (i < w)
				return c[0]->kth(i);
			return c[1]->kth(i - w);
		}
		int ch(node * v)
		{
			return v == c[1];
		}
		void pull()
		{
			s = 1;
			if (c[0])
				s += c[0]->s;
			if (c[1])
				s += c[1]->s;
		}
		void setc(int d,node * t)
		{
			c[d] = t;
			if (t)
				t->p = this;
			pull();
		}
		node * cutc(int d)
		{
			node * t = c[d];
			setc(d,nullptr);
			if (t)
				t->p = nullptr;
			return t;
		}
		void rot(int d)
		{
			node * x = p->p;
			p->setc(d,c[d^1]);
			setc(d^1,p);
			if (x)
				x->c[x->ch(p)] = this;
			p = x;
		}
		node * splay()
		{
			while (p && p->p) {
				node * t = p->p;
				int d = t->ch(p);
				int q = p->ch(this);
				if (d == q)
					p->rot(d);
				else
					rot(q);
				rot(d);
			}
			if (p)
				rot(p->ch(this));
			return this;
		}
	};
	size_t n = distance(first, last);
	if (n <= 1)
		return;
	node * mem = new node[n]();
	node ** a = new node * [n];
	T * b = new T[n];

	{
		It it = first;
		for (size_t i = 0; i < n; ++i) {
			mem[i].k = it++;
			a[i] = mem + i;
		}
	}
	size_t k = 0;
	for (size_t w = n >> 1; w; ++k, w >>= 1) {
		for (size_t i = 0; i < w; ++i)
			a[i] = a[i]->merge(a[i+w]);
	}
	node * rt = a[0];
	while (k--) {
		{
			node ** x = a;
			rt->walk(x);
		}
		size_t m = n >> k;
		size_t w = m >> 1;
		for (size_t i = 0; i < w; ++i)
			a[i+w] = a[i]->pop();
		for (size_t t0 = 0, t1 = 1, c = 2;  w + t0 < m; t0 = t1, c <<= 1, t1 = c - t1)
			for (size_t i = min(w + t1, m); i-- > w + t0; ) {
				node * l, * r = nullptr;
				bool odd = i == w + w;
				if (odd) {
					l = rt;
				} else {
					rt = a[i - w]->splay();
					l = rt->cutc(0);
				}
				if (l) {
					size_t lo = 1, hi = l->s;
					while (lo <= hi) {
						size_t mi = lo + ((hi - lo) >> 1);
						l = l->kth(mi)->splay();
						if (cmp(*(l->k), *(a[i]->k)))
							lo = mi + 1;
						else
							hi = mi - 1;
					}
					if (hi) {
						l = l->kth(hi)->splay();
						r = l->cutc(1);
					} else {
						r = l;
						l = nullptr;
					}
				}
				a[i]->setc(0,l);
				a[i]->setc(1,r);
				if (odd) {
					rt = a[i];
				} else {
					rt->setc(0,a[i]);
				}
			}
	}
	node ** x = a;
	rt->walk(x);
	for (size_t i = 0; i < n; ++i)
		b[i] = *(a[i]->k);
	for (size_t i = 0; i < n; ++i)
		*(first++) = b[i];
	delete [] mem;
	delete [] a;
	delete [] b;
}
template<typename It, typename Cmp = less<typename iterator_traits<It>::value_type>>
void Ford_Johnson(It first, It last)
{
	Ford_Johnson(first, last, Cmp());
}
struct cmp
{
	bool operator () (char x, char y) const
	{
		cout << "? " << x << " " << y << endl;
		char r;
		cin >> r;
		return r == '<';
	}
};
char a[27];
int main()
{
	int n,q;
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
		a[i] = 'A' + i;
	Ford_Johnson(a,a+n,cmp());
	cout << "! " << a << endl;
}
