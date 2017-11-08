#include <stdio.h>
typedef long long ll;
#define N 20000000
int a[N];
int main()
{
	int n, i;
	ll s = 0, f = 0, x, k, y;
	scanf("%d",&n);
	if (n == 1) {
		puts("0 0");
		return 0;
	}
	for (i = 0; i < n; ++i) {
		scanf("%d", a + i);
		s += a[i];
		f += i * 1LL * a[i];
	}
	for (x = 0; x < n/2; ++x) {
		k = f / s;
		if (f - k * s == 0 && 0 <= k && k < n) {
			printf("%lld %lld\n",x,k);
			return 0;
		}
		y = n - x - 1;
		f += (x * a[y] + y * a[x]) - (x * a[x] + y * a[y]);
	}
}

