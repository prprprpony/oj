#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
#include <limits>
#include <cmath>
using namespace std;

struct point
{
    double x, y;
    bool operator < (const point & a) const
    {
        return x < a.x || (x == a.x && y < a.y);
    }

    bool operator > (const point & a) const 
    {
        return x > a.x || (x == a.x && y > a.y);
    }

    bool operator == (const point & a) const
    {
        return  x == a.x && y == a.y;
    }
};
typedef vector<point> point_set;

vector<point_set> kingdoms;
vector<point_set> convex_hulls;
vector<int> rightmost;
vector<double> areas;

inline double slope(const point & a, const point & b)
{
    return a.x - b.x != 0.0 ? (a.y - b.y) / (a.x - b.x) : numeric_limits<double>::max();
}

void Andrew_s_Monotone_Chain(point_set & ps, point_set & ch, int & rm)
{
    sort(ps.begin(), ps.end()); 
    // [] (point a, point b) -> bool {return a.x < b.x || (a.x == b.x && a.y < b.y);}
    ch.clear();
    for (const auto & p : ps) {
        while (ch.size() > 1 && slope(ch.back(), p) < slope(ch[ch.size() - 2], ch.back()))
            ch.pop_back();
        ch.push_back(p);
    }
    rm = ch.size() - 1;
    int s = ch.size();
    for (int i = ps.size() - 2; i >= 0; --i) {
        while (ch.size() > s && slope(ch.back(), ps[i]) < slope(ch[ch.size() - 2], ch.back()))
            ch.pop_back();
        ch.push_back(ps[i]);
    }
}

bool read_point(point & p)
{
    return scanf("%lf%lf", &p.x, &p.y) == 2;
}

double area(const point_set & ch) // ch is a convex hull whose points are (anticlockwise || clockwise) ordered && ch.front() == ch.back()
{
    double a = 0.0;
    for (int i = 0; i < ch.size() - 1; ++i)
        a += ch[i].x * ch[i + 1].y - ch[i].y * ch[i + 1].x;
    return fabs(a) / 2.0;
}

bool inside(const point_set & ch, const int & rm, const point & missile)
{
    if (missile < ch[0] || missile > ch[rm])
        return false;
    // ch[0] <= missile <= ch[rm]
    point_set::const_iterator it = lower_bound(ch.begin(), ch.begin() + rm + 1, missile);
    if (*it == missile)
        return true;
    if ((it->y - (it - 1)->y) * (missile.x - it->x) == (it->x - (it - 1)->x) * (missile.y - it->y))
        return true;

    double m = slope(*it, *(it - 1));
    double y = m * (missile.x - it->x) + it->y;
#ifdef PP
    printf("missile(%fn,%f)\n", missile.x, missile.y);
    printf("down(%f,%f)\n", missile.x, y);
#endif

    if (y > missile.y)
        return false;
    // (y - y0) / (x - x0) = m
    // y = m(x - x0) + y0

    it = lower_bound(ch.begin() + rm,  ch.end(), missile, greater<point>());
    if (*it == missile)
        return true;
    if ((it->y - (it + 1)->y) * (missile.x - it->x) == (it->x - (it + 1)->x) * (missile.y - it->y))
        return true;

    m = slope(*it, *(it + 1));
    y = m * (missile.x - it->x) + it->y;
#ifdef PP
    printf("up(%f,%f)\n", missile.x, y);
#endif
    if (y < missile.y)
        return false;
    return true;
}

int main()
{
    int N;
    while (scanf("%d", &N) == 1 && N >= 3) {
        kingdoms.emplace_back(N);
        convex_hulls.resize(convex_hulls.size() + 1);
        rightmost.resize(rightmost.size() + 1);

        for_each(kingdoms.back().begin(), kingdoms.back().end(), read_point);
        Andrew_s_Monotone_Chain(kingdoms.back(), convex_hulls.back(), rightmost.back());
        areas.push_back(area(convex_hulls.back()));
#ifdef PP
        printf("K%d\n", kingdoms.size());
        for (auto p : convex_hulls.back())
            printf("(%f,%f)\n", p.x, p.y);
        printf("area = %f\n", areas.back());
#endif
    }

    point missile;
    vector<bool> exterminated(kingdoms.size());
    while (read_point(missile))
        for (int i = 0; i < kingdoms.size(); ++i)
            if (!exterminated[i] && inside(convex_hulls[i], rightmost[i], missile)) {
                exterminated[i] = true;
#ifdef PP
                printf("K%d exterminated\n", i+1);
#endif
                break;
            }
    double ans = 0.0;
    for (int i = 0; i < kingdoms.size(); ++i)
        if (exterminated[i])
            ans += areas[i];
    printf("%.2f\n", ans);
}
