#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
#define SZ(a) ((int)a.size())
const int N = 1e5+87;
int n,k;
pii a[N];
bool ok(int v)
{
    multiset<int> s;
    int c=0;
    for (int i=0;i<n;++i) {
        while (SZ(s) && *s.begin() <= a[i].F)
            s.erase(s.begin());
        s.insert(a[i].S);
        if (SZ(s)>v) {
            if (++c>k)
                return false;
            s.erase(next(s.rbegin()).base());
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    if (k >= n) {
        cout << "0\n";
        return 0;
    }
    for (int i = 0; i < n; ++i)
        cin >> a[i].F >> a[i].S;
    sort(a,a+n);
    int lo = 1, hi = n-k;
    while (lo <= hi) {
        int mi = (lo+hi)/2;
        if (ok(mi))
            hi=mi-1;
        else
            lo=mi+1;
    }
    cout<<lo<<'\n';
}
