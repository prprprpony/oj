#include <cstdio>
#include <utility>
#include <algorithm>
#include <functional>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
const int maxn = 1<<10;
pii a[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &a[i].Y, &a[i].X);
	sort(a, a + n, greater<pii>());
	int ans = 0;
	int s = 0;
	for (int i = 0; i < n; ++i) {
		s += a[i].Y;
		ans = max(s + a[i].X, ans);
	}
	printf("%d\n", ans);
}
