#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int ans = 1, cnt = 1, pre = 2e9, a;
	scanf("%*d");
	for ( ; scanf("%d", &a) == 1; pre = a)
		if (pre < a)
			ans = max(ans, ++cnt);
		else
			cnt = 1;
	printf("%d\n", ans);
}
