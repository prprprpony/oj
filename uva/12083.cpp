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
#define DRIII(a,b,c) DRI(a); DRII(b,c)
#define DRIIII(a,b,c,d) DRI(a); DRIII(b,c,d)

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
const int N = 512;
pii ht[N];
vi s[2];
int sx[N],si[N];
int g[N][N];
map<string,vi> ms;
map<string,vi> sp;
char c[8787];

vi gx[N];
bool vx[N],vy[N];
int my[N],mx[N];
void init(int n)
{
	RP(i,n) {fill_n(g[i],n,1); g[i][i] = 0;}
	s[0].clear();
	s[1].clear();
	ms.clear();
	sp.clear();
	RP(i,n) gx[i].clear();
}
bool match(int u)
{
	if (vx[u]) return false;
	for (auto v : gx[u]) 
		if  (!vy[v]) {
			vy[v] = true;
			if (my[v] == -1 || match(my[v])) {
				mx[u] = v;
				my[v] = u;
				return true;
			}
		}
	return false;
}
int bm()
{
	int n = SZ(s[0]), m = SZ(s[1]), ans = 0;
	fill_n(mx,n,-1);
	fill_n(my,m,-1);
	fill_n(vx,n,false);
	RP(i,n) if (mx[i] == -1) {
		fill_n(vy,m,false);
		if (match(i))
			++ans;
		else
			vx[i] = true;
	}
	return ans;
}
int main()
{
	DRI(T);
	DO(T) {
		DRI(n);
		init(n);
		RP(i,n) {
			DRI(h);
			ht[i] = {h,i};
			RD(c[0]);
			s[sx[i] = (c[0] == 'M' ? 0 : 1)].PB(i);
			si[i] = SZ(s[sx[i]]) - 1;
			RD(c);
			ms[c].PB(i);
			RD(c);
			sp[c].PB(i);
		}
		{
			sort(ht,ht+n);
			vi vec;
			for (int i=-1,j=1;j<n;++j) {
				while (i < j && ht[j].F - ht[i+1].F > 40) {
					++i;
					vec.PB(ht[i].S);
				}
				for (int v:vec)
					g[ht[j].S][v] = g[v][ht[j].S] = 0;
			}
		}
		{
			vi vec;
			for (auto v: ms) {
				for (auto u : v.S)
					for (auto x : vec)
						g[u][x] = g[x][u] = 0;
				for (auto u : v.S)
					vec.PB(u);
			}
		}
		{
			for (auto v:sp)
				for (int i=1;i<SZ(v.S);++i)
					for (int j=i-1;j>=0;--j)
						g[v.S[i]][v.S[j]] = g[v.S[j]][v.S[i]] = 0;
		}
		RP(i,n)
			REP(j,i+1,n)
				if (g[i][j] && sx[i] != sx[j]) {
					int u=i,v=j;
					if (sx[u])
						swap(u,v);
					gx[si[u]].PB(si[v]);
				}
		PL(n-bm());
	}
}
