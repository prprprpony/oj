#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
#define SZ(a) ((int)(a.size()))

template <typename T>
T cmin(T & a, T b) {return a = min(a,b);}
template <typename T>
T cmax(T & a, T b) {return a = max(a,b);}

#define REP(i,a,b) for (int i(a),__e(b);i<__e;++i)
#define RP(i,n) REP(i,0,n)
#define DO(n) RP(__i,n)

bool RD(void) {return 1;}
bool RD(int & a) {return scanf("%d", &a) == 1;}
template<typename T, typename ... TT>
bool RD(T & a, TT & ... b) {return RD(a) && RD(b...);}
#define DRI(a) int a; RD(a)
#define DRII(a,b) DRI(a); DRI(b)
#define DRIII(a,b,c) DRI(a); DRII(b,c)
#define DRIIII(a,b,c,d) DRI(a); DRIII(b,c,d)

void PT(const char a) {putchar(a);}
void PT(const char * a) {fputs(a,stdout);}
void PT(const int a) {printf("%d",a);}
void PT(const ll a) {printf("%lld",a);}

void PL(void) {PT('\n');}
template<typename T, typename ... TT>
void PL(const T a, const TT ... b) {PT(a);if (sizeof...(b)) PT(' '); PL(b...);}
/**************************/
const int N = 1.12e5;
struct BIT 
{
	int n,a[N];
	void init(int m)
	{
		n = m;
		fill_n(a+1,n,0);
	}
	void add(int i,int v)
	{
		for (; i <= n; i += i & -i)
			a[i] += v;
	}
	int qry(int i)
	{
		int ret = 0;
		for (; i; i ^= i & -i)
			ret += a[i];
		return ret;
	}
	int qry(int i, int j)
	{
		return qry(j) - qry(i-1);
	}
} B;
int v[N],p[N];
ll solve(int n,const int * a, const int * b)
{
	B.init(n);
	REP(i,1,n+1) v[a[i]] = i;
	ll c = 0;
	REP(i,1,n+1) {
		p[i] = v[b[i]];
		if (p[i] < n)
			c += B.qry(p[i]+1,n);
		B.add(p[i],1);
	}
	ll ret = c;
	REP(i,1,n) {
		c += -(p[i]-1) + (n-p[i]);
		cmin(ret,c);
	}
	return ret;
}
int a[N],b[N];
int main()
{
#ifndef PP
	freopen("mincross.in","r",stdin);
	freopen("mincross.out","w",stdout);
#endif
	DRI(n);
	REP(i,1,n+1) RD(a[i]);
	REP(i,1,n+1) RD(b[i]);
	PL(min(solve(n,a,b), solve(n,b,a)));
}
