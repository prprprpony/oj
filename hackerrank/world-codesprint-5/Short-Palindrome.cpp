#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
const int maxn = 1.1e6;
char s[maxn];
int dp[maxn]; // dp[i] = number of short palindromes that use i as the rightmost element and have two kinds of character
int last[26];
int cnt[maxn][26];
int pcnt[26][26];
void exgcd(int a, int b, ll & x, ll & y, ll & g)
{
	if (b) {
		exgcd(b, a % b, y, x, g);
		y -= a / b * x;
	} else {
		g = a;
		x = 1;
		y = 0;
	}
}
int inv(int a)
{
	ll x, y, g;
	exgcd(a, M, x, y, g);
	return ((x % M) + M) % M;
}
inline int add(int a, int b) {return (a += b) < M ? a : a - M;}
inline int sub(int a, int b) {return (a -= b) < 0 ? a : a + M;}
inline int mul(int a, int b) {return a * 1LL * b % M;}
inline int _div(int a, int b) {return mul(a, inv(b));}
int C(int n, int k)
{
	if (k > n)
		return 0;
	k = min(k, n - k);
	int ret = 1;
	for (int i = 1; i <= k; ++i)
		ret = _div(mul(ret, n - k + i), i);
	return ret;
}
int main()
{
	scanf("%s", s + 1);
	int ans = 0;
	int i, j;
	for (i = 1; islower(s[i]); ++i) {
		int c = s[i] - 'a';
		dp[i] = dp[last[c]];
		for (j = 0; j < 26; ++j) {
			if (j == c)
				continue;
			int nj = cnt[i-1][j] - cnt[last[c]][j], nc = cnt[last[c]][c];
			dp[i] = add(dp[i], mul(C(nj, 2), nc)); // c | jjc
			dp[i] = add(dp[i], mul(nj, sub(pcnt[j][c], mul(nj, nc)))); // cj | jc
			pcnt[c][j] = add(pcnt[c][j], cnt[i-1][j]);
		}
		memcpy(cnt[i], cnt[i-1], 26 * sizeof(int));
		++cnt[i][c];
		last[c] = i;
		ans = add(ans, dp[i]);
	}
	for (j = 0; j < 26; ++j)
		ans = add(ans, C(cnt[i-1][j], 4));
	printf("%d\n", ans);
}
