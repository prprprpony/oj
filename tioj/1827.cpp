#include <bits/stdc++.h>
using namespace std;
// nichijou
#define REP(i,a,b) for (int i = (a), __e = (b); i < __e; ++i)
#define RP(i,n) REP(i,0,n)
#define PER(i,s,e) for (int i = (s) - 1, __e = (e); i >= __e; --i)
#define PR(i,n) PER(i,n,0)
#define REP1(i,a,b) for (int i = (a), __e = (b); i <= __e; ++i)
#define RP1(i,n) REP1(i,1,n)
#define PER1(i,s,e) for (int i = (s), __e = (e); i >= __e; --i)
#define PR1(i,n) PER1(i,n,1)
#define DO(n) REP(__i,0,n)
template<typename T>
void cmax(T & a, T b) {a = max(a, b);}
template<typename T>
void cmin(T & a, T b) {a = min(a, b);}

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
#define BK(a) (a.back())
#define FT(a) (a.front())
#define DB(a) a.pop_back()
#define DF(a) a.pop_front()
#define PB push_back
#define EB emplace_back

/* Reading input is now 20% cooler! */
bool RD(void) {return true;}
template<typename T>
bool RD(T & a)
{
	int c;
	while (!isdigit(c = getchar()));
	a = c&15;
    while (isdigit(c = getchar()))
        a = 10 * a + (c & 15);
	return 1;
}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
template<typename T, typename ... TT>
bool RD(T & a, TT & ...  b) {return RD(a) && RD(b...);}

/* Do princesses dream of magic sheep? */
#define RI(a) int a; RD(a)
#define RII(a,b) RI(a); RI(b)
#define RIII(a,b,c) RI(a); RII(b,c)
#define RIIII(a,b,c,d) RI(a); RIII(b,c,d)

/* For it's time for you to fulfill your output. */
void PT(const char * a) {fputs(a, stdout);}
void PT(char * a) {fputs(a, stdout);}
template<typename T>
void PT(const T a)
{
	static const int maxd = 25;
	static char d[maxd];
	int i = maxd - 1;
	T t = a;
    do {
        d[--i] = (t % 10) | 48;
    } while (t /= 10);
	PT(d + i);
}
void PT(const double a) {printf("%.16f", a);}
void PT(const char a) {putchar(a);}

/* The line will last forever! */
void PL(void) {PT('\n');}
template<typename T, typename ... TT>
void PL(const T a, const TT ...  b) {PT(a); if (sizeof...(b)) PT(' '); PL(b...);}

/* Good Luck && Have Fun ! */
const int N = 1e5 + 87;
const int D = __lg(N)+1;
struct node
{
	int s;
	node*l,*r;
} mem[N*D*2];
node * rt[N],* ptr=mem;
node * add(node * t,int l,int r,int i)
{
	t=t?new(ptr++) node(*t):new(ptr++) node();
	++t->s;
	if (r-l==1)
		return t;
	int m=l+((r-l)>>1);
	if (i<m)
		t->l=add(t->l,l,m,i);
	else
		t->r=add(t->r,m,r,i);
	return t;
}
int qry(node*t,int l,int r,int i,int s=0)
{
	if (!t)
		return s;
	if (r==i+1)
		return s+t->s;
	int m=l+((r-l)>>1);
	if (i<m)
		return qry(t->l,l,m,i,s);
	return qry(t->r,m,r,i,(t->l?t->l->s:0) + s);
}
int main()
{
	RII(n,m);
	RP1(i,n) {
		RI(b);
		rt[i] = add(rt[i-1],1,n+1,b);
	}
	DO(m) {
		RII(p,k);
		++p;
		int lo = 1, hi = n;
		while (lo <= hi) {
			int mi=(lo+hi)>>1;
			if (qry(rt[min(p+mi,n)],1,n+1,mi) - qry(rt[max(p-mi-1,0)],1,n+1,mi) >= k)
				hi = mi - 1;
			else
				lo = mi + 1;
		}
		PL(lo);
	}
}
