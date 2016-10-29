#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(), (x).end()
#define X first
#define Y second
// read integers
int RI() {return 0;}
template<typename T>
int RI(T & a)
{
	int c;
	int s = 1;
	while (!((c = getchar()) == '-' || isdigit(c) || c == EOF));
	if (c == EOF)
		return 0;
	if (c == '-') {
		s = -1;
		c = getchar();
	}
	a = 0;
	do {
		a = 10 * a + s * (c - '0');
	} while (isdigit(c = getchar()));
	return 1;
}
template<typename T, typename... Args>
int RI(T & a, Args & ... args) {return RI(a) ? 1 + RI(args...) : 0;}
//print integers, python style
template<typename T>
void __PI(T a)
{
	static const int maxd = 25;
	static char d[maxd];
	int i = maxd - 1;
	int s = a < 0 ? -1 : 1;
	do {
		d[--i] = s * (a % 10) + '0';
	} while (a /= 10);
	if (s < 0)
		d[--i] = '-';
	fputs(d + i, stdout);
}
template<char sep>
void __PSI() {}
template<char sep, typename T>
void __PSI(const T & a) {putchar(sep), __PI(a);}
template<char sep, typename T, typename... Args>
void __PSI(const T & a, const Args & ... args) {__PSI<sep, T>(a), __PSI<sep, Args...>(args...);}
template<char sep = ' ', char end = '\n', typename T, typename... Args>
void PI(const T & a, const Args & ... args) {__PI(a), __PSI<sep, Args...>(args...), putchar(end);}

const int maxn = 1.12e5;
ll a[maxn], b[maxn], dp[maxn];
struct line
{
	ll m, k; // y = mx + k
	line() {}
	line(ll _m, ll _k) : m(_m), k(_k) {}
	ll operator () (ll x) {return m * x + k;}
};
line dk[maxn];
int l, r;
int main()
{
	int n;
	RI(n);
	rep(i,0,n)
		RI(a[i]);
	rep(i,0,n)
		RI(b[i]);
	dp[0] = 0;
/* naive
	rep(i,1,n) {
		dp[i] = inf;
		rep(j,0,i)
			dp[i] = min(dp[i], a[i] * b[j] + dp[j]);
	}
*/
	dk[0] = line(b[0], dp[0]);
	l = 0;
	r = 1;
	rep(i,1,n) {
		while (r - l >= 2 && dk[l](a[i]) >= dk[l+1](a[i]))
			++l;
		dp[i] = dk[l](a[i]);
		line now(b[i], dp[i]);
		while (r - l >= 2 && (-dk[r-2].k + now.k) * 1.0 / (dk[r-2].m - now.m) <= (-dk[r-2].k + dk[r-1].k) * 1.0 / (dk[r-2].m - dk[r-1].m))
			--r;
		dk[r++] = now;
	}
	PI(dp[n-1]);
}
