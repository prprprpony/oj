#include <bits/stdc++.h>
using namespace std;
const int N = (100000 + 87) / 2;
bool sev[N];
vector<int> p;
int main()
{
    sev[0] = sev[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!sev[i])
            p.push_back(i);
        for (int j : p) {
            if (j * i >= N)
                break;
            sev[j * i] = 1;
            if (i % j == 0)
                break;
        }
    }
    ios::sync_with_stdio(0);cin.tie(0);
    int m,a,b;
    while ((cin >> m >> a >> b) && m){
        int x = 2, y = 2;
        for (int i = 0; i < p.size() && p[i] * p[i] <= m; ++i) {
            int w = p[i];
            int hi = min(w*b/a,m/w);
            if (w > hi)
                continue;
            int j = upper_bound(p.begin(),p.end(),hi) - p.begin();
            if (j && p[j-1] >= w && x*y < p[j-1] * w)
                x = w, y = p[j-1];
        }
        cout << x << ' ' << y << '\n';
    }
}
