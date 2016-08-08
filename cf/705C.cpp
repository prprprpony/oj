#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 3e5 + 228;
vector<int> app[maxn];
bool read[maxn];
int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	int j = 0;
	int cnt = 0;
	int read_first = 0;
	for (int i = 0; i < q; ++i) {
		int t, x;
		scanf("%d%d", &t, &x);
		switch (t) {
		case 1:
			++cnt;
			app[x].push_back(j++);
			break;
		case 2:
			for (int k : app[x])
				if (!read[k]) {
					read[k] = true;
					--cnt;
				}
			app[x].clear();
			break;
		case 3:
			for (int & k = read_first; k < x; ++k)
				if (!read[k]) {
					read[k] = true;
					--cnt;
				}
			break;
		}
		printf("%d\n", cnt);
	}
}
