#include <bits/stdc++.h>
using namespace std;
char s[1024];
int main()
{
	int pos = 0, ans = 0;
	gets(s);
	for (int i = 0; s[i]; ++i) {
		s[i] -= 'a';
		int step = abs(s[i] - pos);
		step = min(step, 26 - step);
		ans += step;
		pos = s[i];
	}
	printf("%d\n", ans);
}
