#include <bits/stdc++.h>
using namespace std;
const int maxn = 51.4;
int K, N;
int U[maxn][maxn], P[maxn][maxn], L[maxn][maxn];
bool check(int a[], int b[])
{
	int cnt = 0, i, j;
	for (i = j = 2 * K; j >= 0 && i >= 0; --j, --i) {
		while (i >= 0 && a[i] <= b[j])
			--i;
		if (i < 0)
			break;
		++cnt;
	}
	return cnt >= K + 1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> K >> N;
	for (int i = 0; i < N; ++i) {
		int S;
		cin >> S;
		for (int j = 0; j < 2 * K + 1; ++j)
			cin >> P[S][j];
		for (int j = 0; j < 2 * K + 1; ++j)
			cin >> U[S][j];
		for (int j = 0; j < 2 * K + 1; ++j)
			cin >> L[S][j];
	}
	for (int S = N; S; --S) {
		bool ok = true;
		for (int i = 1; i <= N && ok; ++i)
			if (i != S)
				ok = check(P[S], P[i]);
		if (ok) {
			cout << S << ' ';
			break;
		}
	}
	for (int S = N; S; --S) {
		bool ok = true;
		for (int i = 1; i <= N && ok; ++i)
			if (i != S)
				ok = check(U[S], L[i]);
		if (ok) {
			cout << S << '\n';
			break;
		}
	}
}
