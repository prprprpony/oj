#include <bits/stdc++.h>
#define RI(x) scanf("%d", &(x))
#define FO(i,s,e) for (int i = (s); i != (e); ++i)
using namespace std;
const int maxn = 106;
int a[maxn], p[maxn];
bool cmp(int x, int y)
{
	return a[x] < a[y];
}
int main()
{
	int n;
	RI(n);
	FO(i, 1, n + 1) {
		RI(a[i]);
		p[i] = i;
	}
	sort(p + 1, p + n + 1, cmp);
	FO(i, 1, n/2 + 1)
		printf("%d %d\n", p[i], p[n-i+1]);
}
