#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7;
bitset<maxn + 1> sev;
vector<int> p;
int main()
{
	sev[0] = sev[1] = 1;
	for (int i = 2; i <= maxn; ++i) {
		if (!sev[i])
			p.push_back(i);
		for (auto x : p) {
			if (i * x > maxn)
				break;
			sev[i * x] = 1;
			if (i % x == 0)
				break;
		}
	}

	long long x = 1;
	for (int i = 0; i < 20; ++i) {
		x *= p[i];
		printf("%d\t%d\t%lld\t%f\n", i + 1, p[i], x, log10(x));
	}
}
