#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point
{
    ll x, y;
    Point(ll a = 0, ll b = 0) : x(a), y(b) {}
    bool operator < (const Point & p) const
    {
        return make_pair(x, y) < make_pair(p.x, p.y);
    }
    Point normal()
    {
        return Point(-y, x);
    }
};
Point operator - (const Point & a, const Point & b)
{
    return Point(a.x - b.x, a.y - b.y);
}
ll operator ^ (const Point & a, const Point & b)
{
    return a.x * b.y - b.x * a.y;
}
ll operator * (const Point & a, const Point & b)
{
    return a.x * b.x + b.y * a.y;
}
ostream& operator << (ostream& out, const Point & p)
{
    out << p.x << ' ' << p.y;
    return out;
}
const int N = 2087;
struct Vector
{
    Point p;
    ll s;
    int i, j;
    ll Area(const Point & q)
    {
        return p * q + s;
    }
    bool operator < (const Vector & u) const
    {
        ll o = p ^ u.p;
        if (o)
            return o > 0;
        return make_pair(i, j) < make_pair(u.i, u.j);
    }
} v[N * N];
Point pt[N];
int ord[N], pos[N];
int main()
{
    int n;
    ll S;
    cin >> n >> S;
    for (int i = 0; i < n; ++i)
        cin >> pt[i].x >> pt[i].y;
    sort(pt, pt + n);
    int vn = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            v[vn++] = {(pt[j] - pt[i]).normal(), pt[i] ^ pt[j], i, j};
    sort(v, v + vn);
    iota(ord, ord + n, 0);
    iota(pos, pos + n, 0);
    for (int i = 0; i < vn; ++i) {
        swap(pos[v[i].i], pos[v[i].j]);
        swap(ord[pos[v[i].i]], ord[pos[v[i].j]]);
        int x = 0;
        for (int k = 1 << __lg(n); k; k >>= 1)
            if (x + k < n && v[i].Area(pt[ord[x + k]]) <= 2 * S)
                x += k;
        if (v[i].Area(pt[ord[x]]) == 2 * S) {
            cout << "Yes\n";
            cout << pt[v[i].i] << "\n";
            cout << pt[v[i].j] << "\n";
            cout << pt[ord[x]] << "\n";
            return 0;
        }
    }
    cout << "No\n";
}
