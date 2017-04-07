#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define F first
#define S second
#define EB emplace_back
#define ALL(a) begin(a),end(a)
const int N = 3e5+87;
int n,m,k;
vector<pii> a[N];
ll f[N];
void upd(int i,ll v)
{
	for (; i <= m && f[i] < v; i+=i&-i)
		f[i] = v;
}
ll qry(int i)
{
	ll ret=0;
	for (; i; i^=i&-i)
		ret=max(ret,f[i]);
	return ret;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<k;++i) {
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		a[x].EB(y,w);
	} 
	for(int i=1;i<=n;++i) {
		sort(ALL(a[i]),greater<pii>());
		for(pii v:a[i])
			upd(v.F,v.S+qry(v.F-1));
	}
	printf("%lld\n",qry(m));
}
