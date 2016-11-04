#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	scanf("%d", &N);
	int a, s = 0;
	while (N--) {
		scanf("%d", &a);
		s ^= a;
	}
	puts(s ? "No" : "Yes");
}
