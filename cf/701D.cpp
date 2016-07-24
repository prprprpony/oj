#include <cstdio>
#include <cmath>
#define RI(x) scanf("%d", &x)
#define RD(x) scanf("%lf", &x)
#define FO(i,s,e) for (int i = (s); i != (e); ++i)
using namespace std;
const double eps = 1e-6;
int n, k;
double L, v1, v2;
bool ok(double t)
{
	double d = L - v1 * t;
	int r = (n + k - 1) / k;
	return d / (v1 + v2) * (r - 1) + d / (v2 - v1) * r <= t; 
}
int main()
{
	RI(n), RD(L), RD(v1), RD(v2), RI(k);
	double low = L / v2, high = L / v1;
	while (fabs(high - low) > eps) {
		double mid = low + (high - low) / 2.0;
		if (ok(mid))
			high = mid;
		else
			low = mid;
	}
	printf("%.7f\n", high);
}
