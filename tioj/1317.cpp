#include <bits/stdc++.h>
using namespace std;
#define ALL(a) begin(a),end(a)
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 2048;
bitset<N> v0[N],v1[N],in[N];
pii f[N][N];
int a[N*N],an;
int n;
char s[2005][2005];
const char dir[] = "lrud";
const int dr[] = {0,0,-1,1};
const int dc[] = {-1,1,0,0};
void apush_back(int x)
{
    a[an++] = x;
}
bool ok(int i,int j)
{
    return !(min(i,j) < 0 || max(i,j) >= n);
}
int id(int i,int j)
{
    if (!ok(i,j))
        return -1;
    return i * n + j;
}
pii di(int u)
{
    return {u/n,u%n};
}
pii nxt(int i,int j)
{
    int k = find(ALL(dir),s[i][j]) - dir;
    return pii(i + dr[k], j + dc[k]);
}
void find_circle(int i,int j)
{
    int x,y;
    for (tie(x,y) = tie(i,j); ok(x,y) && !v1[x][y]; tie(x,y) = nxt(x,y))
        v1[x][y] = 1;
    if (ok(x,y) && !v0[x][y]) {
        pii p(x,y);
        f[x][y] = p;
        while ((p = nxt(p.F,p.S)) != pii(x,y))
            f[p.F][p.S] = {x,y};
    }
    for (tie(x,y) = tie(i,j); ok(x,y) && !v0[x][y]; tie(x,y) = nxt(x,y))
        v0[x][y] = 1;
}
int dfs(int i,int j,int ss=0)
{
    vector<pii> vp{pii(i,j)};
    while (vp.size() == 1) {
        tie(i,j) = vp[0];
        vp.clear();
        ss += f[i][j].F == -1;
        v0[i][j] = 0;
        for (int k = 0; k < 4; ++k) {
            int x = i + dr[k], y = j + dc[k];
            if (ok(x,y) && nxt(x,y) == pii(i,j) && f[x][y].F == -1 && v0[x][y]) {
                vp.emplace_back(x,y);
            }
        }
    }
    if (vp.empty())
        return ss;
    int mx = 0;
    for (const pii & p : vp) {
        int w = dfs(p.F,p.S);
        if (w > mx)
            swap(w,mx);
        if (w)
            apush_back(w);
    }
    return mx + ss;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            f[i][j] = pii(-1,-1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            pii p = nxt(i,j);
            if (ok(p.F,p.S))
                in[i][j] = 1;
            if (v0[i][j])
                continue;
            find_circle(i,j);
        }
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (!v0[i][j])
                continue;
            if (f[i][j].F != -1) {
                int k = 0;
                pii p(i,j);
                int mx = 0;
                do {
                    ++k;
                    int w = dfs(p.F,p.S);
                    if (w > mx)
                        swap(mx,w);
                    if (w)
                        apush_back(w);
                } while ((p = nxt(p.F,p.S)) != pii(i,j));
                apush_back(mx + k);
            } else if (!in[i][j]) {
                apush_back(dfs(i,j));
            }
        }
    sort(a,a+an,greater<int>());
    int ans = 0;
    for (int i = 0; i < an; i += 2)
        ans += a[i];
    cout << ans << '\n';
}
