#include <stdio.h>
#define N 100
int f1[N], f2[N];
int mex(int a,int b)
{
	int i = 0;
	for (; i == a || i == b; ++i);
	return i;
}
int gf1(long long n)
{
	if (n < N)
		return f1[n];
	if (n&1)
		return 0;
	return mex(gf1(n-1), gf1(n/2));
}
int gf2(long long n)
{
	if (n < N)
		return f2[n];
	return n&1^1;
}
int main()
{
	for (int i = 1; i < N; ++i)
		if (i&1) {
			f1[i] = !f1[i-1];
		} else {
			f1[i] = mex(f1[i-1], f1[i/2]);
		}
	for (int i = 1; i < N; ++i)
		if (i&1) {
			f2[i] = !f2[i-1];
		} else {
			f2[i] = mex(f2[i-1], 0);
		}
	long long n;
	int k;
	while (scanf("%lld%d",&n,&k) == 2)
		printf("%d\n", k == 1 ? gf1(n) : gf2(n));
}
