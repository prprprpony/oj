#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;
const int maxn = 1e5 + 426;
int d[maxn];
int l[maxn];
int r[maxn];
int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	int last;
	scanf("%d", &last);
	for (int i = 1; i < n; ++i) {
		int a;
		scanf("%d", &a);
		d[i] = abs(a - last);
		last = a;
	}
	{
		stack<int> st;
		for (int i = 1; i < n; ++i) {
			while (st.size() && d[st.top()] < d[i])
				st.pop();
			l[i] = st.size() ? st.top() : 0;
			st.push(i);
		}
	}
	{
		stack<int> st;
		for (int i = n - 1; i > 0; --i) {
			while (st.size() && d[st.top()] <= d[i])
				st.pop();
			r[i] = st.size() ? st.top() : n;
			st.push(i);
		}
	}
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		--y;
		long long ans = 0;
		for (long long i = x; i <= y; ++i)
			ans += d[i] * (i - max(l[i], x - 1)) * (min(r[i], y + 1) - i);
		printf("%lld\n", ans);
	}
}
