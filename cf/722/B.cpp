#include <bits/stdc++.h>
using namespace std;
int p[111];
char s[1000];
const char * v = "aeiouy";
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d ", p + i);
	for (int i = 0; i < n; ++i) {
		fgets(s, sizeof(s), stdin);
		int cnt = 0;
		for (int j = 0; s[j]; ++j)
			for (int k = 0; v[k]; ++k)
				if (s[j] == v[k]) {
					++cnt;
					break;
				}
		if (cnt != p[i]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}
