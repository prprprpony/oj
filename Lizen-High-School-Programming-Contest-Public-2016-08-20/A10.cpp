#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 228;
int n, k;
int L[maxn];
bool ok(int v)
{
	int j = k;
	// v <= L[i]
	for (int i = 0; i < n && j > 0; ++i)
		j -= L[i] / v - 1;
	return j <= 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	int low = 1, high = 1e9;
	for (int i = 0; i < n; ++i) {
		cin >> L[i];
		high = min(high, L[i]);
	}
	while (low <= high) {
		int mid = (low + high) / 2;
		if (ok(mid))
			low = mid + 1;
		else
			high = mid - 1;
	}
	cout << high << '\n';
}
