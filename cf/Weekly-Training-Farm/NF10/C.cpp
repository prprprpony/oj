#include <bits/stdc++.h>
using namespace std;
const int maxn = 2.28e5;
int a[maxn];
int pos[maxn];
int n;
int p[maxn];
int len[maxn];
int find(int a) {return p[a] == a ? a : p[a] = find(p[a]);}
void meld(int a, int b)
{
	a = find(a), b = find(b);
	p[a] = b;
	len[b] += len[a];
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		pos[a[i]] = i;
		p[i] = i;
	}
	int ml = 0;
	long long ans = 0;
	for (int i = n-1; i >= 0; --i) {
		int x = pos[i];
		len[x] = 1;
		if (x + 1 < n && len[find(x+1)])
			meld(x, x+1);
		if (x - 1 >= 0 && len[find(x-1)])
			meld(x, x-1);
		ml = max(ml, len[find(x)]);
		ans += ml;
	}
	printf("%lld\n", ans);
}
