#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,a,b) for (int i = (a), __e = (b); i < __e; ++i)
#define RP(i,n) REP(i,0,n)
#define CZ(a,n) memset((a), 0, (n) * sizeof(*(a)))
inline bool RD(void) {return true;}
inline bool RD(int & a) {return scanf("%d", &a) == 1;}
template <typename T, typename ... TT>
inline bool RD(T & a, TT & ... b) {return RD(a) && RD(b...);}

const int maxn = 2.28e6;
int nxt[maxn], pre[maxn], q[maxn];
inline void link(int a, int b)
{
	nxt[a] = b;
	pre[b] = a;
}
inline void ins_b(int a, int b) // b after a
{
	link(b, nxt[a]);
	link(a, b);
}
inline void ins_f(int a, int b) // b before a
{
	link(pre[a], b);
	link(b, a);
}
inline void pop(int a)
{
	link(pre[a], nxt[a]);
}
int main()
{
	int T;
	RD(T);
	while (T--) {
		int n, m, a0, tp = 0;
		ll ans = 0;
		RD(n,m,a0);
		CZ(nxt+1,n);
		CZ(pre+1,n);
		while (m--) {
			int k,a,b,c;
			RD(k,a,b,c);
			switch (k) {
			case 1:
				if (c == 1)
					ins_f(b, a);
				else
					ins_b(b, a);
				break;
			case 2:
				link(pre[a], nxt[b]);
				link(pre[c], a);
				link(b, c);
				break;
			case 3:
				for (int v; a && b; b--, a = v) {
					v = c == 1 ? pre[a] : nxt[a];
					q[tp++] = a;
					pop(a);
				}
				ans += b;
				break;
			}
		}
		printf("%lld\n", ans);
		RP(i,n)
			printf("%d\n", q[i]);
	}
}
