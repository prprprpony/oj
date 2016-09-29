#include <bits/stdc++.h>
using namespace std;
const int T = 1;
const int N = 1e4;
const int Q = 1e6;
int a[N+1];
mt19937 mt(time(0));
const char * cmd[3] = {"CHANGE", "NEGATE", "QUERY"};
int main()
{
	int t = T, n = N, q = Q;
	ios::sync_with_stdio(0);
	cin.tie(0);
	auto pr = bind(uniform_int_distribution<int>(1, N), mt);
	auto cr = bind(uniform_int_distribution<int>(0, 2), mt);
	auto pp = bind(uniform_int_distribution<int>(1, N-1), mt);
	cout << T << '\n';
	while (t--) {
		cout << N << '\n';
		for (int i = 1; i <= N; ++i)
			a[i] = i;
		for (int i = N; i > 1; --i) {
			swap(a[i], a[mt()%i+1]);
			swap(a[i-1], a[mt()%(i-1)+1]);
			cout << a[i] << ' ' << a[i-1] << ' ' << pr() << '\n';
		}
		while (q--) {
			int a, b, c = cr();
			cout << cmd[c] << ' ';
			if (!c) {
				a = pp();
				b =	pr();
			} else {
				a = pr();
				while ((b = pr()) == a);
			}
			cout << a << ' ' << b << '\n';
		}
		cout << "DONE\n";
	}
}
