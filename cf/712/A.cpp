#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1.12e5;
int a[maxn];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb push_back
#define eb emplace_back
#define X first
#define Y second
inline bool RI(int & a) {return scanf("%d", &a) == 1;}
inline bool RL(ll & a) {return scanf("%lld", &a) == 1;}
int main()
{
	int n;
	RI(n);
	rep(i, 0, n)
		RI(a[i]);
	rep(i,0,n)
		printf("%d%c", a[i] + a[i+1], i == n-1 ? '\n' : ' ');
}
