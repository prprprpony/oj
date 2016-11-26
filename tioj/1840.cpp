#include <bits/stdc++.h>
using namespace std;
// iteration
#define CONC(a,b) a ## b
#define CONC_M(a,b) CONC(a,b)
#define __REP(i,s,j,e,nxt) for (auto i = (s), j = (e); i != j; i nxt)
#define _REP(i,s,e,nxt) __REP(i,s,CONC_M(__e,__LINE__),e,nxt)
#define REP(i,s,e) _REP(i,s,e, ++)
#define RP(i,n) REP(i,0,n)
#define PER(i,s,e) _REP(i,s,e, --)
#define PR(i,n) PER(i,n-1,-1)
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

/* Good Luck && Have Fun ! */

const int N = 55665, M = 11221, INF = 0x7fffffff;
const int EN = 2 * (N + M);
int n,m;
int a[N];
struct event
{
	int t; // 1: add, -1:remove, 0: query
	int l, r, k;
	int v;
	event() {}
	event(int _t, int i, int j, int _k, int _v) : t(_t), l(i), r(j), k(_k), v(_v) {}
} e[EN], tmp[EN];
int ans[M];
int top, qt;
bool is7122[M];

int B[N];
void add(int i, int v)
{
	for ( ; i <= n; i += i & -i)
		B[i] += v;
}
int qry(int i)
{
	int ret = 0;
	for ( ; i; i ^= i & -i)
		ret += B[i];
	return ret;
}
int qry(int i, int j)
{
	return qry(j) - qry(i-1);
}
void DC(int vl, int vr, int el, int er)
{
	if (el >= er)
		return;
	if (vl == vr) {
		REP(i,el,er)
			if (!e[i].t)
				ans[e[i].v] = vl;
		return;
	}
	int vm = vl + ((vr + 0LL - vl) >> 1);
	int em = el, tp = 0;
	REP(i,el,er)
		if (!e[i].t) {
			int v = qry(e[i].l, e[i].r);
			if (v < e[i].k) {
				e[i].k -= v;
				tmp[tp++] = e[i];
			} else {
				e[em++] = e[i];
			}
		} else if (e[i].v <= vm) {
			add(e[i].l, e[i].t);
			e[em++] = e[i];
		} else {
			tmp[tp++] = e[i];
		}
	RP(i,tp)
		e[em+i] = tmp[i];
	DC(vl,vm,el,em);
	DC(vm+1,vr,em,er);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	DO(T) {
		top = qt = 0;
		cin >> n >> m;
		REP(i,1,n+1) {
			cin >> a[i];
			e[top++] = event(1,i,i,0,a[i]);
		}
		DO(m) {
			int c;
			cin >> c;
			if (c == 1) {
				int i,j,k;
				cin >> i >> j >> k;
				is7122[qt] = false;
				e[top++] = event(0,i,j,k,qt++);
			} else if (c == 2) {
				int i,w;
				cin >> i >> w;
				e[top++] = event(-1,i,0,0,a[i]);
				e[top++] = event(1,i,0,0,a[i]=w);
			} else {
				int x,v;
				cin >> x >> v;
				is7122[qt++] = true;
			}
		}
		REP(i,1,n+1)
			e[top++] = event(-1,i,0,0,a[i]);
		DC(0,INF,0,top);
		RP(i,qt)
			if (is7122[i])
				cout << "7122\n";
			else
				cout << ans[i] << '\n';
	}
}
