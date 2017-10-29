#include<bits/stdc++.h>
using namespace std;
#define ALL(a) begin(a),end(a)
#define SZ(a) ((int)(a).size())
#define PB push_back
/**/
const int N = 1e5 + 87;
int n,cp[N];
string a;
bool cmp(int i,int j)
{
	if (j >= n)
		return 1;
	int k = cp[i];
	if (k >= j)
		return 1;
	return a[k] <= a[k+1];
}
void sol()
{
	cin >> a;
	int v = 0;
	for (char c : a)
		v += c - '0';
	v %= 3;
	n = SZ(a);
	if ((a[n-1] - '0') % 2 == 0) {
		cp[n-1] = n;
		for (int i = n - 2; i >= 0; --i)
			cp[i] = (a[i+1] != a[i] ? i : cp[i+1]);
		int ai = n;
		if ((a[n-1] - '0') % 3 == v && (a[n-2] - '0') % 2 == 0) {
			ai = n-1;
		}
		for (int i = n - 2; i >= 0; --i)
			if ((a[i] - '0') % 3 == v && cmp(i,ai))
				ai = i;
		if (ai == n) {
			cout << "-1\n";
		} else {
			for (int i = 0; i < n; ++i)
				if (i != ai)
					cout << a[i];
			cout << '\n';
		}
	} else {
		if ((a[n-2] - '0') % 2 == 0) {
			if ((a[n-1] - '0') % 3 == v) {
				a.pop_back();
				cout << a << '\n';
			} else {
				cout << "-1\n";
			}
		} else {
			cout << "-1\n";
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin >> T;
	while (T--)
		sol();
}
