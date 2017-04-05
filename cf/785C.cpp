#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
x*(x-1)/2 + m +x >= n
x^2+x+2(m-n)>=0
x>=(-1+sqrt(1-8(m-n)))/2
*/
int main()
{
    ll n,m;
    cin >> n >> m;
    if (m >= n) {
        cout << n << '\n';
    } else {
        cout << m + (ll)(ceil((-1+sqrt(1.0L-8*(m-n)))/2)) << '\n';
    }
}
