#include <bits/stdc++.h>
using namespace std;
const int maxn = 2.28e5;
int cnt[maxn];
set<int> C;
int c, n;
int main()
{
	scanf("%d%d", &c, &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		if (x == c)
			goto no_answer;
		++cnt[x];
	}
	for (int i = 1; i < c; ++i)
		if (cnt[i])
			C.insert(i);
	for (int i = 2; i < c; ++i) {
		if (cnt[i]++ == 0)
			C.insert(i);
		int s = c, up = c;
		while (s) {
			auto p = C.upper_bound(up);
			if (p != C.begin())
				--p;
			else
				break;
			int x = *p;
			s -= min(s / x, cnt[x]) * x;
			up = min(s, x - 1);
		}
		if (s) {
			printf("%d\n", i);
			return 0;
		}
		if (--cnt[i] == 0)
			C.erase(i);
	}
no_answer:
	puts("Greed is good");
}
