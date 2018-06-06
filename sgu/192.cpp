#include<bits/stdc++.h>
using namespace std;
typedef double val;
const val eps = 1e-6, inf = 1e9;
bool eq(val a, val b)
{
    return fabs(a-b) < eps;
}
bool lt(val a, val b)
{
    return b-a >= eps;
}
bool le(val a,val b)
{
    return lt(a,b) || eq(a,b);
}
bool gt(val a,val b)
{
    return lt(b,a);
}
bool ge(val a,val b)
{
    return le(b,a);
}
typedef pair<val,val> pt;
#define X first
#define Y second
istream& operator >> (istream&in,pt&p)
{
    in >> p.X >> p.Y;
    return in;
}
pt operator + (const pt & a, const pt & b)
{
    return {a.X+b.X,a.Y+b.Y};
}
pt operator - (const pt & a, const pt & b)
{
    return {a.X-b.X,a.Y-b.Y};
}
val operator ^ (const pt & a, const pt & b)
{
    return a.X * b.Y - a.Y * b.X;
}
typedef pair<pt,pt> seg;
val inc(seg a,seg b)
{
    if (eq((a.Y-a.X) ^ (b.Y-b.X), 0))
        return -1;
/*
    (t a.X.X + (1-t) a.Y.X, t a.X.Y + (1-t) a.Y.Y)
    (s b.X.X + (1-s) b.Y.X, s b.X.Y + (1-s) b.Y.Y)

    (a.X.X - a.Y.X) t + a.Y.X = (b.X.X - b.Y.X) s + b.Y.X
    (a.X.Y - a.Y.Y) t + a.Y.Y = (b.X.Y - b.Y.Y) s + b.Y.Y
*/
    val a0 = (a.X.X - a.Y.X), b0 = -(b.X.X - b.Y.X), c0 = b.Y.X - a.Y.X;
    val a1 = (a.X.Y - a.Y.Y), b1 = -(b.X.Y - b.Y.Y), c1 = b.Y.Y - a.Y.Y;
/*
    a0 t + b0 s = c0
    a1 t + b1 s = c1
*/
    val t,s;
    if (eq(a1,0)) {
        s = c1/b1;
        t = (c0 - b0 * s) / a0;
    } else if (eq(b1,0)) {
        t = c1/a1;
        s = (c0 - a0 * t) / b0;
    } else {
        s = (a1 * c0 - a0 * c1) / (a1 * b0 - a0 * b1);
        t = (c0 - b0 * s) / a0;
    }
    if (le(0,s) && le(s,1) && le(0,t) && le(t,1)) {
        return t * a.X.X + (1 - t) * a.Y.X;
    } else {
        return -1;
    }
}
val f(seg s,val x)
{
    if (!((le(s.X.X,x) && le(x,s.Y.X)) || (le(s.Y.X,x) && le(x,s.X.X))))
        return inf;
    val y = s.X.Y + (x - s.X.X) * (s.Y.Y - s.X.Y) / (s.Y.X - s.X.X);
    if (!((le(s.X.Y,y) && le(y,s.Y.Y)) || (le(s.Y.Y,y) && le(y,s.X.Y))))
        return inf;
    return y;
}
const int N = 333;
const string colors = "RGB";
seg s[N];
int co[N];
val ans[3];
int main()
{
    int n;
    cin >> n;
    vector<val> ev;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> s[i].X >> s[i].Y >> c;
        if (s[i].X.X == s[i].Y.X) {
            --n, --i;
            continue;
        }
        co[i] = colors.find(c);
        ev.push_back(s[i].X.X);
        ev.push_back(s[i].Y.X);
        for (int j = 0; j < i; ++j) {
            auto x = inc(s[i],s[j]);
            if (x >= 0)
                ev.push_back(x);
        }
    }
    sort(begin(ev),end(ev));
    ev.erase(unique(begin(ev),end(ev)),end(ev));
    val lx = -98;
    for (auto x : ev) {
        int c = 0;
        auto y = inf, mid = (x + lx) / 2;
        for (int i = 0; i < n; ++i) {
            auto v = f(s[i],mid);
            if (lt(v, y)) {
                y = v;
                c = co[i];
            }
        }
        if (lt(y,inf))
            ans[c] += x - lx;
        lx = x;
    }
    for (int i = 0; colors[i]; ++i)
        cout << colors[i] << ' ' << fixed << setprecision(2) << ans[i] << endl;
}
