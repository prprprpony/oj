#include <cmath>
#include <cstdio>

const double pi = acos(-1.0);

double rad(const double &x)
{
    return x / 180.0 * pi;
}

int main()
{
    double l, a, b;
    scanf("%lf%lf%lf", &l, &a, &b);
    a = rad(a);
    b = rad(b);
    printf("%.2f\n", (int)(l * sin(a) * sin(b) / sin(a+b) * 100.0 + 0.5) / 100.0);

    return 0;
}
