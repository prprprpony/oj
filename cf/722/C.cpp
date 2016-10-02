#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1.12e5;
int a[maxn], b[maxn];
ll s[maxn];
int p[maxn];
bool ok[maxn];
ll ans[maxn];
int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
inline void meld(int x, int y)
{
	x = find(x), y = find(y);
	p[x] = y;
	s[y] += s[x];
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for (int i = 1; i <= n; ++i)
		scanf("%d", b + i);
	for (int i = n; i > 1;--i) {
		ok[b[i]] = true;
		p[b[i]] = b[i];
		s[b[i]] = a[b[i]];
		if (ok[b[i] - 1])
			meld(b[i]-1, b[i]);
		if (ok[b[i] + 1])
			meld(b[i]+1, b[i]);
		ans[i-1] = max(ans[i], s[find(b[i])]);
	}
	for (int i = 1; i <= n; ++i)
		printf("%lld\n", ans[i]);
}
