#include <cstdio>
using namespace std;
const int maxn = 11;
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
    fraction operator + (const fraction & f)
    {
        return fraction(a * f.b + f.a * b, b * f.b);
    }
    fraction operator + (int x)
    {
        return *this + fraction(x, 1);
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

fraction f[maxn];


int main(void)
{
    f[1] = 1;
    for (int i = 2; i < maxn; ++i)
        f[i] = (i & 1) ? 1 / f[i - 1] : f[i >> 1] + 1;

    puts("$$");
    fputs("\\begin{array}{c", stdout);
    for (int i = 1; i < maxn; ++i);
        fputs("|c", stdout);
    puts("}");

    putchar('k');
    for (int i = 1; i < maxn; ++i)
        printf(" & %d", i);
    puts(" \\\\ \\hline");

    fputs("f(k)",stdout);
    for (int i = 1; i < maxn; ++i) {
        fputs(" & ", stdout);
        if (f[i].a % f[i].b)
            printf("\\frac %d %d", f[i].a, f[i].b);
        else
            printf("%d", f[i].a);
    }
    puts(" \\\\");
    puts("\\end{array}");
    puts("$$");

    return 0;
}
