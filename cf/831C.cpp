#include<bits/stdc++.h>
using namespace std;
const int N = 2017;
int a[N],b[N];
int main()
{
	int k,n;
	scanf("%d%d",&k,&n);
	for (int i = 0; i < k; ++i) {
		scanf("%d", a + i);
		if (i) a[i] += a[i-1];
	}
	for (int i = 0; i < n; ++i)
		scanf("%d", b + i);
	sort(a,a+k);
	k = unique(a,a+k) - a;
	sort(b,b+n);
	int ans = 0;
	for (int i = 0; i + n - 1 < k; ++i) {
		int l = i, r = i + 1, j = 1;
		for (; j < n; ++j) {
			while (r < k && a[r] - a[l] < b[j] - b[j-1])
				++r;
			if (r == k || a[r] - a[l] > b[j] - b[j-1])
				break;
			l = r;
		}
		ans += j == n;
	}
	printf("%d\n",ans);

}
