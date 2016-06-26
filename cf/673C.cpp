#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 5566;
int t[maxn];
int cnt[maxn];
int ans[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", t + i);
	for (int s = 1; s <= n; ++s) {
		memset(cnt + 1, 0, n * sizeof(int));
		for (int i = s, m = t[s]; i <= n; ++i) {
			++cnt[t[i]];
			if (cnt[t[i]] > cnt[m] || (cnt[t[i]] == cnt[m] &&  t[i] < m))
				m = t[i];
			++ans[m];
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%d%c", ans[i], i != n ? ' ' : '\n');
}
