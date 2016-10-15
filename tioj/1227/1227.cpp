#include "lib1227.h"
#include <algorithm>
using namespace std;
typedef long long ll;
ll * d;
int n;
void init(int N, long long D[])
{
	n = N;
	d = D;
	for (int i = (n-1); i >= 2; --i)
		d[i] -= d[i-2];
}
void change(int a, int b, long long k)
{
	int eb = b ^ (b & 1);
	int ob = b - 1 + (b & 1);
	if (!(a & 1))
		swap(eb, ob);
	d[a] -= k;
	if (ob + 2 < n)
		d[ob + 2] += k;
	if (a + 1 <= b) {
		d[a + 1] += k;
		if (eb + 2 < n)
			d[eb + 2] -= k;
	}
}
long long query(int c)
{
	static bool first = true;
	if (first) {
		first = false;
		for (int i = 2; i < n; ++i)
			d[i] += d[i-2];
	}
	return d[c];
}
