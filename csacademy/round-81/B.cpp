#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
bool ok(ll a1,ll l1,ll a2,ll l2)
{
    l1 = (l1 + a2 - 1) / a2;
    l2 = (l2 + a1 - 1) / a1;
    return l1 >= l2;
}
int main()
{
    ll a1,l1,a2,l2,c,x,y;
    cin >> a1 >> l1 >> a2 >> l2 >> c >> x >> y; 
    for (int i = 0; i <= c; ++i)
        if (ok(a1+x*i,l1+y*(c-i),a2,l2)) {
            cout << 1 << endl;
            return 0;
        }
    cout << 0 << endl;
}
