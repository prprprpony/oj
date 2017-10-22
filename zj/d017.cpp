#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1087;
char s[N];
int main()
{
	for (int kase = 1; scanf("%s",s+1) == 1; ++kase) {
		if (kase > 1)
			puts("");
		printf("AB Circle #%d:\n",kase);
		int n = strlen(s+1), b = 0;
		for (int i = 1; i <= n; ++i)
			b += s[i] - 'a';
		int a = n - b;
		if (a > b) {
			a ^= b;
			b ^= a;
			a ^= b;
		}
		for (int i = 0; i + a < n; ++i) {
		// a == c[n] - b
		// j - i - b == c[n] - b
		// j - i == c[n]
		// j == i + c[n]

		// b = n - c[n] - j + i + b
		// j = i + n - c[n]
			printf("%d,%d\n",i,i + a);
			if (a != b && i + b < n)
				printf("%d,%d\n",i,i + b);
		}
	}
}
