#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[87];
int la[28];
char ans[2][87];
int main()
{
	gets(s + 1);
	int x, y;
	for (int i = 1; i <= 27; ++i)
		if (!la[s[i] - 'A']) {
			la[s[i] - 'A'] = i;
		} else if (la[s[i] - 'A'] == i - 1) {
			puts("Impossible");
			return 0;
		} else {
			x = la[s[i] - 'A'];
			y = i;
			int len = i - x;
			int r, c;
			for (r = 0, c = (len + 1) / 2 - 1; len; --len) {
				ans[r][c] = s[y--];
				if (!r)	{
					if (--c < 0) {
						r = 1;
						c = 0;
					}
				} else {
					++c;
				}
			}
			while (--y > 0) {
				ans[r][c] = s[y];
				if (r) {
					if (++c >= 13) {
						r = 0;
						c = 12;
					}
				} else {
					--c;
				}
			}
			r = 0, c = (i - x + 1) / 2 - 1;
			while (++i <= 27) {
				if (!r) {
					if (++c >= 13) {
						r = 1;
						c = 12;
					}
				} else {
					--c;
				}
				ans[r][c] = s[i];
			}
			break;
		}
	puts(ans[0]);
	puts(ans[1]);
}
