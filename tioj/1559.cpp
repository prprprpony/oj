#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
void opt(double x)
{
	int v = x * 1000 + (x >= 0 ? 0.5 : -0.5);
	printf("%d.%03d", v / 1000, abs(v % 1000));
}
int main()
{
	double x1,y1,x2,y2;
	pair<double,double> ans[2];
	while (scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2) != EOF) {
		x1 -= x2;
		y1 -= y2;
		double mx = x2 + x1/ 2, my = y2 + y1 / 2;
		swap(x1, y1);
		x1 *= -1;
		x1 *= sqrt(3)/2;
		y1 *= sqrt(3)/2;
		ans[0] = {mx + x1, my + y1};
		ans[1] = {mx - x1, my - y1};
		sort(ans,ans+2);
		for (int i = 0; i < 2; ++i) {
			opt(ans[i].first);
			putchar(' ');
			opt(ans[i].second);
			putchar(" \n"[i]);
		}
	}
}
