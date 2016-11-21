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

const int maxn = 3.18e5;
int p[maxn];
vi foe[maxn];
int inq[maxn];
int main()
{
	int n, m;
	RD(n, m);
	ll ans = 0;
	RP(i,n)
		RD(p[i]);
	DO(m) {
		int a, b;
		RD(a, b);
		foe[a].PB(b);
		foe[b].PB(a);
	}
	int i = 0, j = 0;
	for (;;) {
		while (j < n && !inq[p[j]]) {
			for (int x : foe[p[j]])
				++inq[x];
			ans += ++j - i;
		}
#ifdef PP
REP(k,i,j)
	printf("%d%c",p[k]," \n"[k==j-1]);
#endif
		if (j == n)
			break;
		while (i < j && inq[p[j]]) {
			for (int x : foe[p[i]])
				--inq[x];
			++i;
		}
	}
	printf("%lld\n",ans);
}
