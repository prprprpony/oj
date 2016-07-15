#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int N;
	int a[64];
	while (scanf("%d", &N) == 1 && N) {
		int p = 0;
		for (int i = 0; i < N; ++i) {
			scanf("%d", a + i);
			for (int j = i - 1; j >= 0; --j)
				if (__gcd(a[j], a[i]) == 1)
					++p;
		}
		if (p)
			printf("%.6f\n", sqrt(6.0 / (p / (N * (N - 1) / 2.0))));
		else
			puts("No estimate for this data set.");
	}
}
