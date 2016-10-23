#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[100];
int v[] = {3,4,5,2,1,0};
int main()
{
	gets(a);
	int i;
	for (i = 1; isdigit(a[i]); ++i);
	char c = a[i];
	a[i] = '\0';
	ll n;
	sscanf(a, "%lld", &n);
	--n;
	printf("%lld\n", 16 * (n / 4) + ((n % 4) & 1) * 7 + v[c - 'a'] + 1);
}
