#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second

#define REP(i,a,b) for (int i(a),__e(b);i<__e;++i)
#define RP(i,n) REP(i,0,n)
bool RD(void) {return 1;}
bool RD(int & a) {return scanf("%d", &a) == 1;}
template<typename T, typename ... TT>
bool RD(T & a, TT & ... b) {return RD(a) && RD(b...);}
#define DRI(a) int a; RD(a)
#define DRII(a,b) DRI(a); DRI(b)

void PT(const char a) {putchar(a);}
void PT(const char * a) {fputs(a,stdout);}
void PT(const int a) {printf("%d",a);}

void PL(void) {PT('\n');}
template<typename T, typename ... TT>
void PL(const T a, const TT ... b) {PT(a);if (sizeof...(b)) PT(' '); PL(b...);}
/**************************/
const int N = 2.28e4;
int t[N];
pii a[N];
int main()
{
#ifndef PP
	freopen("helpcross.in","r",stdin);
	freopen("helpcross.out","w",stdout);
#endif
	DRII(c,n);
	RP(i,c) RD(t[i]);
	sort(t,t+c);
	RP(i,n) {RD(a[i].S, a[i].F); a[i].S = a[i].F - a[i].S;}
	sort(a,a+n);
	multiset<int> s;
	int ans = 0;
	for (int i = 0, j = 0; j < n; ++j) {
		while (i < c && t[i] <= a[j].F)
			s.insert(t[i++]);
		int b = a[j].F - a[j].S;
		auto it = s.lower_bound(b);
		if (it != s.end()) {
			++ans;
			s.erase(it);
		}
	}
	PL(ans);
}
