#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        ll c1,c5,c10,c50,v;
        cin >> c1 >> c5 >> c10 >> c50 >> v;
        ll w = c5 * 5 + c10 * 10 + c50 * 50;
        ll t = (v+4)/5*5;
        ll k = t-v;
        ll ans = c1 + w/t*k;
        cout << ans << '\n'; 
    }
}
