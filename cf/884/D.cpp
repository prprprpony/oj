#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SZ(a) ((int)(a).size())
#define PB push_back
/**/
const int N = 200000 + 87;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	for (int i = 1; i <= n; ++i) {
		ll a;
		cin >> a;
		pq.push(a);
	}
	ll ans = 0;
	int k = n;
	while (k >= 3)
		k = k/3 + k%3;
	if (k == 2) {
		ll a = pq.top();
		pq.pop();
		a += pq.top();
		pq.pop();
		ans += a;
		pq.push(a);
	}
	while (SZ(pq) > 1) {
		ll a = pq.top();
		pq.pop();
		a += pq.top();
		pq.pop();
		a += pq.top();
		pq.pop();
		ans += a;
		pq.push(a);
	}
	cout << ans << '\n';
}
