#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main()
{
	int n;
	scanf("%d", &n);
	while (n--) {
		ull l, r;
		scanf("%llu%llu", &l, &r);
		ull ans = r;
		if (ull x = l ^ r) { 
			x = (2LLU << __lg(x)) - 1;
			if ((r & x) ^ x)
				ans = (r & ~x) | (x >> 1);
		}
		printf("%llu\n", ans);
	}
}
