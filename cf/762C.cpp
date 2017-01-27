#include <bits/stdc++.h>
using namespace std;
// nichijou
#define REP(i,s,e) for (int i = (s), __e = (e); i < __e; ++i)
#define RP(i,n) REP(i,0,n)
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

/* reading input is now 20% cooler */
bool RD(void) {return true;}
bool RD(int & a) {return scanf("%d", &a) == 1;}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
template<typename T, typename ... TT>
bool RD(T & a, TT & ...  b) {return RD(a) && RD(b...);}

/* For it's time for you to fulfill your output */
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
const int N = 1.12e5;
char a[N], b[N];
int p[N], q[N];
int main()
{ 
	RD(a,b);
	int n=strlen(a),m=strlen(b);
	int i,j;
	for (i = j = 0; i < m && j < n; ++j)
		if (a[j] == b[i])
			p[i++] = j;
	int x,y;
	for (x = m - 1, y = n - 1; x >= 0 && y >= 0; --y)
		if (a[y] == b[x])
			q[x--] = y;
	if (i == 0 && x == m - 1) {
		PL('-');
		return 0;
	}
	int mv = N,aa,ab;
	for (int k = i - 1,l = x + 1; k >= 0 && l > x; --k) {
		while (l < m && p[k] > q[l])
			++l;
		while (l - 1 > x && p[k] < q[l-1])
			--l;
		if (l < m && l > k && q[l] > p[k] && l - k - 1 < mv) {
			mv = l - k - 1;
			aa = k+1;
			ab = l;
		}
	}
	if (m - i <= min(x + 1, mv)) {
		b[i] = '\0';
		PL(b);
		return 0;
	} else if (x + 1 <= min(m - i, mv)) {
		PL(b + x + 1);
		return 0;
	}
	char c = b[aa];
	b[aa] = '\0';
	PT(b);
	b[aa] = c;
	PL(b + ab);
}
