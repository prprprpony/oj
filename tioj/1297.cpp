#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x;
	while (scanf("%d", &x) == 1) {
		int low = 0, high = 1024;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if ((int)(mid * 1.01) < x)
				low = mid + 1;
			else
				high = mid - 1;
		}
		if (low < 0 || low > 1024 || (int)(low * 1.01) != x)
			puts("stupid");
		else
			printf("%d\n", low);
	}
}
