#include<bits/stdc++.h>
using namespace std;
const int N = 106;
typedef pair< string, vector<int> > shit;
#define F first
#define S second
shit p[N];
map<string,int> r;
bool cmp(const shit & x,const shit & y)
{
	for (int i = 0; i < x.S.size() && i < y.S.size(); ++i)
		if (x.S[i] != y.S[i])
			return x.S[i] > y.S[i];
	return x.S.size() > y.S.size();
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> p[i].F >> k;
		p[i].S.resize(k);
		for (int x = 0; x < k; ++x)
			cin >> p[i].S[x];
		sort(p[i].S.begin(),p[i].S.end(),greater<int>());
	}
	sort(p,p+n,cmp);
	int k = r[p[0].F] = 1;
	for (int i = 1; i < n; ++i)
		r[p[i].F] = cmp(p[i-1],p[i]) ? ++k : k;
	string s;
	while (cin >> s)
		cout << r[s] << '\n';
}
