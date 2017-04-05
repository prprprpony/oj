#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a,b;
    scanf("%lld%lld",&a,&b);
    int i;
    for (i = 0; a <= b; a *= 3, b *= 2,++i);
    printf("%d\n",i);
}
