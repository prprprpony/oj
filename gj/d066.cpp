#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 10;
int g[maxn];

struct Edge
{
    int from;
    int to;
    int dist;
    Edge(int u, int v, int d) : from(u), to(v), dist(d) {};
    Edge() {};
    friend bool operator < (const Edge &a, const Edge &b) {return a.dist < b.dist;}
};

int find(int x)
{
    return g[x] != x ? g[x] = find(g[x]) : x;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    map<string, int> cid;
    string cn[m];
    Edge e[m];
    string s, c;
    pair<int, int> opt[n-1];
    for (int i = 0; i < n; i++) {
        cin >> s;
        cid[s] = i;
        cn[i] = s;
        g[i] = i;
    }
    for (int i = 0, d; i < m; i++) {
        cin >> s >> c >> d;
        int a = cid[s], b = cid[c];
        if (a > b)
            swap(a, b);
        e[i] = Edge(a, b, d);
    }
    sort(e, e + m);
    int cost = 0;
    for (int i = 0, a, b, o = 0; i < m && o < n-1; i++) {
        a = find(e[i].from);
        b = find(e[i].to);
        if (a != b) {
            opt[o] = pair<int, int>(e[i].from, e[i].to);
            o++;
            cost += e[i].dist;
            g[a] = b;
        }
    }
    sort(opt, opt + n- 1);
    for (int i = 0; i < n-1; i++) {
            cout << "(" << cn[opt[i].first] << " " << cn[opt[i].second] << ")";
    }
    cout << endl << cost << endl;

    return 0;
}
