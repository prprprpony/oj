#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	set<int> Y;
	while (n--) {
		int y;
		scanf("%d",&y);
		Y.insert(y);
	}
	for(;;) {
		int x = *Y.rbegin();
		while (x && Y.count(x))
			x>>=1;
		if (x) {
			Y.erase(*Y.rbegin());
			Y.insert(x);
		} else {
			break;
		}
	}
	printf("%d", *Y.begin());
	Y.erase(*Y.begin());
	for (int x : Y)
		printf(" %d", x);
	puts("");
}
