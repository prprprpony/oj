#include<cstdio>
#include<cassert>
using namespace std;
void exgcd(int a, int & x, int b, int & y, int & g)
{
    if (b) {
        exgcd(b, y, a % b, x, g);
        y -= a / b * x;
    } else {
        x = 1;
        y = 0;
        g = a;
    }
}
int fl(int a, int b)
{
    if (b < 0)
        return fl(-a, -b);
    if (a >= 0)
        return a / b;
    return (-a + b - 1) / b * -1;
}
int cl(int a, int b)
{
    if (b < 0)
        return cl(-a, -b);
    if (a >= 0)
        return (a + b - 1) / b;
    return -a / b * -1;
}
bool f(int a, int b, int c)
{
    int x0, y0, g;
    exgcd(a, x0, b, y0, g);
    int ap = a / g, bp = b / g;
    for (int i = c; i <= c + a - 1; ++i) {
        if (i % g)
            return false;
        int x1 = x0 * (i / g);
        int y1 = y0 * (i / g);
        int l = cl(-y1, ap), r = fl(x1, bp);
        if (l > r)
            return false;
        int x = x1 - l * bp, y = y1 + l * ap;
        //fprintf(stderr, "l = %d <= r = %d, %d = %d * %d + %d * %d\n", l, r, i, a, x, b, y);
        assert(l <= r);
        assert(x >= 0 && y >= 0);
        assert(i == a * x + b * y);
    }
    return true;

}
int main()
{
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) == 3)
        puts(f(a, b, c) ? "Yes" : "No");
}
