#include<bits/stdc++.h>
using namespace std;
#define SZ(a) ((int)a.size())
const int N = 3e6 + 87, M = 1e9 + 9, P = 0xdefaced;
int pw[N];
int mul(int a,int b) {return a * 1LL * b % M;}
int add(int a,int b) {return (a += b) < M ? a : a - M;}
int sub(int a,int b) {return (a -= b) < 0 ? a + M : a;}
void pre()
{
	pw[0] = 1;
	for (int i = 1; i < N; ++i)
		pw[i] = mul(pw[i-1], P);
}
struct hs
{
	int h[N];
	void init(const string & s)
	{
		h[0] = 0;
		for (int i = 1; i <= SZ(s); ++i)
			h[i] = add(mul(h[i-1], P), s[i-1] + 287);
	}
	int val(int i,int j)
	{
		++j;
		return sub(h[j], mul(h[i], pw[j-i]));
	}
} a,b;
bool solve(string & s, string & t)
{
	for ( ; SZ(s) && s.back() != '*'; s.pop_back(), t.pop_back())
		if (!SZ(t) || s.back() != t.back())
			return 0;
	if (!SZ(s))
		return !SZ(t);
	int i, j = 0;
	for (; s[j] != '*'; ++j)
		if (j >= SZ(t) || t[j] != s[j])
			return 0;
	s = s.substr(j);
	t = t.substr(j);
	a.init(t);
	b.init(s);
	i = j = 0;
	while (j < SZ(s)) {
		if (s[j] == '*') {
			++j;
			continue;
		}
		int k = j;
		while (k+1 < SZ(s) && s[k+1] != '*')
			++k;
		int n = k - j;
		while (i + n < SZ(t) && a.val(i,i+n) != b.val(j,k))
			++i;
		if (i + n == SZ(t))
			return 0;
		i += n + 1;
		j += n + 1;
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	pre();
	string s,t;
	int k;
	cin >> k;
	while (k--) {
		cin >> s >> t;
		cout << (solve(s,t) ? "Yes" : "No") << '\n';
	}
}
