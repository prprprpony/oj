#include <bits/stdc++.h>
using namespace std;
const int maxn = 2.28e5;
int a[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < n - 1; ++i)
		if (a[i] & 1) {
			if (a[i+1]) {
				--a[i];
				--a[i+1];
			} else {
				puts("NO");
				return 0;
			}
		}
	puts((a[n-1] & 1) ? "NO" : "YES"); 
}
