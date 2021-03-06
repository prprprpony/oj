#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
#define C first
#define N second
#define MAXN 228
using namespace std;
typedef pair<int, int> pii;

vector<pii> v;
int d[MAXN][MAXN][MAXN];
int pre[MAXN];
int last[MAXN];
int n;

inline int sqr(int x) {return x * x;}

void init() {
    int s = 0;
    for (int i = 0; i < v.size(); i++) {
        int ss = s;
        for (int j = i; j < v.size(); j++) {
            ss += v[j].N;
            for (int k = 0; k <= n - ss; k++)
                d[i][j][k] = -1;
        }
        s += v[i].N;
    }
}

int dp(int l, int r, int k) { // alredy have k blocks which c == v[r].C
    int& now = d[l][r][k];
    if (now != -1)
        return now;
    if (l == r)
        return now = sqr(v[l].N + k);
    now = dp(l, r - 1, 0) + sqr(v[r].N + k);
    for (int p = pre[r]; p >= l; p = pre[p]) // merge with previos blocks
        now = max(now, dp(l, p, v[r].N + k) + dp(p + 1, r - 1, 0));
    return now;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int kase = 1; kase <= t; kase++) {
        cin >> n;
        v.clear();
        memset(last + 1, -1, n * sizeof(int));
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            if (v.empty() || v.back().C != c) {
                v.emplace_back(c, 1);
                pre[v.size() - 1] = last[c];
                last[c] = v.size() - 1;
            } else {
                v.back().N++;
            }
        }
#ifdef PP
        for (pii x : v)
            cout << x.C << ' ' << x.N << '\n';
#endif
        init();
        cout << "Case " << kase << ": " << dp(0, v.size() - 1, 0) << '\n';
    }
    return 0;
}
