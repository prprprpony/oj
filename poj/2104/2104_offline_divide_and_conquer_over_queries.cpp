#include <cstdio>
#include <algorithm>
#define REP(i,s,e) for (int i = (s), __e = (e); i != __e; ++i) 
using namespace std;
const int maxn = 1.12e5, maxm = 5566, inf = 1e9;
int a[maxn], idx[maxn], ans[maxm], tmpg[maxn];
struct Qry
{
	int i, l, r, k, cur;
} q[maxm], qtmpg[maxm];
inline int mid(int l, int r) {return l + ((r - l) >> 1);}
void DC(int ql, int qr, int il, int ir, int L, int R)
{
	if (ql == qr)
		return;
	if (L == R) {
		REP(i,ql,qr)
			ans[q[i].i] = L;
		return;
	}
	int M = mid(L, R);
	int tpl = il, tpg = 0;
	REP(i,il,ir)
		if (a[idx[i]] <= M)
			idx[tpl++] = idx[i];
		else
			tmpg[tpg++] = idx[i];
	REP(i,0,tpg)
		idx[tpl + i] = tmpg[i];
	int qi = ql, topqg = 0;
	REP(i,ql,qr) {
		int num = upper_bound(idx + il, idx + tpl, q[i].r) - lower_bound(idx + il, idx + tpl, q[i].l);
		if (q[i].cur + num < q[i].k) {
			q[i].cur += num;
			qtmpg[topqg++] = q[i];
		} else {
			q[qi++] = q[i];
		}
	}
	REP(i,0,topqg)
		q[qi + i] = qtmpg[i];
	DC(ql, qi, il, tpl, L, M);
	DC(qi, qr, tpl, ir, M+1, R);
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i,1,n+1) {
		scanf("%d", a + i);
		idx[i] = i;
	}
	REP(i,0,m) {
		q[i].i = i;
		scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].k); 
	}
	DC(0, m, 1, n + 1, -inf, inf);
	REP(i,0,m)
		printf("%d\n", ans[i]);
}
