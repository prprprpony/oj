#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+87;
int a[N],c[N/2];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",a+i);
    set<int> b;
    for (int i=0;i<n/2;++i) {
        int x;
        scanf("%d",&x);
        b.insert(x);
    }
    for (int i=1,k=0;k<n/2;++k) {
        for(;b.count(i);++i);
        c[k]=i++;
    }
    sort(c,c+n/2,
         [&] (int x,int y) -> bool {
            return a[x] > a[y] || (a[x] == a[y] && x < y);
         }
    );
    ll ans=0;
    for (int i=0;i<n/2;++i) {
//cout << "i=" << i << '\n';
//cout << c[i] << '\n';
        auto it=b.lower_bound(c[i]);
        if (it!=b.begin()) {
            --it;
            ans+=a[c[i]];
//cout << *it << '\n';
            b.erase(it);
        } else {
            ans-=a[c[i]];
//cout << *prev(b.end()) << '\n';
            b.erase(prev(b.end()));
        }
    }
    printf("%lld\n",ans);
}
