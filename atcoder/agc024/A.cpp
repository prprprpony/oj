#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a,b,c,k;
    cin >> a >> b >> c >> k;
    cout << (a-b) * (k%2 ? -1 : 1) << endl;
}
