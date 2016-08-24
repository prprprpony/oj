#include <cstdio>
#include <cstring>
using namespace std;
bool t[27];
int num;
int g[][5] = {
	{},
	{2, 5}, // a
	{1, 3, 6},
	{2, 4, 7},
	{3, 8},
	{1, 6, 9}, // e
	{2, 5, 10},
	{3, 8, 11},
	{4, 7, 12},
	{5, 10, 13}, // i
	{6, 9, 11, 14},
	{7, 10, 12},
	{8, 11, 16},
	{9, 14}, // m
	{10, 13, 15},
	{14, 16},
	{15, 12}
};
int ans;
inline int c2i(char c) {return c - 'a' + 1;}
void dfs(int u, int d)
{
	if (d + num >= ans)
		return;
	if (!num) {
		ans = d;
		return;
	}
	for (int i = 0; g[u][i] && d + num < ans; ++i) {
		int v = g[u][i];
		bool f = t[v];
		if (f) {
			t[v] = false;
			--num;
		}
		dfs(v, d + 1);
		if (f) {
			t[v] = true;
			++num;
		}
	}
}
int main()
{
#ifdef PP
	for (int i = 1; i < sizeof(g) / sizeof(g[0]); ++i) {
		printf("%c:", 'a' + i - 1);
		for (int j = 0; j < sizeof(g[i]) / sizeof(int) && g[i][j]; ++j)
			printf("%c ", 'a' - 1 + g[i][j]);
		putchar('\n');
	}
#endif
	int T;
	scanf("%d ", &T);
	while (T--) {
		memset(t, 0, sizeof(t));
		int s = c2i(getchar());
		num = 0;
		getchar();
		do {
			int c = c2i(getchar());
			if (!t[c]) {
				t[c] = true;
				++num;
			}
		} while (getchar() != '\n');
		ans = 15;
		dfs(s, 0);
		printf("%d\n", ans);
	}
}
