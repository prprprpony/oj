#include<cstdio>
#include<bitset>
using namespace std;
const int N = 10000 + 6;
bitset<N> d;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while (m--) {
		int a,b;
		scanf("%d%d",&a,&b);
		d.flip(a);
		d.flip(b);
	}
	int k = d.count();
	puts((k == 0 || k == 2) ? "YES" : "NO");
}
