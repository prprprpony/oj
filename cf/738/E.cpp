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

const int maxn = 2.28e5;
int a[maxn];
int dep[maxn];
int main()
{
	int n,s, ans = 0;
	scanf("%d%d", &n, &s);
	--s;
	REP(i,0,n)
		scanf("%d", a + i);
	if (a[s])
		a[s] = 0, ++ans;
	REP(i,0,n)
		++dep[a[i]];
	int cnt = dep[0] - 1;
	dep[0] = 1;
	ans += cnt;
	int j = n - 1;
	REP(i,1,n)
		if (!dep[i]) {
			if (!cnt) {
				for (; j > i; --j)
					if (dep[j]) {
						--dep[j];
						++cnt;
						++ans;
						break;
					}
				if (j == i)
					break;
			}
			--cnt;
		}
	printf("%d\n", ans);
}
