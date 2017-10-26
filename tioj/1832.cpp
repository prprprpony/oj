#include<cstdio>
using namespace std;
const int N = 1000000 + 987;
long long a[N];
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld",a+i);
        a[i] ^= a[i-1];
    }
    while (q--) {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%lld\n", a[r] ^ a[l-1]);
    }
}
