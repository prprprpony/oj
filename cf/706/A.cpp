#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int n;
	scanf("%d", &n);
	double ans = -1.0;
	for (int i = 0; i < n; ++i) {
		double x, y, v;
		scanf("%lf%lf%lf", &x, &y, &v);
		if (!i)
			ans = hypot(x-a, y-b) / v;
		else
			ans = min(ans, hypot(x-a, y-b) / v);
	}
	printf("%.16f\n", ans);
}
