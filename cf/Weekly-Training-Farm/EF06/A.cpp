#include <cstdio>
#include <utility>
#define X first
#define Y second
using namespace std;
const int maxn = 1e5 + 426;
const int maxq = 1 << 30;
typedef pair<int,int> pii;
int n, m;
pii lr[maxn];
int q[maxn];
int t[4 * maxn];
void set(int o, int l, int r, int i, int j, int v)
{
	if (r < i || l > j)
		return;
	if (i <= l && r <= j) {
		t[o] |= v;
		return;
	}
	int m = (l + r) / 2;
	set(o+o+1, l, m, i, j, v);
	set(o+o+2, m+1, r, i, j, v);
	t[o] |= (t[o+o+1] & t[o+o+2]);
}
int qry(int o, int l, int r, int i, int j)
{
	if (r < i || l > j)
		return maxq - 1;
	if (i <= l && r <= j)
		return t[o];
	int m = (l + r) / 2;
	return t[o] | (qry(o+o+1, l, m, i, j) & qry(o+o+2, m+1, r, i, j));
}
void print(int o, int l, int r, int v)
{
	v |= t[o];
	if (l == r) {
		printf("%d%c", v, r == n ? '\n' : ' ');
		return;
	}
	int m = (l + r) / 2;
	print(o+o+1, l, m, v);
	print(o+o+2, m+1, r, v);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &lr[i].X, &lr[i].Y, q + i);
		set(0, 1, n, lr[i].X, lr[i].Y, q[i]);
	}
	for (int i = 0; i < m; ++i)
		if (qry(0, 1, n, lr[i].X, lr[i].Y) != q[i]) {
			puts("NO");
			return 0;
		}
	puts("YES");
	print(0, 1, n, 0);
}
