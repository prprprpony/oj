#include <bits/stdc++.h>
using namespace std;
const int maxn = 106;
int x[maxn];
int main()
{
	int n, b, p, v1, v2;
	scanf("%d%d%d%d%d", &n, &b, &p, &v1, &v2);
	for (int i = 0; i < n; ++i)
		scanf("%d", x + i);
	sort(x, x + n);
	int i = lower_bound(x, x + n, p) - x;
	if (i < n && !(p < b && b <= x[i]) && abs(p - x[i]) * v1 < abs(b - x[i]) * v2)
		puts("useful");
	else if (--i >= 0 && !(x[i] <= b && b < p) && abs(p - x[i]) * v1 < abs(b - x[i]) * v2)
		puts("useful");
	else 
		puts("useless");
}
