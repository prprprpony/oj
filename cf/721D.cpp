#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2.25e5;
typedef pair<ll, int> pli;
#define A first
#define I second
ll a[maxn];
int main()
{
	int n, k, x;
	scanf("%d%d%d", &n, &k, &x);
	int neg = 0;
	int m = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lld", a + i);
		if (a[i] < 0)
			++neg;
		if (abs(a[i]) < abs(a[m]))
			m = i;
	}
	if (!(neg & 1)) {
		ll j = min(abs(a[m]) / x + (a[m] < 0 && !(a[m] % x) ? 0 : 1), 1LL * k);
		a[m] += (a[m] < 0 ? 1 : -1) * j * x;
		k -= j;
	}
	if (k) {
		priority_queue<pli, vector<pli>, greater<pli> > pq;
		for (int i = 0; i < n; ++i)
			pq.push({abs(a[i]), i});
		while (k--) {
			auto v = pq.top();
			pq.pop();
			v.A += x;
			a[v.I] = (a[v.I] < 0 ? -1 : 1) * v.A;
			pq.push(v);
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%lld%c", a[i], i == n-1 ? '\n' : ' ');
}
