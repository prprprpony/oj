#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
int main()
{
    int t, r;
    double p;
    double high, low, mid, theta, phi, ratio, k;
    bool first = true;
    cin >> t;
    while (t--) {
        cin >> r >> p;
        low = 0.0;
        high = sqrt(2.0) * r;
        while (fabs(high - low) > eps) {
            mid = (high + low) / 2.0;
            k = pow(mid / r, 2.0);
            theta = acos(1.0 - k / 2.0);
            phi = acos(mid / r / 2.0);
            ratio = (theta - sin(theta) + k * phi) / pi;
            if (ratio > p)
                high = mid;
            else
                low = mid;
        }
        if (!first)
            putchar('\n');
        else
            first = false;
        printf("R = %d, P = %.2f, Rope = %.2f\n", r, p, mid);
    }
    return 0;
}
