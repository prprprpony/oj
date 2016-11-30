#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a), __e = (b); i < __e; ++i)
#define RP(i,b) REP(i,0,b)
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 56, len = 1.12e6;
int n, m;
double z[maxn];
char s[len];
int rt[len];
double solve(int l, int r)
{
	if (r - l == 2)
		return z[1];
	vector<double> c;
	bool op = s[rt[l+1]+1] == '*';
	for (int i = l + 1; i < r; i = rt[i] + 2)
		c.push_back(solve(i, rt[i]));
	double ret;
	if (op) { // multiplication
		double sum = z[c.size()];
	   	ret = 1.0;
		sort(c.begin(), c.end());
		int k = c.size();
		for (int i = 0; i < k; ++i) {
			double x = min(c[i], sum / (k - i));
			ret *= x;
			sum -= x;
		}
	} else {  // addition
		ret = 0.0;
		for (auto x : c)
			ret += x;
		ret = min(ret, z[c.size()]);
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	REP(i,1,n+1)
		cin >> z[i];
	cin >> s;
	stack<int> st;
	for (m = 0; s[m]; ++m)
		if (s[m] == '(')
			st.push(m);
		else if (s[m] == ')') {
			rt[st.top()] = m;
			st.pop();
		}
	cout << setprecision(15) << fixed << solve(0, rt[0]) << '\n';
}
