#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
#define SZ(a) ((int)(a.size()))

template <typename T>
T cmin(T & a, T b) {return a = min(a,b);}
template <typename T>
T cmax(T & a, T b) {return a = max(a,b);}

#define REP(i,a,b) for (int i(a),__e(b);i<__e;++i)
#define RP(i,n) REP(i,0,n)
#define DO(n) RP(__i,n)

bool RD(void) {return 1;}
bool RD(int & a) {return scanf("%d", &a) == 1;}
template<typename T, typename ... TT>
bool RD(T & a, TT & ... b) {return RD(a) && RD(b...);}
#define DRI(a) int a; RD(a)
#define DRII(a,b) DRI(a); DRI(b)
#define DRIII(a,b,c) DRI(a); DRII(b,c)
#define DRIIII(a,b,c,d) DRI(a); DRIII(b,c,d)

void PT(const char a) {putchar(a);}
void PT(const char * a) {fputs(a,stdout);}
void PT(const int a) {printf("%d",a);}

void PL(void) {PT('\n');}
template<typename T, typename ... TT>
void PL(const T a, const TT ... b) {PT(a);if (sizeof...(b)) PT(' '); PL(b...);}
/**************************/
const int N = 1087;
int a[N], b[N], dp[N][N];
int main()
{
#ifndef PP
	freopen("nocross.in","r",stdin);
	freopen("nocross.out","w",stdout);
#endif
	DRI(n);
	REP(i,1,n+1) RD(a[i]);
	REP(i,1,n+1) RD(b[i]);
	REP(i,1,n+1)
		REP(j,1,n+1) {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			if (abs(a[i] - b[j]) <= 4)
				cmax(dp[i][j], 1 + dp[i-1][j-1]);
		}
	PL(dp[n][n]);
}
