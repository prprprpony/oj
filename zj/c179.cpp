#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+87;
int a[N];
int n,k;
bool ok(int v)
{
    int t=k,w=v;
    for (int i=0;i<n;++i) {
        if(w<a[i]) {
            w=v;
            if (--t<=0)
                return false;
        }
        w-=a[i];
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&k);
    int lo=1,hi=0;
    for (int i=0;i<n;++i) {
        scanf("%d",a+i);
        lo=max(lo,a[i]);
        hi+=a[i];
    }
    while (lo<=hi) {
        int mi=lo+((hi-lo)>>1);
        if (ok(mi))
            hi=mi-1;
        else
            lo=mi+1;
    }
    printf("%d\n",lo);
}
