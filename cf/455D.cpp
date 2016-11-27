#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a), __e = (b); i < __e; ++i)
#define RP(i,b) REP(i,0,b)
#define PER(i,a,b) for (int i = (a), __e = (b); i > __e; --i)
#define PR(i,b) REP(i,(b)-1,-1)
#define SZ(a) ((int)a.size())
#define PB push_back
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
typedef vector<int> vi;

const int maxn = 1e5 + 42, BS = 768, BN = maxn / BS + 1;
int cnt[BN][maxn];
struct DK
{
	static const int SZ = BS + 2;
	int a[BS + 2];
	int l, r;
	DK() : l(0), r(SZ-1) {}
	int pp(int & i)
	{
		if (++i == SZ)
			i = 0;
		return i;
	}
	int mm(int & i)
	{
		if (--i == -1)
			i = SZ - 1;
		return i;
	}
	void PB(int x)
	{
		a[pp(r)] = x;
	}
	void push_front(int x)
	{
		a[mm(l)] = x;
	}
	void pop_front()
	{
		pp(l);
	}
	void pop_back()
	{
		mm(r);
	}
	int back()
	{
		return a[r];
	}
	int & operator [] (int i)
	{
		if ((i += l) >= SZ)
			i -= SZ;
		return a[i];
	}
} dk[BN];
int n, ans;
inline int decode(int a)
{
	return (a + ans - 1) % n + 1;
}
inline void dec(int i, int v)
{
	--cnt[i][v];
}
inline int get(int i, int v)
{
	return cnt[i][v];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	RP(i,n) {
		int a;
		cin >> a;
		int j = i / BS;
		cnt[j][a]++;
		dk[j].PB(a);
	}
	int q;
	cin >> q;
	while (q--) {
		int t, l, r, k;
		cin >> t >> l >> r;
		l = decode(l) - 1;
		r = decode(r) - 1;
		if (l > r)
			swap(l,r);
		int i = l / BS, j = r / BS;
		if (t == 1) {
			if (i == j) {
				int s = i * BS;
				l -= s, r -= s;
				int v = dk[i][r];
				while (--r >= l)
					dk[i][r+1] = dk[i][r];
				dk[i][l] = v;
			} else {
				r -= j * BS;
				int v = dk[j][r];
				dec(j, v);
				while (--r >= 0)
					dk[j][r + 1] = dk[j][r];
				dk[j].pop_front();
				while (j > i) {
					int c = dk[j-1].back();
					dk[j].push_front(c);
					cnt[j][c]++;
					dec(--j, c);
					dk[j].pop_back();
				}
				dk[i].PB(42);
				l -= i * BS;
				PER(k,BS-1,l)
					dk[i][k] = dk[i][k-1];
				dk[i][l] = v;
				cnt[i][v]++;
			}
		} else {
			cin >> k;
			k = decode(k);
			ans = 0;
			if (i == j) {
				int s = i * BS;
				l -= s, r -= s;
				for (; l <= r; ++l)
					if (dk[i][l] == k)
						++ans;
			} else {
				r -= j * BS;
				while (r >= 0)
					if (dk[j][r--] == k)
						++ans;
				--j;
				while (j > i)
					ans += get(j--, k);
				l -= i * BS;
				PER(p, BS-1, l-1)
					if (dk[i][p] == k)
						++ans;
			}
			cout << ans << '\n';
		}
	}
}
