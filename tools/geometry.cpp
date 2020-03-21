#include <bits/stdc++.h>
using namespace std;
#define SZ(a) ((int)(a).size())
#define ALL(a) begin(a), end(a)
#define PB push_back

// copied and modified from bcw_codebook
// list of algorithms: point operations, convex hull (Andrew's monotone chain), minkowski sum
#define x first
#define y second
#define cpdd const pdd
typedef long long val_t;
// typedef __int128 val_t;
// typedef double val_t;
// typedef long double val_t;
// typedef __float128 val_t;
struct pdd : pair<val_t, val_t> {
    using pair<val_t, val_t>::pair;

    pdd operator + (cpdd &p) const {
        return {x+p.x, y+p.y};
    }

    pdd operator - () const {
        return {-x, -y};
    }

    pdd operator - (cpdd &p) const {
        return (*this) + (-p);
    }

    pdd operator * (val_t f) const {
        return {f*x, f*y};
    }

    val_t operator * (cpdd &p) const {
        return x*p.x + y*p.y;
    }
};
double abs(cpdd &p) { return hypot(p.x, p.y); }
double arg(cpdd &p) { return atan2(p.y, p.x); }
val_t cross(cpdd &p, cpdd &q) {const val_t L = 1; return p.x*L*q.y - p.y*L*q.x; }
val_t cross(cpdd &p, cpdd &q, cpdd &o) { return cross(p-o, q-o); }
pdd operator * (val_t f, cpdd &p) { return p*f; } // !! Not f*p !!
vector<pdd> convex_hull(vector<pdd> pt){
    sort(ALL(pt));
    pt.erase(unique(ALL(pt)), end(pt));
    int n = pt.size(), top = 0;
    if (n <= 2)
        return pt;
    vector<pdd> stk(2 * n);
    for (int i = 0; i < n; i++){
        while (top >= 2 && cross(stk[top - 1], pt[i], stk[top - 2]) <= 0)
            top--;
        stk[top++] = pt[i];
    }
    for (int i = n - 2, t = top + 1; i >= 0; i--) {
        while (top >= t && cross(stk[top - 1], pt[i], stk[top - 2]) <= 0)
            top--;
        stk[top++] = pt[i];
    }
    stk.resize(top - 1);
    return stk;
}
vector<pdd> minkowski_bruteforce(vector<pdd> a, vector<pdd> b)
{
    vector<pdd> c;
    int n = a.size(), m = b.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            c.PB(a[i] + b[j]);
    return convex_hull(c);
}
// copied and modified from https://www.w3xue.com/exp/article/20192/20858.html
vector<pdd> minkowski(vector<pdd> a, vector<pdd> b) 
{
    a = convex_hull(a);
    b = convex_hull(b);
    a.PB(a[0]);
    b.PB(b[0]);
    int na = a.size(), nb = b.size();
    vector<pdd> q(na + nb + 1);
    int top = -1;
    q[++top] = a[0] + b[0];
    int i = 0, j = 0;
    while(i + 1 < na && j + 1 < nb) {
        auto n1 = (a[i] + b[j + 1]) - q[top], n2 = (a[i + 1] + b[j]) - q[top];
        if(cross(n1, n2) < 0)
            q[++top] = a[i + 1] + b[j], i++;
        else
            q[++top] = a[i] + b[j + 1], j++;
    }
    for(; i < na; i++) q[++top] = a[i] + b[nb - 1];
    for(; j < nb; j++) q[++top] = b[j] + a[na - 1];
    // assert(top + 1 == q.size());
    // TODO: the assertion below failed
    // assert(q == convex_hull(q));
    return convex_hull(q);
}
