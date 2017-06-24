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
template<char sep = ' ',char end = '\n',typename T, typename ...  TT>
void PL(const T a, const TT ...  b) {PT(a); if (sizeof...(b) && 
sep) PT(sep); PL<sep,end>(b...);}

/* Good Luck && Have Fun ! */
const int N = 55,inf = 5566,dr[]={-1,0,0,1},dc[]={0,-1,1,0};
int n,m,k;
vector<char> c;
char v[4];
bool w[26];
char g[N][N];
int d[N][N];
int vis[N][N], vc;
pii s,t;
int al = inf - 1;
bool fl;
string ans;
bool ok(pii x)
{
	if (!(0 <= x.F && x.F < n && 0 <= x.S && x.S < m))
		return 0;
	char ch = g[x.F][x.S];
	RP(i,k)
		if (ch == v[i])
			return 1;
	return ch == 'S' || ch == 'T';
}
void bfs()
{
	RP(i,n)
		fill_n(d[i],m,inf);
	queue<pii> q;
	q.push(t);
	d[t.F][t.S] = 0;
	while (SZ(q)) {
		pii x = q.front();
		q.pop();
		RP(i,4) {
			pii y(x.F+dr[i],x.S+dc[i]);
			if (ok(y) && d[y.F][y.S] == inf) {
				d[y.F][y.S] = d[x.F][x.S] + 1;
				q.push(y);
			}
		}
	}
	if (d[s.F][s.S] > al)
		return;
	al = d[s.F][s.S];
	string ca;
	vector<pii> li[2];
	li[al&1^1] = {s};
	PER(i,al,1) {
		++vc;
		ca += v[k-1];
		for (auto x : li[i&1]) {
			RP(j,4) {
				pii y(x.F+dr[j],x.S+dc[j]);
				if (ok(y) && d[y.F][y.S] == i && vis[y.F][y.S] < vc) {
					vis[y.F][y.S] = vc;
					char ch = g[y.F][y.S];
					if (ch < ca.back()) {
						ca.back() = ch;
						li[i&1^1].clear();
					}
					if (ch == ca.back())
						li[i&1^1].PB(y);
				}
			}
		}
		li[i&1].clear();
	}
	if (!fl || SZ(ans) > SZ(ca) || ans > ca) {
		ans = ca;
		fl = 1;
	}
}
void dfs(int i,int j)
{
	if (i == k) {
		RP(u,k)
			bfs();
		return;
	}
	for ( ; SZ(c) - j >= k - i; j++) {
		v[i] = c[j];
		dfs(i+1,j+1);
	}
}
int main()
{
	RD(n,m,k);
	RP(i,n) {
		RD(g[i]);
		RP(j,m)
			if (g[i][j] == 'S')
				s = {i,j};
			else if (g[i][j] == 'T')
				t = {i,j};
			else
				w[g[i][j]-'a'] = 1;
	}
	RP(i,26)
		if (w[i])
			c.PB(i+'a');
	if (SZ(c) <= k) {
		k = SZ(c);
		RP(i,k)
			v[i] = c[i];
		bfs();
	} else {
		dfs(0,0);
	}
	if (!fl)
		cout << "-1\n";
	else
		cout << ans << '\n';
}
