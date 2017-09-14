/* -std=c99 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
typedef int64_t ll;
#define N 100087
#define D_CMP(T) int cmp_ ## T (const void * a, const void * b) \
{ \
	return *(T *)a < *(T *)b ? -1 : \
	       *(T *)a > *(T *)b ?  1 : \
	                            0 ; \
}
#define CMP(T) cmp_ ## T
void * unique(void * first,size_t n,size_t s,int (*cmp)(const void *, const void *)) 
{
	char * a = first;
	if (!n)
		return a;
	char * last = a + n * s;
	a += s;
	for (char * it = a; it != last; it += s)
		if (cmp(it, it-s)) {
			memcpy(a,it,s);
			a += s;
		}
	return a;
}
void * lower_bound(void * first,size_t n, size_t s,int (*cmp)(const void *, const void *),void * v)
{
	char * a = first;
	if (!n)
		return a;
	if (cmp(a,v) >= 0)
		return a;
	size_t k = 1;
	while (k <= n - k)
		k<<=1;
	size_t i = 0;
	for (;k;k>>=1)
		if ((i | k) < n && cmp(a + (i | k) * s, v) < 0)
			i |= k;
	return a + (i+1) * s;
}
#define D_DISC(T) int disc_ ## T (T * a,size_t n,int (*cmp)(const void *, const void *)) \
{ \
	static T b[N]; \
	memcpy(b,a,n*sizeof(T)); \
	qsort(b,n,sizeof(T),cmp); \
	size_t m = (T *)unique(b,n,sizeof(T),cmp) - b; \
	for (T * it = a; it != a + n; it++) \
		*it = (T *)lower_bound(b,m,sizeof(T),cmp,it) - b; \
	return m; \
}
#define DISC(T,a,n,cmp) disc_ ## T (a,n,cmp)
typedef struct _node
{
	int s, lc, rc;
} node;
node tr[N * 40];
int t[N], mptr;
int fn, tn;
int newnode()
{
	int a = ++mptr;
	memset(tr + a,0,sizeof(node));
	return a;
}
void tadd(int * o,int l,int r,int i,int v)
{
	if (!*o)
		*o = newnode();
	tr[*o].s += v;
	if (r - l == 1)
		return;
	int m = l + (r - l) / 2;
	if (i < m)
		tadd(&(tr[*o].lc),l,m,i,v);
	else
		tadd(&(tr[*o].rc),m,r,i,v);
}
int tqry(int o,int l,int r,int i,int j)
{
	if (r <= i || j <= l || !o)
		return 0;
	if (i <= l && r <= j)
		return tr[o].s;
	int m = (l + r) / 2;
	return tqry(tr[o].lc,l,m,i,j) + tqry(tr[o].rc,m,r,i,j);
}
void add(int i,int j,int v)
{
	for (; i <= fn; i += i & -i)
		tadd(t + i, 0, tn, j, v);
}
int qry(int i,int l,int r)
{
	int ans = 0;
	for (; i; i ^= i & -i)
		ans += tqry(t[i], 0, tn, l, r);
	return ans;
}
D_CMP(ll)
D_DISC(ll)
ll a[N], b[N];
int main()
{
	ll n,d,u;
	scanf("%lld%lld%lld",&n,&d,&u);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", a + i);
		a[i] += -d + a[i-1];
	}
	u -= d;
	for (int i = 1; i <= n; ++i)
		b[i] = a[i] - i * u;
	fn = DISC(ll,a,n+1,CMP(ll));
	tn = DISC(ll,b,n+1,CMP(ll));
	ll ans = 0;
	for (int i = 0; i <= n; ++i) {
		ans += qry(++a[i],b[i],tn);
		add(a[i],b[i],1);
	}
	printf("%lld\n", ans);
}
