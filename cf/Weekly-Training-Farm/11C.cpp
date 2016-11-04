#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 42;
int ans[maxn];
int main()
{
	deque<int> s;
	for (int i = 1; i < maxn; ++i) {
		int x = i;
		vector<int> d;
		while (x) {
			d.push_back(x % 10);
			x /= 10;
		}
		while (d.size()) {
			s.push_back(d.back());
			d.pop_back();
			if (s.size() > 6)
				s.pop_front();
			int v = 0;
			for (int k = s.size() - 1, p = 1; k >= 0; --k, p *= 10) {
				v += s[k] * p;
				if (v >= maxn)
					break;
				if (!ans[v])
					ans[v] = i;
			}
		}
	}
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
}
