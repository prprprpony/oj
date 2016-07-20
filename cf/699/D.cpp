#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 2.05e5;
int a[maxn];
int p[maxn];
bool c[maxn];
int find(int x) {return x == p[x] ? x : p[x] = find(p[x]);}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		p[i] = i;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		int x = find(a[i]);
		if (a[i] != i && x == i)
			c[i] = true;
		p[i] = x;
	}
	int num = 0;
	int root = 0;
	queue<int> q;
	for (int i = 1; i <= n; ++i)
		if (p[i] == i) {
			++num;
			if (!root && !c[i])
				root = i;
			else 
				q.push(i);
		}
	printf("%d\n", q.size());
	if (!root)
		root = q.front();
	while (!q.empty()) {
		int i = q.front();
		q.pop();
		a[i] = root;
	}
	printf("%d", a[1]);
	for (int i = 2; i <= n; ++i)
		printf(" %d", a[i]);
	puts("");
}
