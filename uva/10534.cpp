#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1e4 + 228;
int a[maxn], lis[maxn];
int main()
{
	int n;
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; ++i)
			scanf("%d", a + i);
		vector<int> rear = {a[0]};
		for (int i = 1; i < n; ++i)
			if (a[i] > rear.back()) {
				rear.push_back(a[i]);
				lis[i] = rear.size();
			} else {
				int j = lower_bound(rear.begin(), rear.end(), a[i]) - rear.begin();
				rear[j] = a[i];
				lis[i] = j + 1;
			}
		rear = {a[n-1]};
		int ans = 1;
		for (int i = n - 2; i >= 0; --i) {
			int d;
			if (a[i] > rear.back()) {
				rear.push_back(a[i]);
				d = rear.size();
			} else {
				int j = lower_bound(rear.begin(), rear.end(), a[i]) - rear.begin();
				rear[j] = a[i];
				d = j + 1;
			}
			ans = max(ans, min(d, lis[i]));
		}
		printf("%d\n", 2 * ans - 1);
	}
}
