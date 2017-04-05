#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,mnr=2e9,mxl=0,ans=0;
    scanf("%d",&n);
    for (int i=0;i<n;++i) {
        int l,r;
        scanf("%d%d",&l,&r);
        mxl = max(mxl,l);
        mnr = min(mnr,r);
    }
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        int l,r;
        scanf("%d%d",&l,&r);
        ans = max(ans,max(l - mnr, mxl - r));
    }
    printf("%d\n",ans);
}
