#include <bits/stdc++.h>
using namespace std;
// iteration
#define CONC(a,b) a ## b
#define CONC_M(a,b) CONC(a,b)
#define __REP(i,s,j,e,nxt) for (auto i = (s), j = (e); i != j; i nxt)
#define _REP(i,s,e,nxt) __REP(i,s,CONC_M(__e,__LINE__),e,nxt)
#define REP(i,s,e) _REP(i,s,e, ++)
#define PER(i,s,e) _REP(i,s,e, --)
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

// Good Luck && Have Fun !

// #define FASTIO

#ifdef FASTIO
// under construction
// return number of arguements read
int RI() {return 0;}
int RI(char * a) {return scanf("%s", a) == 1;}
int RI(double & a) {return scanf("%f", &a) == 1;}
// read integers only
template<typename T>
int RI(T & a)
{
	int c;
	int s = 1;
	while (!((c = getchar()) == '-' || isdigit(c) || c == EOF));
	if (c == EOF)
		return 0;
	if (c == '-') {
		s = -1;
		c = getchar();
	}
	a = 0;
	do {
		a = 10 * a + s * (c - '0');
	} while (isdigit(c = getchar()));
	return 1;
}
template<typename T, typename... Args>
int RI(T & a, Args & ... args) {return RI(a) ? 1 + RI(args...) : 0;}
// python style print 

// POD integers up to __int128
template<typename T>
void __PI(T a)
{
	static const int __W = 42;
	static char d[__W];
	int i = __W - 1;
	int s = a < 0 ? -1 : 1;
	do {
		d[--i] = s * (a % 10) + '0';
	} while (a /= 10);
	if (s < 0)
		d[--i] = '-';
	fputs(d + i, stdout);
}
template<char sep>
void __PSI() {}
template<char sep, typename T>
void __PSI(const T & a) {putchar(sep), __PI(a);}
template<char sep, typename T, typename... Args>
void __PSI(const T & a, const Args & ... args) {__PSI<sep, T>(a), __PSI<sep, Args...>(args...);}
template<char sep = ' ', char end = '\n', typename T, typename... Args>
void PI(const T & a, const Args & ... args) {__PI(a), __PSI<sep, Args...>(args...), putchar(end);}
#endif

inline void init()
{
#ifdef FASTIO

#else
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
}

const int dr[] = {1, 0, 0, -1};
const int dc[] = {0, -1, 1, 0};
const int maxn = 565, maxm = 1024, inf = 1e9;
int g[maxn][maxn];
int d[maxn][maxn];
int n, m;
inline bool ok(int r, int c) {return 0 <= r && r < n && 0 <= c && c < n;}
int dp(int i, int j)
{
	if (d[i][j] != inf)
		return d[i][j];
	bool low = true;
	REP(k,0,4) {
		int r = i + dr[k];
		int c = j + dc[k];
		if (ok(r,c) && g[r][c] < g[i][j]) {
			low = false;
			d[i][j] = min(d[i][j], 1 + dp(r, c));
		}
	}
	if (low)
		d[i][j] = 0;
	return d[i][j];
}
int main()
{
	init();
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		REP(i,0,n)
			REP(j,0,n)
				cin >> g[i][j];
		REP(i,0,n) fill_n(d[i], n, inf);
		int cnt = 0, ans = 0;
		REP(i,0,n) 
			REP(j,0,n) {
				int v = dp(i,j);
				ans = max(ans, v);
				if (!v)
					++cnt;
			}
		if (cnt > m)
			cout << "Impossible\n";
		else
			cout << ans << '\n';
	}
}
