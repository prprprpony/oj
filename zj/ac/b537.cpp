#include <cstdio>
using namespace std;
int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
struct fraction
{
    int a, b;
    fraction(int i = 0, int j = 1) : a(i), b(j)
    {
        int g = gcd(a, b);
        if (g > 1) {
            a /= g;
            b /= g;
        }
    }
    bool operator < (const fraction & f) const 
    {
        return a * f.b < f.a * b;
    }
    bool operator < (int x) const
    {
        return *this < fraction(x, 1);
    }
    bool operator > (const fraction & f) const 
    {
        return f < *this;
    }
    bool operator > (int x) const
    {
        return *this > fraction(x, 1);
    }
    fraction operator - (int x)
    {
        return fraction(a - x * b, b);
    }
    fraction operator / (const fraction & f)
    {
        return fraction(a * f.b, b * f.a);
    }
};

fraction operator / (int x, const fraction & f)
{
    return fraction(x, 1) / f;
}

long long find(fraction f) {
    if (f > 1)
        return 2 * find(f - 1);
    else if (f < 1)
        return 1 + find(1 / f);
    else
        return 1;
}

int main(void)
{
    fraction f;
    while (scanf("%d%d", &f.a, &f.b) == 2)
        printf("%lld\n", find(f));
    return 0;
}
