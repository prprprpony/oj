#include <bits/stdc++.h>
using namespace std;
// nichijou
#define REP(i,a,b) for (int i = (a), __e = (b); i < __e; ++i)
#define RP(i,n) REP(i,0,n)
#define REP1(i,a,b) for (int i = (a), __e = (b); i <= __e; ++i)
#define RP1(i,n) REP1(i,1,n)
#define PER(i,s,e) for (int i = (s) - 1, __e = (e); i >= __e; --i)
#define PR(i,n) PER(i,n,0)
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
bool RD(int & a) {return scanf("%d", &a) == 1;}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
template<typename T, typename ... TT>
bool RD(T & a, TT & ...  b) {return RD(a) && RD(b...);}

/* Do princesses dream of magic sheep? */
#define DRI(a) int a; RD(a)
#define DRII(a,b) DRI(a); DRI(b)

/* For it's time for you to fulfill your output. */
void PT(const int a) {printf("%d", a);}
void PT(const ll a) {printf("%lld", a);}
void PT(const double a) {printf("%.16f", a);}
void PT(const char a) {putchar(a);}
void PT(const char * a) {fputs(a, stdout);}

/* The line will last forever! */
void PL(void) {PT('\n');}
template<typename T, typename ... TT>
void PL(const T a, const TT ...  b) {PT(a); if (sizeof...(b)) PT(' '); PL(b...);}

/* Good Luck && Have Fun ! */
const int N = 3005, inf = 1e9;
vi e[N];
int g[N][N];
pii in[N][4], ot[N][4];
int ans,a[4];
int main()
{
	DRII(n,m);
	RP1(i,n)
		fill_n(g[i]+1,n,inf);
	DO(m) {
		DRII(u,v);
		if (u != v)
			e[u].PB(v);
	}
	RP1(i,n) {
		queue<int> q;
		q.push(i);
		g[i][i] = 0;
		while (SZ(q)) {
			int u = q.front();
			q.pop();
			for (auto v : e[u])
				if (g[i][v] == inf) {
					g[i][v] = g[i][u] + 1;
					q.push(v);
				}
		}
	}
	RP1(i,n)
		RP1(j,n) if (g[i][j] != inf && i != j) {
			ot[i][3] = {g[i][j], j};
			sort(ot[i],ot[i]+4,greater<pii>());
			in[j][3] = {g[i][j], i};
			sort(in[j],in[j]+4,greater<pii>());
		}
	RP1(i,n)
		RP1(j,n)
			if (g[i][j] != inf && i != j)
				RP(k,3) {
					pii x = in[i][k];
					if (!x.S)
						break;
					if (x.S != j)
						RP(l,3) {
							pii y = ot[j][l];
							if (!y.S)
								break;
							if (y.S != i && x.S != y.S) {
								int v = x.F + g[i][j] + y.F;
								if (v > ans) {
									ans = v;
									a[0] = x.S;
									a[1] = i;
									a[2] = j;
									a[3] = y.S;
								}
								break;
							}
						}
				}
	RP(i,4)
		PT(a[i]), PT(" \n"[i==3]);
}
