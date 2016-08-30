#include <bits/stdc++.h>
#define FOR(i,s,e) for (int i = (s); i < (e); ++i)
using namespace std;
typedef long long ll;
ll get()
{
	int n, b;
	scanf("%d%d", &n, &b);
	ll v = 0;
	while (n--) {
		int d;
		scanf("%d", &d);
		v = b * v + d;
	}
	return v;
}
int main()
{
	ll x = get();
    ll y = get();
	puts(x < y ? "<" : x > y ? ">" : "=");
}
