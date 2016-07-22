#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 1.1e5;
bool row[maxn], col[maxn];
int cntr, cntc;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	int m;
	cin >> n >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		if (!row[x]) {
			row[x] = 1;
			++cntr;
		}
		if (!col[y]) {
			col[y] = 1;
			++cntc;
		}
		cout << (n * n - n * (cntr + cntc) + cntc * 1LL * cntr) << (m ? ' ' : '\n');
	}
}
