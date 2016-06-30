#include <cstdio>
#include <cstring>
using namespace std;
bool vis[7];
int log7(int x)
{
	int p = 0;
	do {
		++p;
		x /= 7;
	} while (x);
	return p;
}
bool ok(int x, int i)
{
	for ( ; i > 0; --i, x /= 7)
		if (vis[x % 7])
			return false;
		else
			vis[x % 7] = true;
	return true;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int a = log7(n - 1), b = log7(m - 1);
	int ans = 0;
	if (a + b <= 7) {
		for (int h = 0; h < n; ++h)
			for (int i = 0; i < m; ++i) {
				memset(vis, 0, sizeof(vis));
				if (ok(h, a) && ok(i, b))
					++ans;
			}
	}
	printf("%d\n", ans);
}

