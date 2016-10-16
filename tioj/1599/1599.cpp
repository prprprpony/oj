#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
#define L first
#define W second
pii operator + (const pii & a, const pii & b) {return {a.L + b.L, a.W + b.W};}
const int maxn = 1.12e3;
const int maxv = 5e4;
const int d = 13;
const pii inf(maxn, 530000000000000000LL);
ll w[maxn];
pii dp[maxv];
vector<int> choice[maxv];
ll p[d];
int e[d];
int ne[d], pe[d], ue[d];
int we[maxn][d];
int tot[d];
int k;
int base[d];
void fin(ll x)
{
	int f[2] = {2, 3};
	for (int i = 0; i < 2; ++i)
		if (x % f[i] == 0) {
			p[k++] = f[i];
			while (x % f[i] == 0) {
				x /= f[i];
				++e[k-1];
			}
		}
	for (ll i = 5, j = 1; i * i <= x; i += 2 << (j ^= 1)) // 6n+1, 6n+5
		if (x % i == 0) {
			p[k++] = i;
			while (x % i == 0) {
				x /= i;
				++e[k-1];
			}
		}
	if (x > 1) {
		p[k++] = x;
		++e[k-1];
	}
	base[0] = 1;
	for (int i = 1; i < k; ++i)
		base[i] = (e[i-1] + 1) * base[i-1];
}
int encode(int ve[])
{
	int ret = 0;
	for (int i = k - 1; i >= 0; --i)
		ret = ret * (e[i] + 1) + ve[i];
	return ret;
}
void sub(int v1[], int v2[], int res[])
{
	for (int i = 0; i < k; ++i)
		res[i] = max(0, v1[i] - v2[i]);
}
void dec(int &S, int & pr)
{
	--S;
	for (int i = 0; i < k; ++i) {
		if (pe[i] - 1 >= 0) {
			pr -= base[i];
			--pe[i];
		}
		if (ne[i] - 1 >= 0) {
			--ne[i];
			return;
		}
		ne[i] = e[i];
		pe[i] = ue[i];
		pr += ue[i] * base[i];
	}
}
#define INITM()\
	clock_t __s, __e;
#define SM()\
	__s = clock();
#define EM(s)\
	__e = clock();\
cout<<'\n'<<s<<'\n';\
cout << (__e - __s) * 1.0 / CLOCKS_PER_SEC << "\n\n";
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int M;
	ll C;
	cin >> M >> C;
	fin(C);
	for (int i = 0; i < M; ++i) {
		cin >> w[i];
		for (ll j = 0, t = w[i]; j < k; ++j) {
			while (t % p[j] == 0) {
				++we[i][j];
				t /= p[j];
			}
			tot[j] += we[i][j];
		}
	}
	if (C == 1) {
		int j = 0;
		for (int i = 1; i < M; ++i)
			if (w[i] < w[j])
				j = i;
		cout << "1\n" << j << '\n';
		return 0;
	}
	for (int i = 0; i < k; ++i)
		if (tot[i] < e[i]) {
			cout << "-1\n";
			return 0;
		}
	int full = encode(e);
	fill_n(dp+1, full, inf);
	dp[0] = {0,0};
#ifdef PP
	INITM();
	SM();
#endif
	for (int i = 0; i < M; ++i) {
		bool ok = false;
		for (int j = 0; j < k && !ok; ++j)
			ok = we[i][j] > 0;
		if (!ok)
			continue;
		copy(e, e+k, ne);
		sub(ne, we[i], pe);
		copy(pe, pe+k, ue);
		for (int S = full, pr = encode(pe); S; dec(S, pr)) {
			pii c = dp[pr] + pii(1, w[i]);
			if (c < dp[S]) {
				dp[S] = c;
				choice[S] = choice[pr];
				choice[S].push_back(i);
			}
		}
	}
#ifdef PP
	EM("bottom up DP");
#endif
	cout << dp[full].L << '\n';
	for (int i = 0; i < choice[full].size(); ++i)
		cout << choice[full][i] << (i != choice[full].size() - 1 ? ' ' : '\n');
}
