#include <bits/stdc++.h>
#define MAXN 100001
#define U first
#define V second
using namespace std;
typedef pair<int, int> pii;
pii edges[MAXN];
int qry[MAXN];
bool ruin[MAXN];
int ans[MAXN];
struct DS
{
    vector<int> p;
    int setn;
    DS(int n) {
        p.resize(n + 1);
        for (int i = 1; i <= n; i++)
            p[i] = i;
        setn = n;
    }
    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    void Union(int x, int y) {
        x = find(x); y = find(y);
        if (x != y) {
            p[x] = y;
            setn--;
        }
    }
};
int main()
{
    int n, m, q;
    cin >> n >> m;
    DS s(n);
    for (int i = 1; i <= m; i++)
        cin >> edges[i].U >> edges[i].V;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> qry[i];
        ruin[qry[i]] = true;
    }
    for (int i= 1; i <= m; i++)
        if (!ruin[i])
            s.Union(edges[i].U, edges[i].V);
    for (int i = q-1; i >= 0; i--) {
        ans[i] = s.setn;
        s.Union(edges[qry[i]].U, edges[qry[i]].V);
    }
    for (int i = 0; i < q - 1; i++)
        cout << ans[i] << ' ';
    cout << ans[q-1] << endl;
}
