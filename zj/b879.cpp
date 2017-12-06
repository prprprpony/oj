#include<bits/stdc++.h>
using namespace std;
const int N = 1.1e6;
int n,a[N],b[N],f[N],c[N];
void init()
{
    memset(f+1,0,n*sizeof(f[0]));
}
void add(int i)
{
    for (;i<=n;i+=i&-i)
        ++f[i];
}
int qry(int i)
{
    int ans = 0;
    for (;i;i^=i&-i)
        ans += f[i];
    return ans;
}
int qry(int i,int j)
{
    return qry(j) - qry(i-1);
}
int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
        scanf("%d",a+i);
    copy_n(a,n,b);
    sort(b,b+n);
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(b,b+n,a[i]) - b + 1;
        c[i] = qry(a[i]+1,n);
        add(a[i]);
    }
    init();
    long long ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        ans += qry(a[i]) * 1LL * c[i];
        add(a[i]);
    }
    printf("%lld\n",ans);
}
