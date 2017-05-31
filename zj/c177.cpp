#include<bits/stdc++.h>
using namespace std;
const int V = 205;
int h[V];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		++h[x];
		int s = 0;
		for (int j = 0; j < V; ++j) {
			s += h[j];
			if (j >= k + 1)
				s -= h[j-k-1];
			if (s >= m) {
				cout << i << '\n';
				return 0;
			}
		}
	}
	cout << "Impossible\n";
}
