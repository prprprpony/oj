#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define S first
#define W second
const int maxn = 5607;
pii a[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	for ( ; cin >> a[n].W >> a[n].S; ++n);
/*
Moore-Hodgson Algorithm
O(N * log(N))
*/
	sort(a, a + n);
	int t = 0;
	priority_queue<int> pq;
	for (int i = 0; i < n; ++i) {
		pq.push(a[i].W);
		t += a[i].W;
		if (t > a[i].S) {
			t -= pq.top();
			pq.pop();
		}
	}
	cout << pq.size() << '\n';
}
