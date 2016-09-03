#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 777;
ll odd[maxn][maxn];
ll d[maxn][maxn];
ll p(int n, int k)
{
	if (k > n)
		k = n;
	if (k == 1 || n == 0)
		return 1;
	if (n < 0)
		return 0;
	ll & now = d[n][k];
	if (now != -1)
		return now;
	else
		return now = p(n-k,k) + p(n, k-1);
}
ll dp(int n, int k)
{
	if (k > n)
		k = n;
	if (k == 1)
		return n & 1;
	ll & now = odd[n][k];
	if (now != -1)
		return now;
	return now = (((n - k) & 1) ? 0 : p((n - k) / 2, k)) + dp(n, k-1);
}
int main()
{
	memset(d, -1, sizeof(d));
	memset(odd, -1, sizeof(odd));
	int M;
	scanf("%d", &M);
	while (M--) {
		int N;
		scanf("%d", &N);
		printf("%lld\n", dp(N, N));
	}
}
