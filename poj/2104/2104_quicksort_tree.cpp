#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 64;
const int maxd = 18;
int sorted[maxn];
int t[maxd][maxn];
int lcnt[maxd][maxn];
void build(int d, int l, int r)
{
	if (l == r)
		return;
	int m = (l + r) / 2;
	int me = sorted[m];
	int lp = l, rp = m + 1;
	int lm = 0;
	for (int i = m; i >= l && sorted[i] == me; --i, ++lm);
	int lc = 0;
	for (int i = l; i <= r; ++i) {
		if (t[d][i] < me || (t[d][i] == me && lm-- > 0)) {
			t[d+1][lp++] = t[d][i];
			++lc;
		} else {
			t[d+1][rp++] = t[d][i];
		}
		lcnt[d][i] = lc;
	}
	build(d+1,l,m);
	build(d+1,m+1,r);
}
int kth(int d, int l, int r, int i, int j, int k)
{
	if (l == r)
		return t[d][l];
	int m = (l + r) / 2;
	int ilc = i > l ? lcnt[d][i-1] : 0;
	int jlc = lcnt[d][j];
	int lc = jlc - ilc;
	if (lc >= k) {
		return kth(d+1, l, m, l + ilc, l + jlc - 1, k);
	} else {
		int irc = (i - 1) - l + 1 - ilc;
		int jrc = j - l + 1 - jlc;
		return kth(d+1, m+1, r, m + 1 + irc, m + 1 + jrc - 1, k - lc);
	}
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", t[0] + i);
	copy(t[0] + 1, t[0] + n + 1, sorted + 1);
	sort(sorted + 1, sorted + n + 1);
	build(0, 1, n);
	while (m--) {
		int i, j, k;
		scanf("%d%d%d", &i, &j, &k);
		printf("%d\n", kth(0, 1, n, i, j, k));
	}
}
