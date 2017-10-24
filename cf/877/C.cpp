#include<bits/stdc++.h>
using namespace std;
#define SZ(a) ((int)(a).size())
/*>_<*/
const int N = 1e5 + 87;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int k = n + n/2;
	cout << k << '\n';
	for (int i = 2; i <= n; i += 2)
		cout << i << " \n"[--k == 0];
	for (int i = 1; i <= n; i += 2)
		cout << i << " \n"[--k == 0];
	for (int i = 2; i <= n; i += 2)
		cout << i << " \n"[--k == 0];
}
