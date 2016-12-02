#include <bits/stdc++.h>
using namespace std;
// daily life
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
#define DB(a) a.pop_back()
#define DF(a) a.pop_front()
#define PB push_back
#define EB emplace_back

// input
bool RD(void) {return true;}
bool RD(int & a) {return scanf("%d", &a) == 1;}
bool RD(ll & a) {return scanf("%lld", &a) == 1;}
bool RD(double & a) {return scanf("%lf", &a) == 1;}
bool RD(char & a) {return scanf(" %c", &a) == 1;}
bool RD(char * a) {return scanf("%s", a) == 1;}
template<typename T, typename ... TT>
bool RD(T & a, TT & ...  b) {return RD(a) && RD(b...);}

/* Good Luck && Have Fun ! */

const int p[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
const int sp = sizeof(p) / sizeof(int);
const int maxn = 100, mv = 60, mem = 1 << sp;
int n;
int sev[mv];
int a[maxn];
int dp[maxn][mem];
int ch[maxn][mem];
int ans[maxn];
int main()
{
	REP(i,2,mv) 
		RP(j,sp)
			if (i % p[j] == 0) 
				sev[i] |= 1 << j;
	RD(n);
	memset(dp, 0x3f, n * mem * sizeof(int));
	RP(i,n)
		RD(a[i]);
	REP(k,1,mv) 
		if (abs(k - a[0]) < dp[0][sev[k]]) {
			dp[0][sev[k]] = abs(k - a[0]);
			ch[0][sev[k]] = k;
		}
	REP(i,1,n)
		REP(k,1,mv) {
			int S = ~sev[k] & ((1 << sp) - 1);
			for (int s = S; ; s = (s - 1) & S) {
				if (dp[i-1][s] + abs(k - a[i]) < dp[i][sev[k] | s]) {
					dp[i][sev[k] | s] = dp[i-1][s] + abs(k - a[i]);
					ch[i][sev[k] | s] = k;
				}
				if (!s)
					break;
			}
		}
	pii s(8787, 8787);
	RP(S,mem)
		cmin(s, {dp[n-1][S], S});
	int S = s.S;
	PR(i,n) {
		ans[i] = ch[i][S];
		S ^= sev[ans[i]];
	}
	RP(i,n)
		printf("%d%c", ans[i], " \n"[i == n - 1]);
}
