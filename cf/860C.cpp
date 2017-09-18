#include <bits/stdc++.h>
using namespace std;
// nichijou
#define REP(i,a,b) for (int i(a); i < (b); ++i)
#define RP(i,n) REP(i,0,n)
#define PER(i,a,b) for(int i((a)-1); i >= (b); --i)
#define PR(i,n) PER(i,n,0)
#define REP1(i,a,b) REP(i,a,(b)+1)
#define RP1(i,n) REP1(i,1,n)
#define PER1(i,a,b) PER(i,(a)+1,b)
#define PR1(i,n) PER1(i,n,1)
#define DO(n) RP(__i,n)
template<class T>
void cmax(T & a, T b) {a = max(a, b);}
template<class T>
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
#define SZ(a) ((int)(a).size())
#define ALL(a) begin(a), end(a)
#define CLR(a) (a).clear()
#define BK(a) ((a).back())
#define FT(a) ((a).front())
#define DB(a) (a).pop_back()
#define DF(a) (a).pop_front()
#define PB push_back
#define EB emplace_back

/* I gave you my heart and then you turned around. */
void _BG(const char * s) {}
template<class T, class ... TT>
void _BG(const char * s,T a, TT...b)
{
	for (int c = 0; *s && (c || *s != ','); ++s) {
		cerr<<*s;
		for (char x : "([{") c += *s == x;
		for (char x : ")]}") c -= *s == x;
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
bool RD() {return 1;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(int & a) {return scanf("%d", &a) == 1;}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}

template<class T, class ... TT>
bool RD(T & a, TT & ... b) {return RD(a) && RD(b...);}

/* Do princesses dream of magic sheep? */
#define DR(T,...) T __VA_ARGS__; RD(__VA_ARGS__)
#define RI(...) DR(int,__VA_ARGS__)

/* For it's time for you to fulfill your output. */
void PT(const char & a) {putchar(a);}
void PT(char const * const & a) {fputs(a, stdout);}
void PT(const double & a) {printf("%.16f", a);}
void PT(const int & a) {printf("%d", a);}
void PT(const ll & a) {printf("%lld", a);}

/* The line will last forever! */
template<char s = ' ', char e = '\n'>
void PL() {if (e) PT(e);}
template<char s = ' ', char e = '\n', class T, class ... TT>
void PL(const T & a, const TT & ... b)
{PT(a); if (sizeof...(b) && s) PT(s); PL<s,e>(b...);}

/* Good Luck && Have Fun ! */
const int N = 1e5 + 87;
int num(char * s)
{
	if (s[0] == '0')
		return -1;
	int v = 0;
	for (int i = 0; s[i]; ++i) {
		if (!isdigit(s[i]))
			return -1;
		v = 10 * v + s[i] - '0';
	}
	return v;
}

char s[N][7];
int t[N], va[N];

bool vis[N];
set<int> cn[2], us;
vi q[4];
int ans;
string opt;
string tos(int x)
{
	string y;
	do {
		y += (char)(x%10+'0');
	} while (x/=10);
	reverse(ALL(y));
	return y;
}
string tos(const char * x)
{
	return string(x);
}
template<class T,class U,class V>
void prt(T x, U  y, V z)
{
	++ans;
	opt += tos(x);
	opt += ' ';
	opt += tos(y);
	opt += ' ';
	opt += tos(z);
	opt += '\n';
}
int main()
{
	RI(n);
	int e = 0;
	RP(i,n) {
		RD(s[i], t[i]);
		e += t[i];
	}
	RP1(i,n)
		cn[i<=e].insert(i);
	RP(i,n) {
		int v = va[i] = num(s[i]);
		if (v < 0 || v > n) {
			q[t[i]].PB(i);
			if (v > n)
				us.insert(v);
			continue;
		}
		if (t[i]) {
			if (v <= e) {
				cn[1].erase(v);
			} else {
				cn[0].erase(v);
				q[3].PB(v);
			}
		} else {
			if (v > e) {
				cn[0].erase(v);
			} else {
				cn[1].erase(v);
				q[2].PB(v);
			}
		}
	}
	int flag = -1;
	if (SZ(q[3]) && SZ(q[2]) && !SZ(cn[0]) && !SZ(cn[1])) {
		int k = 999999;
		while (us.count(k))
			--k;
		int v = q[3].back();
		q[3].pop_back();
		prt("move", v, k);
		cn[0].insert(v);
		flag = k;
	}
	while ((SZ(q[3]) && SZ(cn[1])) || (SZ(q[2]) && SZ(cn[0]))) {
		if (SZ(q[3]) && SZ(cn[1])) {
			int v = q[3].back();
			q[3].pop_back();
			prt("move", v, *(cn[1].begin()));
			cn[0].insert(v);
			cn[1].erase(begin(cn[1]));
		} else {
			int v = q[2].back();
			q[2].pop_back();
			prt("move", v, *(cn[0].begin()));
			cn[1].insert(v);
			cn[0].erase(begin(cn[0]));
		}
	}
	if (flag > 0) {
		prt("move", flag, *(cn[1].begin()));
		cn[1].erase(begin(cn[1]));
	}
	while (SZ(q[0])) {
		int v = q[0].back();
		q[0].pop_back();
		prt("move", s[v], *(cn[0].begin()));
		cn[0].erase(begin(cn[0]));
	}
	while (SZ(q[1])) {
		int v = q[1].back();
		q[1].pop_back();
		prt("move", s[v], *(cn[1].begin()));
		cn[1].erase(begin(cn[1]));
	}
	PL(ans);
	PT(opt.c_str());
}
