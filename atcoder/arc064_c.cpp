#include<bits/stdc++.h>
using namespace std;
const int N = 1087;
const double inf = 1e15;
struct circ
{
    int x,y,r;
} c[N];
double d[N];
bool vis[N];
double dist(int u,int v)
{
    long long dx = c[u].x-c[v].x, dy = c[u].y-c[v].y, rr = c[u].r + c[v].r;
    long long w = dx * dx + dy * dy;
    if (w <= rr * rr)
        return 0;
    return sqrt(w) - rr;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> c[0].x >> c[0].y >> c[1].x >> c[1].y >> n;
    c[0].r = c[1].r = 0;
    n += 2;
    for (int i = 2; i < n; ++i)
        cin >> c[i].x >> c[i].y >> c[i].r;
    fill_n(d,n,inf);
    d[0] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1;
        double mn = inf;
        for (int j = 0; j < n; ++j)
            if (!vis[j] && d[j] < mn) {
                mn = d[j];
                u = j;
            }
        if (u == 1) {
            cout << fixed << setprecision(16) << d[u] << endl;
            return 0;
        }
        vis[u] = 1;
        for (int j = 0; j < n; ++j)
            if (!vis[j])
                d[j] = min(d[j], d[u] + dist(u,j));
    }
}
