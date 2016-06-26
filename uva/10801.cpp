#include <bits/stdc++.h>
#define MAXN 5
#define MAXF 100
#define INF (int)1e9
#define I second
#define D first
using namespace std;
typedef pair<int, int> pii;
int t[MAXN];
int g[MAXF][MAXF];
int d[MAXF];
bool done[MAXF];
int main()
{
    int n, k;
    while (cin >> n >> k) {
        for (int i = 0; i < MAXF; i++)
            for (int j = 0; j < MAXF; j++)
                g[i][j] = INF;
        for (int i = 0; i < n; i++)
            cin >> t[i];
        while (cin.get() != '\n');
        for (int i = 0; i < n; i++) {
            string buf;
            getline(cin, buf);
            stringstream ss(buf);
            int f;
            vector<int> v;
            while (ss >> f) {
                for (int j = v.size() - 1; j >= 0; j--)
                    g[v[j]][f] = g[f][v[j]] =  min(g[f][v[j]], (f - v[j]) * t[i] + (v[j] != 0 ? 60 : 0));
                v.push_back(f);
            }
        }
        for (int i = 1; i < MAXF; i++)
            d[i] = INF;
        d[0] = 0;
        memset(done, 0, sizeof(done));

        int x = 0;
        while (1) {
            done[x] = true;
            if (x == k)
                break;
            bool first = true;
            int nxt = 0;
            for (int j = 1; j < MAXF; j++) {
                if (!done[j]) {
                    if (d[x] + g[x][j] < d[j])
                        d[j] = d[x] + g[x][j];
                    if (first || d[j] < d[nxt]) {
                        nxt = j;
                        first = false;
                    }
                }
            }
            if (nxt == 0 || d[nxt] == INF)
                break;
            x = nxt;
        }
        if (d[k] == INF)
            puts("IMPOSSIBLE");
        else
            printf("%d\n", d[k]);
    }
    return 0;
}
