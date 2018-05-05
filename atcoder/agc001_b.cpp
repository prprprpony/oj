#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(ll a,ll b)
{
    if (!a)
        return -b;
    return b/a * 2 * a + solve(b % a,a);
}
int main()
{
    ll n,x;
    cin >> n >> x;   
    cout << n + solve(x,n-x) << endl;
}
