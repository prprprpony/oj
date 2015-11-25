#include <iostream>
#include <algorithm>
#include <cmath>
#define SQR(x) ((x) * (x))
using namespace std;
const int maxn = 1000;
const long long inf = 9e18;
long long x[maxn], y[maxn], p[maxn], ans;
bool vis[maxn];
int t, n;
long long edge;
int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        ans = 0;
        for (int i = 0; i < n; i++) {
            p[i] = inf;
            vis[i] = false;
        }
        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        for (int i = 0, c = 0, nc; i < n - 1; i++) {
            vis[c] = true;
            edge = inf;
            for (int j = 0; j < n; j++) {
                if (!vis[j]) {
                    p[j] = min(p[j], SQR(x[c]-x[j]) + SQR(y[c]-y[j]));
                    if (edge > p[j]) {
                        edge = p[j];
                        nc = j;
                    }
                }
            }
            ans = max(ans, edge);
            c = nc;
        }

        cout << (long long)ceil(sqrt(ans) / 2.0) << '\n';
    }

    return 0;
}
