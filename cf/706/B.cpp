#include <cstdio>
using namespace std;
const int maxn = 1e5 + 228;
int s[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		++s[x];
	}
	for (int i = 1; i < maxn; ++i)
		s[i] += s[i-1];
	int q;
	scanf("%d", &q);
	while (q--) {
		int m;
		scanf("%d", &m);
		printf("%d\n", m < maxn ? s[m] : n);
	}
}
