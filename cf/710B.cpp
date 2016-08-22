#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 3e5 + 315;
int x[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", x + i);
	nth_element(x, x + (n - 1) / 2, x + n);
	printf("%d\n", x[(n-1)/2]);
}
