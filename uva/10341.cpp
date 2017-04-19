#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
#define F(x) (p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u)
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int p,q,r,s,t,u;
    while (cin >> p >> q >> r >> s >> t >> u) {
        if (F(0) < 0 || F(1) > 0) {
            puts("No solution");
            continue;
        }
        double lo = 0, hi = 1;
        while (lo + eps < hi) {
            double mi = (lo + hi) / 2;
            if (F(mi) > 0)
                lo = mi;
            else
                hi = mi;
        }
        printf("%.4f\n",hi);
    }
}
