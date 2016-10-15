#include "lib1227.h"
#include <iostream>
typedef long long ll;
using namespace std;
const int maxn = 1.12e6;
ll dd[maxn];
int main()
{
	int N, M, Q;
	cin >> N >> M >> Q;
	for (int i = 0; i < N; ++i)
		cin >> dd[i];
	init(N, dd);
	while (M--) {
		int a, b;
		ll k;
		cin >> a >> b >> k;
		change(a, b, k);
	}
	while (Q--) {
		int c;
		cin >> c;
		cout << query(c) << '\n';
	}
}
