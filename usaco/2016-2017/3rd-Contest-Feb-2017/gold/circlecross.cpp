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

void PL(void) {PT('\n');}
template<typename T, typename ... TT>
void PL(const T a, const TT ... b) {PT(a);if (sizeof...(b)) PT(' '); PL(b...);}
/**************************/
const int N = 5.14e4;
struct BIT 
{
	int n,a[N<<1];
	void init(int m) {n = m;}
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
int la[N];
pii p[N];
int main()
{
#ifndef PP
	freopen("circlecross.in","r",stdin);
	freopen("circlecross.out","w",stdout);
#endif
	DRI(n);
	int ans = 0,tp = 0;
	REP(i,1,2*n+1) {
		DRI(a);
		if (la[a])
			p[tp++] = {i, i - la[a]};
		else
			la[a] = i;
	}
	sort(p, p + n);
	B.init(n*2);
	RP(i,n) {
		ans += p[i].S - 1 - 2 * B.qry(p[i].F-p[i].S, p[i].F);
		B.add(p[i].F-p[i].S,1);
	}
	PL(ans/2);
}
