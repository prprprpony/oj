#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2.25e5;
char s[maxn];
int main()
{
	int n;
	scanf("%d ", &n);
	gets(s);
	int ans = 0;
	for (int i = 0; i < n && s[i] == '<'; ++i, ++ans);
	for (int i = n - 1; i >= 0 && s[i] == '>'; --i, ++ans);
	printf("%d\n", ans);
}
