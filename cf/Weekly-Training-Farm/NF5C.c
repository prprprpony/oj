#include <stdio.h>
int main()
{
	long long N;
	int ans;
	scanf("%lld", &N);
	for (ans = 0; N > 0; ++ans)
		if (N == 3)
			N ^= 1;
		else if ((N & 3) == 3)
			++N;
		else if (N & 1)
			N ^= 1;
		else
			N >>= 1;
	printf("%d\n", ans);
}
