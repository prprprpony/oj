#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int low = 1, high = n;
	while (m-- && high > low) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a > b)
			swap(a, b);
		low = max(low, a);
		high = min(high, b);
	}
	printf("%d\n", high > low ? high - low : 0);
	
	return 0;
}