#include<stdio.h>
#define N 100087
char s[N];
int main()
{
	while (scanf("%s",s) == 1) {
		int ans = 0;
		for (int i = 0; s[i]; ++i) {
			ans = 10 * ans + s[i] - '0';
			if (ans >= 100000000)
				ans %= 91;
		}
		printf("%d\n", ans%91);
	}
}
