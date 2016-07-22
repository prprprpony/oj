#include <cstdio>
#include <cctype>
#include <algorithm>
#define RI(x) scanf("%d ", &x)
#define FO(i,s,e) for (int i = (s); i != (e); ++i)
using namespace std;
const int maxn = 1.1e5;
char s[maxn];
bool cs[52];
int cnt[52];
inline int ctoi(char c)
{
	return islower(c) ? c - 'a' : c - 'A' + 26;
}
int main()
{
	int n;
	RI(n);
	fgets(s, sizeof(s), stdin);
	int j;
	int tot = 0;
	FO(i, 0, n)
		if (!cs[j = ctoi(s[i])]) {
			++tot;
		   	cs[j] = true;
		}
	int ans = n;
	int r = 0, t = 0;
	for (int l = 0; l < n; ++l) {
		if (l)
			if (--cnt[ctoi(s[l-1])] == 0)
				--t;
		while (r < n && t < tot)
			if (cnt[ctoi(s[r++])]++ == 0)
				++t;
		if (t == tot)
			ans = min(ans, r - l);
		else
			break;
	}
	printf("%d\n", ans);
}
