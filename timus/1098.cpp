#include<bits/stdc++.h>
using namespace std;
const int N = 3e4 + 87, M = 1999;
char s[N];
int main()
{
	char * p = s;
	while (fgets(p,s+N-p,stdin)) {
		int m = strlen(p);
		if (p[m-1] == '\n')
			p[--m] = '\0';
		p += m;
	}
	int n = p - s;
	int a = 1;
	for (int i = 2; i <= n; ++i) {
		int k = M%i;
		if (!k)
			k = i;
		a = (k + a) % i;
		if (!a)
			a = i;
	}
	puts(s[a-1] == '?' ? "Yes" : s[a-1] == ' ' ? "No" : "No comments");
}
