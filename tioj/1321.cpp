#include<bits/stdc++.h>
using namespace std;
const int N = 1000000 * 2 + 87;
char t[N*2];
int z[N*2];
void bz(char * s,int n)
{
	int m = 0;
	for (int i = 0; i < n; ++i) {
		t[m++] = '*';
		t[m++] = s[i];
	}
	t[m++] = '*';
	z[0] = 0;
	int j = 0;
	for (int i = 1; i < m; ++i)
		if (j + z[j] >= i) {
			int p = j-(i-j);
			if (i + z[p] < j + z[j])
				z[i] = z[p];
			else if (i + z[p] == j + z[j]) {
				int l = i - z[p] - 1, r = i + z[p] + 1;
				for (; l >= 0 && r < m && t[l] == t[r]; --l, ++r);
				z[i] = r - i - 1;
				j = i;
			} else {
				z[i] = j + z[j] - i;
			}
		} else {
			int l = i - 1,r = i + 1;
			for (; l >= 0 && r < m && t[l] == t[r]; --l, ++r);
			z[i] = r - i - 1;
			j = i;
		}
}
char s[N];
int ans[N],tp;
int main()
{
	fgets(s,N,stdin);
	int n = strlen(s);
	while (s[n-1] == '\n') --n;
	for (int i = n; i < 2 * n - 1; ++i)
		s[i] = s[i-n];
	bz(s,2*n-1);
	for (int i = 0; i < n; ++i)
		if (z[i*2+n] >= n)
			ans[tp++] = i;
	if (!tp)
		puts("none");
	else {
		printf("%d:",tp);
		for (int i = 0; i < tp; ++i)
			printf(" %d",ans[i]);
		puts("");
	}
}
