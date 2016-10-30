#include <bits/stdc++.h>
using namespace std;
const int N = 1.12e5, M = 11;
const char nil = 'a' - 1;
char s[N];
int sa[N], ct[N], w[2][N], rk[N], ht[N];
void suffix_array(int n, int m)
{
	int i, j, p = 0, * x = w[0], * y = w[1], h;
	memset(ct, 0, m * sizeof(int));
	for (i = 0; i < n; ++i) ++ct[x[i] = s[i] - ('a' - 1)];
	for (i = 1; i < m; ++i) ct[i] += ct[i - 1];
	for (i = n - 1; i >= 0; --i) sa[--ct[x[i]]] = i;
	for (j = p = 1; p < n; j *= 2, m = p) {
		for (i = n - j, p = 0; i < n; ++i) y[p++] = i;
		for (i = 0; i < n; ++i) if (sa[i] >= j) y[p++] = sa[i] - j;
		memset(ct, 0, m * sizeof(int));
		for (i = 0; i < n; ++i) ++ct[x[y[i]]];
		for (i = 1; i < m; ++i) ct[i] += ct[i - 1];
		for (i = n - 1; i >= 0; --i) sa[--ct[x[y[i]]]] = y[i];
		swap(x, y);
		x[sa[0]] = 0;
		p = 1;
		for (i = 1; i < n; ++i)
			x[sa[i]] = y[sa[i]] == y[sa[i-1]] && y[sa[i] + j] == y[sa[i-1] + j] ? p - 1 : p++;
	}
	for (i = 0; i < n; ++i) rk[sa[i]] = i;
	ht[0] = 0;
	h = 0;
	for (i = 0; rk[i]; ++i) {
		while (s[i + h] == s[sa[rk[i] - 1] + h]) ++h;
		ht[rk[i]] = h;
		if (h) --h;
	}
}
int main()
{
	scanf("%s", s);
	int n = strlen(s);
	s[n++] = nil;
	suffix_array(n, M);
#ifdef PP
	for (int i = 0; i < n; ++i)
		printf("%d%c", sa[i], i == n - 1 ? '\n' : ',');
	for (int i = 0; i < n; ++i)
		printf("%d%c", ht[i], i == n - 1 ? '\n' : ',');
	for (int i = 0; i < n; ++i)
		printf("%d%c", rk[i], i == n - 1 ? '\n' : ',');
#endif
	int p = 0;
	for (int i = 1; i < n; ++i)
		if (ht[i] > ht[p])
			p = i;
	s[sa[p] + ht[p]] = '\0';
	puts(s + sa[p]);
}
