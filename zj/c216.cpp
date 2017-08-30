#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5;
struct node
{
	int v;
	vector<int> ct;
	node * lc, * rc;
	node(const vector<int>& b,int l,int r,const vector<int>& a)
	{
		int n = a.size();
		int m = (l + r) / 2;
		v = b[m];
		ct.resize(n);
		vector<int> al,ar;
		for (int i = 0; i < n; ++i) {
			ct[i] = i ? ct[i-1] : 0;
			if (a[i] <= v) {
				++ct[i];
				al.push_back(a[i]);
			} else if (a[i] > v) {
				ar.push_back(a[i]);
			}
		}
		lc = rc = nullptr;
		if (l == r)
			return;
		if (al.size())
			lc = new node(b,l,m,al);
		if (ar.size())
			rc = new node(b,m+1,r,ar);
	}
	node(const vector<int> & a)
	{
		vector<int> b(a);
		sort(b.begin(),b.end());
		b.erase(unique(b.begin(),b.end()),b.end());
		new(this) node(b,0,b.size()-1,a);
	}
	int rk(int i,int j,int k)
	{
		if (i > j)
			return 0;
		int l = i ? ct[i-1] : 0;
		int r = ct[j] - 1;
		if (v <= k)
			return r - l + 1 + (rc ? rc->rk(i-l,j-ct[j],k) : 0);
		else
			return lc ? lc->rk(l,r,k) : 0;
	}
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector<int> a(n);
	vector<long long> s;
	for (int & x : a) {
		cin >> x;
		s.push_back((s.size() ? s.back() : 0) + x);
	}
	node * rt = new node(a);
	int k = 0;
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int x;
			cin >> x;
			k = (k + x) % N;
		} else {
			int l, r;
			cin >> l >> r;
			--l,--r;
			long long ans = s[r] - (l ? s[l-1] : 0), x = rt->rk(l,r,N-k);
			ans += x*k+(k-N)*(r-l+1-x);
			cout << ans << '\n';
		}
	}
}
