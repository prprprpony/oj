#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#define W second
#define S first
using namespace std;
typedef pair<int,int> pii;
const int maxn = 5607;
pii a[maxn];
int main()
{
	int n = 0;
	for ( ; scanf("%d%d", &a[n].W, &a[n].S) == 2; ++n);
	sort(a, a + n);
	vector<int> minw = {a[0].W};
	for (int i = 1; i < n; ++i) {
		int j;
		if (a[i].S - a[i].W >= minw.back()) {
			minw.push_back(minw.back() + a[i].W);
			j = minw.size() - 2;
		} else {
			j = upper_bound(minw.begin(), minw.end(), a[i].S - a[i].W) - minw.begin();
		}
		for (; j > 0; --j)
			minw[j] = min(minw[j], minw[j-1] + a[i].W);
		minw[0] = min(minw[0], a[i].W);
	}
	printf("%d\n", (int)minw.size());
}
