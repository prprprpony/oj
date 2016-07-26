#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;
const int maxl = 1.1e5;
char s[maxl];
bool vis[26];
int main()
{
	int n;
	scanf("%d ", &n);
	while (n--) {
		fgets(s, sizeof(s), stdin);
		memset(vis, 0, sizeof(vis));
		int tot = 0;
		for (int i = 0; islower(s[i]); ++i)
			vis[s[i] - 'a'] = true;
		for (int i = 0; i < 26; ++i)
			if (vis[i])
				++tot;
		printf("%d\n", tot);
	}
}
