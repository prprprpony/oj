#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
#define SZ(a) ((int)a.size())
const int N = 6e4 + 5;
vector<int> v[N];
struct hs
{
	hash<unsigned long long> hss;
	size_t operator () (const pii & x) const
	{
		return hss(((unsigned long long)x.F) << 32 | x.S);
	}
};
unordered_map<pii,int,hs> ans(N);
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int la[2], j = 1;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d",&a);
		if (i >= 2 && la[0] == la[1] && la[0] == a) {
			v[a].back() = i;
		} else {
			v[a].push_back(i);
			la[j^=1] = a;
		}
	}
	while (m--) {
		int x,y;
		scanf("%d%d",&x,&y);
		if (x > y)
			swap(x,y);
		auto a = ans.insert({{x,y},N});
		int & o = (a.F)->S;
		if (a.S) {
			if (SZ(v[x]) > SZ(v[y]))
				swap(x,y);
			auto r = v[y].begin();
			for (const auto & u : v[x]) {
				if (r != v[y].end() && *r < u)
					r = upper_bound(r, v[y].end(), u);
				if (r != v[y].end())
					o = min(o, *r - u);
				if (r != v[y].begin())
					o = min(o, u - *(r - 1));
			}
			if (o == N)
				o = -1;
		}
		printf("%d\n",o);
	}
}
