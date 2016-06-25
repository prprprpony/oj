#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    long long X;
    while (scanf("%lld", &X) == 1) {
        /*
(1 + H) * H / 2 = X
H^2 + H - 2X = 0
H = (-1 + sqrt(1 + 8X)) / 2
        */
        printf("%.0f\n", (-1 + sqrt(1 + 8.0 * X)) / 2);
    }
}
