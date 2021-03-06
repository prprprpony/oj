#include<bits/stdc++.h>
using namespace std;
const int N = 1087;
int mem[2*N+1];
int * vis = mem + N;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,k;
	vector<int> e;
	queue<int> q;
	cin >> n >> k;
	bool gt = 0, lt = 0;
	while (k--) {
		int a;
		cin >> a;
		a -= n;
		if (!vis[a]) {
			vis[a] = 1;
			e.push_back(a);
			q.push(a);
			if (a > 0)
				gt = 1;
			else if (a < 0)
				lt = 1;
			else {
				cout << "1\n";
				return 0;
			}
		}
	}
	if (!lt || !gt) {
		cout << "-1\n";
		return 0;
	}
	while (q.size() && !vis[0]) {
		int u = q.front();
		q.pop();
		for (int v : e) {
			int w = u + v;
			if (-N <= w and w <= N and !vis[w]) {
				vis[w] = vis[u] + 1;
				q.push(w);
			}
		}
	}
	cout << vis[0] << '\n';
}
