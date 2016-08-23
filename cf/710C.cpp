#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int odd = -1, even = 0;
	for (int i = 0; i < n; ++i) {
		int v = n - 2 * abs(i - n / 2);
		int k = n / 2 - (v - 1) / 2;
		for (int j = 0; j < n; ++j)
			printf("%d%c", k <= j && j < k + v ? (odd += 2) : (even += 2), j == n - 1 ? '\n' : ' ');
	}
}
