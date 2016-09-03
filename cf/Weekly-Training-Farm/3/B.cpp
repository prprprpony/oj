#include <cstdio>
#include <utility>
#include <algorithm>
#define R first
#define W second
using namespace std;
typedef pair<int,int> pii;
const int maxn = 2e5 + 426;
pii p[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x, w;
		scanf("%d%d", &x, &w);
		p[i] = {x + w, w * 2};
	}
	sort(p, p + n);
	int ans = 1;
	int last = 0;
	for (int i = 1; i < n; ++i)
		if (p[last].R <= p[i].R - p[i].W) {
			++ans;
			last = i;
		}
	printf("%d\n", ans);
}
