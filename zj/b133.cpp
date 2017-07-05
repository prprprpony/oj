#include<cstdio>
using namespace std;
int main()
{
	int k,n,ans=0;
	scanf("%d%d",&k,&n);
	for (int x = 1; n; n >>= 1, x *= k)
		ans += (n&1) * x;
	printf("%d\n", ans);
}
