#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> pii;
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

const int maxn = 100;
bool sev[maxn + 1];
vector<int> p;
int cnt[maxn + 1][25];

void build()
{
	sev[0] = sev[1] = true;
	rep(i, 2, maxn+1) {
		if (!sev[i])
			p.push_back(i);
		for (auto x: p) {
			if (i * x > maxn)
				break;
			sev[i * x] = true;
			if (i % x == 0)
				break;
		}
	}
	rep(i, 1, maxn + 1) {
		int x = i;
		rep(j,0, p.size()) {
			while (x % p[j] == 0) {
				cnt[i][j]++;
				x /= p[j];
			}
			if (x == 1)
				break;
		}
	}
}

ui d(int x, int y, int z)
{
	ui ret = 1;
	rep(i,0,25)
		ret *= (cnt[x][i] + cnt[y][i] + cnt[z][i] + 1);
	return ret;
}

int main()
{
	build();
	int a, b, c;
	RI(a, b, c);
	ui ans = 0;
	rep(i, 1, a+1)
		rep(j, 1, b+1)
			rep(k, 1, c+1)
				ans += d(i, j, k);
	PI(ans & ((1U<<31)-1));
}
