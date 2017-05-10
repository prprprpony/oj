#include<cstdio>
using namespace std;
int main()
{
	int k,s=0;
	scanf("%d",&k);
	for (int i = 0; i <= k && s >= (1<<i) - 1; ++i) {
		int x;
		scanf("%d",&x);
		s += x * (1<<i);
	}
	printf("%d\n",s+1);
}
