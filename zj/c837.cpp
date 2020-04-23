#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}
struct point
{
    double key;
    int x, y;
    bool operator < (const point & p) const
    {
        return key < p.key;
    }
};
int main()
{
    int n, P, Q;
    scanf("%d%d%d", &n, &P, &Q);
    const double S = P * 1. / Q;
    vector<point> v(n);
    for (auto & p : v)
        scanf("%d%d", &p.x, &p.y);
    auto ok = [&] (double k) {
        const double cl = S - k, cr = S + k;
        for (auto & a : v)
            a.key = cl * a.x - a.y;
        sort(v.begin(), v.end());
        for (int i = 1; i < n; ++i)
            if (cr * v[i - 1].x - v[i - 1].y >= cr * v[i].x - v[i].y)
                return true;
        return false;
    };
    double l = 0, r = 1;
    while (!ok(r)) {
        l = r;
        r *= 2;
    }
    while (abs(r - l) > 1e-6) {
        double m = (l + r) / 2;
        if (ok(m))
            r = m;
        else
            l = m;
    }
    ok(r);
    tuple<double, double, int, int> ans = {DBL_MAX, 0, 0, 0};
    for (int i = 0; i + 1 < n; ++i) {
        int j = i + 1;
        int dx = v[j].x - v[i].x;
        int dy = v[j].y - v[i].y;
        double sl = dy * 1. / dx;
        double d = abs(sl - S);
        ans = min(ans, make_tuple(d, -sl, dx, dy));
    }
    int dx = get<2>(ans), dy = get<3>(ans);
    int g = gcd(dx, dy);
    dx /= g, dy /= g;
    if (dx < 0)
        dx = -dx, dy= -dy;
    printf("%d/%d\n", dy, dx);
}
