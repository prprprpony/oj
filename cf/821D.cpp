#include <bits/stdc++.h>
using namespace std;
// nichijou
#define REP(i,a,b) for (int i(a), _B(b); i < _B; ++i)
#define RP(i,n) REP(i,0,n)
#define PER(i,a,b) for(int i((a)-1), _B(b); i >= _B; --i)
#define PR(i,n) PER(i,n,0)
#define REP1(i,a,b) REP(i,a,(b)+1)
#define RP1(i,n) REP1(i,1,n)
#define PER1(i,a,b) PER(i,(a)+1,b)
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

/* I gave you my heart and then you turned around. */
void _BG(const char * s) {}
template<typename T, typename ... TT>
void _BG(const char * s,T a, TT...b)
{
	for (int c = 0; *s && (c || *s != ','); ++s) {
		cerr<<*s;
		switch (*s) {
		case '(':
		case '[':
		case '{':
			++c;
			break;
		case ')':
		case ']':
		case '}':
			--c;
			break;
		}
	}
	cerr<<" = "<<a;
	if (*s) {
		cerr<<", ";
		_BG(++s,b...);
	} else
		cerr<<endl;
}
#define BG(...) do { \
	cerr << __PRETTY_FUNCTION__ << ':' << __LINE__ << ": "; \
	_BG(#__VA_ARGS__,__VA_ARGS__); \
} while(0)

/* Reading input is now 20% cooler! */
bool RD(void) {return true;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(int & a) {return scanf("%d", &a) == 1;}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}

template<typename T, typename ... TT>
bool RD(T & a, TT & ...  b) {return RD(a) && RD(b...);}

/* Do princesses dream of magic sheep? */
#define RI(a) int a; RD(a)
#define RII(a,b) RI(a); RI(b)
#define RIII(a,b,c) RI(a); RII(b,c)
#define RIIII(a,b,c,d) RI(a); RIII(b,c,d)

/* For it's time for you to fulfill your output. */
void PT(const char a) {putchar(a);}
void PT(const char * a) {fputs(a, stdout);}
void PT(char * a) {fputs(a, stdout);}
void PT(const double a) {printf("%.16f", a);}
void PT(const int a) {printf("%d", a);}
void PT(const ll a) {printf("%lld", a);}

/* The line will last forever! */
template<char sep = ' ',char end = '\n'>
void PL(void) {if (end) PT(end);}
template<char sep = ' ',char end = '\n',typename T, typename ... TT>
void PL(const T a, const TT ...  b) {PT(a); if (sizeof...(b) && sep) PT(sep); PL<sep,end>(b...);}

/* Good Luck && Have Fun ! */
const int N = 1e4 + 87, inf = 1e9;
vi row[N],col[N],g[N];
pii a[N];
int d[N*3];
int main()
{
	RIII(n,m,k);
	int lu = 0, rb = 0;
	RP1(i,k) {
		RII(r,c);
		a[i] = {r,c};
		row[r].PB(i);
		col[c].PB(i);
		if (r == 1 && c == 1)
			lu = i;
		else if (r == n && c == m)
			rb = i;
	}
	RP1(r,n) {
		for (int i : row[r])
			d[a[i].S] = i;
		for (int i : row[r])
			if (d[a[i].S-1]) {
				g[i].PB(d[a[i].S-1]);
				g[d[a[i].S-1]].PB(i);
			}
		for (int i : row[r])
			d[a[i].S] = 0;
	}
	RP1(c,m) {
		for (int i : col[c])
			d[a[i].F] = i;
		for (int i : col[c])
			if (d[a[i].F-1]) {
				g[i].PB(d[a[i].F-1]);
				g[d[a[i].F-1]].PB(i);
			}
		for (int i : col[c])
			d[a[i].F] = 0;
	}
	fill_n(d+1,k+n+m,inf);
	queue<int> q[2];
	d[lu] = 0;
	q[0].push(lu);
	for (int w = 0; SZ(q[0]) || SZ(q[1]); ++w) {
		while (SZ(q[1])) {
			int u = q[1].front();
			q[1].pop();
			if (u > k + n) {
				int c = u - (k + n);
				REP1(i,c-1,c+1)
					if (1 <= i && i <= m)
						for (int v : col[i])
							if (w < d[v]) {
								d[v] = w;
								q[0].push(v);
							}
			} else {
				int r = u - k;
				REP1(i,r-1,r+1)
					if (1 <= i && i <= n)
						for (int v : row[i])
							if (w < d[v]) {
								d[v] = w;
								q[0].push(v);
							}
			}
		}
		while (SZ(q[0])) {
			int u = q[0].front();
			q[0].pop();
			for (int v : g[u])
				if (w < d[v]) {
					d[v] = w;
					q[0].push(v);
				}
			REP1(r,a[u].F-1,a[u].F+1)
				if (1 <= r && r <= n && w + 1 < d[k+r]) {
					d[k+r] = w + 1;
					q[1].push(k+r);
				}
			REP1(c,a[u].S-1,a[u].S+1)
				if (1 <= c && c <= m && w + 1 < d[k+n+c]) {
					d[k+n+c] = w + 1;
					q[1].push(k+n+c);
				}
		}

	}
	int ans = min(d[k+n],d[k+n+m]);
	if (rb)
		ans = min(ans, d[rb]);
	PL(ans == inf ? -1 : ans);
}
