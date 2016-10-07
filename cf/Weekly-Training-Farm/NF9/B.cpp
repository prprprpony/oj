#include <bits/stdc++.h>
using namespace std;
int n;
int a[3];
int p[12];
int ans;
void dfs(int i)
{
	if (i > n) {
		++ans;
		return;
	}
	for (int j = 0; j < 3; ++j)
		if (a[j] && p[i-1] != j) {
			--a[j];
			p[i] = j;
			dfs(i+1);
			++a[j];
		}
}
int main()
{
	for (int i = 0; i < 3; ++i) {
		cin >> a[i];
		n += a[i];
	}
	p[0] = -1;
	dfs(1);
	cout << ans << '\n';
}
