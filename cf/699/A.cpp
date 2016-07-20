#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 2.12e5;
const int inf = 2e9;
char d[maxn];
int x[maxn];
int main()
{
	int n;
	scanf("%d ", &n);
	fgets(d, sizeof(d), stdin);
	for (int i = 0; i < n; ++i)
		scanf("%d", x + i);
	int ans = inf;
	for (int i = 1; i < n; ++i)
		if (d[i - 1] == 'R' && d[i] == 'L')
			ans = min(ans, (x[i] - x[i-1]) / 2);
	printf("%d\n", ans < inf ? ans : -1);
}
