#include <cstdio>
using namespace std;
const int maxn = 1024;
char g[maxn][maxn];
int sumr[maxn];
int sumc[maxn];
int main()
{
	int n, m;
	int w = 0;
	scanf("%d%d ", &n, &m);
	for (int r = 1; r <= n; ++r) {
		fgets(g[r] + 1, sizeof(g[r]) - 1, stdin);
		for (int c = 1; c <= m; ++c)
			if (g[r][c] == '*') {
				++sumr[r];
				++sumc[c];
			}
		w += sumr[r];
	}
	for (int r = 1; r <= n; ++r)
		for (int c = 1; c <= m; ++c)
			if (sumr[r] + sumc[c] + (g[r][c] == '*' ? -1 : 0) == w) {
				puts("YES");
				printf("%d %d\n", r, c);
				return 0;
			}
	puts("NO");
}
