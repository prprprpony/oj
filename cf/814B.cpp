#include<bits/stdc++.h>
using namespace std;
const int N = 1087;
int a[N],b[N],c[N];
int main()
{
	int n,x,y,k=0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (c[a[i]]) {
			x = c[a[i]];
			y = i;
		}
		c[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		k += i != x && i != y && a[i] != b[i];
	}
	for (int i = 1; i <= n; ++i)
		if (!c[i])
			a[x] = i;
	if ((a[x] != b[x]) + (a[y] != b[y]) + k != 1)
		swap(a[x], a[y]);
	for (int i = 1; i <= n; ++i)
		cout << a[i] << " \n"[i == n];
}
