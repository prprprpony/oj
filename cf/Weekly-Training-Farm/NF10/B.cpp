#include <bits/stdc++.h>
using namespace std;
const int maxn = 2.28e5;
int a[maxn];
int pos[maxn];
int n;
void print() 
{
	printf("%d", a[0]);
	for (int i = 1; i < n; ++i)
		printf(" %d", a[i]);
	putchar('\n');
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		pos[a[i]] = i;
	}
	int flag = 0;
	for (int i = 0; i < n; ++i)
		if (a[i] != n-i-1) {
			swap(a[i], a[pos[n-i-1]]);
			print();
			swap(a[i], a[pos[n-i-1]]);
			flag = 1;
			break;
		}
	if (!flag) {
		swap(a[n-1], a[n-2]);
		print();
		swap(a[n-1], a[n-2]);
	} else 
		flag = 0;
	for (int i = 0; i < n; ++i)
		if (a[i] != i) {
			swap(a[i], a[pos[i]]);
			print();
			swap(a[i], a[pos[i]]);
			flag = 1;
			break;
		}
	if (!flag) {
		swap(a[n-1], a[n-2]);
		print();
		swap(a[n-1], a[n-2]);
	}
}
