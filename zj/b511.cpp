#include <cstdio>
using namespace std;
int N;
int c[5];
int a[5];
void dfs(int d, int v)
{
	if (d == N) {
		if (!v) {
			printf("(%d", a[0]);
			for (int i = 1; i < N; ++i)
				printf(",%d", a[i]);
			puts(")");
		}
		return;
	}
	for (a[d] = 0; v >= 0; v -= c[d], ++a[d])
		dfs(d + 1, v);
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", c + i);
	int v;
	scanf("%d", &v);
	dfs(0,v);
}
