#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b) {return b ? gcd(b,a%b) : a;}
int main()
{
    int n,k,g=0,mx=0,a;
    cin >> n >> k;
    while (n--) {
        cin >> a;
        g = gcd(g,a);
        mx = max(mx,a);
    }
    cout << ((k % g == 0 && k <= mx) ? "POSSIBLE\n" : "IMPOSSIBLE\n");
}
