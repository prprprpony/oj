#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
a1 x + b1 = a2 y + b2
a1 x - a2 y = b2 - b1

a1 x0 - a2 y0 = a1 x - a2 y
a1/g (x0 - x) = a2/g (y0 - y)

x = x0 - k dx >= 0
x0 >= dx * k;
k <= floor(x0/dx)

k >= 0
L <= a1 (x0 + k * dx) + b1 <= R
ceil( ((L-b1)/a1 - x0)/dx ) <= k <= floor( ((R-b1)/a1-x0)/dx )


(L-b1-a1x0)/a1dx
*/
void exgcd(ll a,ll&x,ll b,ll&y,ll&g)
{
    if (b == 0) {
        y = 0;
        g = abs(a);
        x = g/a;
    } else {
        exgcd(b,y,a%b,x,g);
        y -= a/b*x;
    }
}
ll fl(ll a,ll b)
{
    if (b < 0)
        b=-b,a=-a;
    if (a >= 0)
        return a/b;
    return ((-a+b-1)/b)*(-1);
}
ll cl(ll a,ll b)
{
    if (b < 0)
        b=-b,a=-a;
    if (a >= 0)
        return (a+b-1)/b;
    return a/b;
}
ll a1,b1,a2,b2,L,R;
int main()
{
    cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
    ll x0,y0,g;
    exgcd(a1,x0,-a2,y0,g);
    ll c = b2 - b1;
    if (c % g) {
        cout << "0\n";
        return 0;
    }
    x0 *= c/g, y0 *= c/g;
    ll dx = a2/g, dy = a1/g;
    ll dt = min(fl(x0,dx),fl(y0,dy));
    x0 -= dt * dx, y0 -= dt * dy;
    ll l = max(0ll,cl(L-b1-a1*x0,a1*dx)), r = fl(R-b1-a1*x0,a1*dx);
    if (r < l)
        cout << "0\n";
    else
        cout << r - l + 1 << endl;
}
