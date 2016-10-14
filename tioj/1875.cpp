#include <bits/stdc++.h>
using namespace std;
const int N = 600000000;
const int maxn = 24494; // sqrt(N)
bool sev[maxn + 1];
int p[2717];
int pn;
void build()
{
	sev[0] = sev[1] = true;
	for (int i = 2; i <= maxn; ++i) {
		if (!sev[i])
			p[pn++] = i;
		for (int j = 0; j < pn && p[j] * i <= maxn; ++j) {
			sev[i * p[j]] = true;
			if (i % p[j] == 0)
				break;
		}
	}
}
int phi(int x)
{
	int ret = x;
	for (int i = 0; i < pn && p[i] * p[i] <= x; ++i)
		if (x % p[i] == 0) {
			while (x % p[i] == 0)
				x /= p[i];
			ret -= ret / p[i];
		}
	if (x > 1)
		ret -= ret / x;
	return ret;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	build();
	long long A;
	while (cin >> A)
		cout << (A > N ? A - 1 : phi(A)) << '\n';
}
