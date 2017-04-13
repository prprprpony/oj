#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1001;
ll f[N];
int main()
{
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i < N; ++i) {
        f[i] = 2 * f[i-1] + 1;
		for (int j = 1; j <= i - 1 && (1LL<<j) < f[i]; ++j)
			f[i] = min(f[i], 2 * ((1LL<<j) - 1 + f[i-1-j]) + 1);
	}
    int n,kase=0;
    while (scanf("%d",&n) == 1)
        printf("Case %d: %lld\n",++kase,f[n]);
}
