#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 42;
int N, M;
priority_queue<int> Q[maxn];
int q[maxn], p[maxn];
ll S[maxn], L[maxn];
inline ll max(ll a, ll b) {return a > b ? a : b;}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		cin >> p[i] >> S[i] >> L[i];
		Q[i].push(S[i]);
		q[i] = i;
	}
	ll ans = 0;
	for (int i = N; i >= 1; --i) {
		int a = q[i], b = q[p[i]];
		ans = max(ans, Q[a].size() * L[i]);
		if (Q[a].size() < Q[b].size())
			swap(a, b);
		q[p[i]] = a;
		while (Q[b].size()) {
			S[a] += Q[b].top();
			Q[a].push(Q[b].top());
			Q[b].pop();
			if (S[a] > M) {
				S[a] -= Q[a].top();
				Q[a].pop();
			}
		}
	}
	cout << ans << '\n';
}
