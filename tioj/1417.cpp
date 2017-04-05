#include<bits/stdc++.h>
#include "lib1417.h"
using namespace std;
const int N = 1.12e5;
int a[N];
char b[878];
struct Int
{
    const static int base = 1e9;
	int d[2];
	Int() : d{0,0} {}
	Int(int x) : d{x%base,x/base} {}
	Int operator += (Int x)
	{
	    d[0] += x.d[0];
	    int c = d[0]/base;
	    d[0] %= base;
	    d[1] += x.d[1] + c;
	    if (d[0] < 0 && d[1] > 0) {
            --d[1];
            d[0] += base;
	    } else if (d[0] > 0 && d[1] < 0) {
            ++d[1];
            d[0] -= base;
	    }
	    return *this;
	}
	Int operator += (int x)
	{
		return *this += Int(x);
	}
};
void opt(char * s,const Int& x)
{
    if (x.d[1]) {
        int i = sprintf(s,"%d", x.d[1]);
        sprintf(s+i,"%09d",abs(x.d[0]));
    } else {
        sprintf(s,"%d",x.d[0]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, l, r;
		cin >> n >> l >> r;
		--l;
		for (int i = 0; i < n; ++i)
            cin >> a[i];
		Int sum;
		nth_element(a, a + r, a + n);
		nth_element(a, a + l, a + r);
		for (int i = l; i < r; ++i)
			sum += a[i];
        opt(b,sum);
		output(b);
	}
}
