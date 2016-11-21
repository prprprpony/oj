#include <bits/stdc++.h>
using namespace std;
// iteration
#define CONC(a,b) a ## b
#define CONC_M(a,b) CONC(a,b)
#define __REP(i,s,j,e,nxt) for (auto i = (s), j = (e); i != j; i nxt)
#define _REP(i,s,e,nxt) __REP(i,s,CONC_M(__e,__LINE__),e,nxt)
#define REP(i,s,e) _REP(i,s,e, ++)
#define RP(i,n) REP(i,0,n)
#define PER(i,s,e) _REP(i,s,e, --)
#define PR(i,n) PER(i,n-1,-1)
#define REP_B(i,e) _REP(i,1,e, <<= 1)
#define DO(n) REP(CONC_M(__i,__LINE__),0,n)

// data type
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define F first
#define S second

// STL container
typedef vector<int> vi;
typedef vector<ll> vll;
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(), a.end()
#define CLR(a) a.clear()
#define DB(a) a.pop_back()
#define DF(a) a.pop_front()
#define PB push_back
#define EB emplace_back

// input
bool RD(void) {return true;}
bool RD(int & a) {return scanf("%d", &a) == 1;}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
template<typename T, typename ... TT>
bool RD(T & a, TT & ...  b) {return RD(a) && RD(b...);}

/* Good Luck && Have Fun ! */

const int maxn = 2.25e5;
struct rng
{
	int l, r, i;
	bool operator < (const rng & rhs) const
	{
		return r < rhs.r || (r == rhs.r && l > rhs.l);
	}
} s[maxn];
int ans[maxn];

mt19937 ran(42);
struct node
{
	int v, sz, pr;
	node * c[2];
	node(int a) : v(a), sz(1), pr(ran()), c{NULL,NULL} {}
};
node * root = NULL;

inline int size(node * t) {return t ? t->sz : 0;}
inline void pull(node * t) {t->sz = 1 + size(t->c[0]) + size(t->c[1]);}
void split(node * t, node *& a, node *& b, int k)
{
	if (!t) {
		a = b = NULL;
		return ;
	}
	if (t->v < k) {
		a = t;
		split(t->c[1], a->c[1], b, k);
		pull(a);
	} else {
		b = t;
		split(t->c[0], a, b->c[0], k);
		pull(b);
	}
}
node * merge(node * a, node * b)
{
	if (!a || !b)
		return a ? a : b;
	if (a->pr > b->pr) {
		a->c[1] = merge(a->c[1], b);
		pull(a);
		return a;
	} else {
		b->c[0] = merge(a, b->c[0]);
		pull(b);
		return b;
	}
}

int main()
{
	int n;
	RD(n);
	RP(i,n) {
		RD(s[i].l, s[i].r);
		s[i].i = i;
	}
	sort(s, s + n);
	RP(i,n) {
		node * l, * r;
		split(root, l, r, s[i].l);
		ans[s[i].i] = size(r);
		root = merge(merge(l, new node(s[i].l)), r);
	}
	RP(i,n)
		printf("%d\n", ans[i]);
}
