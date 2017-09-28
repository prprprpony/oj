#include<bits/stdc++.h>
using namespace std;
int d[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char * s[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 1; i <= 12; ++i)
		d[i] += d[i-1];
	char x[87];
	cin >> x;
	int k;
	for (k = 0; k < 7 && strcmp(x,s[k]); ++k);
	int ans = 0;
	for (int i = 1; i <= 12; ++i) {
		int v = d[i-1] + 13;
		if ((k + v - 1) % 7 == 4)
			++ans;
	}
	cout << ans << '\n';
}
