#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <set>
using namespace std;
const int maxn = 20 + 5;
vector< pair<int, int> > px_ban;
vector< pair<int, int> > py_ban;
set<pair<int, int> > stop;
vector<string> ans;
char p[maxn];
int n;
char dir[] = {'n', 's', 'e', 'w'};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dfs(int len, int x, int y, int d)
{
    if (len > n) {
        if (x == 0 && y == 0) {
            ans.push_back(p + 1);
            return 1;
        }
        return 0;
    }
    if (stop.count(pair<int,int>(x, y)))
        return 0;
    {// cutting
        int h[2];
        // h[0] = len + (len + 2) + ... +  (n - (n - len) % 2)
        // h[1] = (len + 1) + (len + 3) + ... (n - (n - len + 1) % 2)
        for (int i = 0, hi, lo; i < 2; i++) {
            lo = len + i;
            hi = n - (n - len + i) % 2;
            h[i] = (hi + lo) * ((hi - lo) / 2 + 1) / 2;
        }
        if (dx[d] != 0) {
            if (abs(x) > h[0] || abs(y) > h[1])
                return 0;
        } else {
            if (abs(y) > h[0] || abs(x) > h[1])
                return 0;
        }
    }
    stop.insert(pair<int,int>(x, y));

    vector<pair<int, int> >::iterator it;
    int nx, ny, nd;
    int r = 0;
    for (int i = 0; i < 2; i++) {
        nd = d + i;
        nx = x + dx[nd] * len;
        ny = y + dy[nd] * len;
        if (!dy[d]) {
            it = lower_bound(py_ban.begin(), py_ban.end(), pair<int, int>(y, min(x, nx)));
            if (it != py_ban.end() && it->first == y && it->second <= max(x, nx))
                continue;
        } else {
            it = lower_bound(px_ban.begin(), px_ban.end(), pair<int, int>(x, min(y, ny)));
            if (it != px_ban.end() && it->first == x && it->second <= max(y, ny))
                continue;
        }
        p[len] = dir[nd];
        r += dfs(len + 1, nx, ny, 2 - d); // turn vertically
    }
    stop.erase(pair<int,int>(x, y));
    return r;
}

int main(void)
{
    int t, b;
    cin >> t;
    while (t--) {
        px_ban.clear();
        py_ban.clear();
        ans.clear();
        stop.clear();
        cin >> n >> b;
        p[n + 1] = '\0';
        for (int i = 0, x, y; i < b; i++) {
            cin >> x >> y;
            px_ban.push_back(pair<int,int>(x,y));
            py_ban.push_back(pair<int,int>(y,x));
        }
        sort(px_ban.begin(), px_ban.end());
        sort(py_ban.begin(), py_ban.end());
        int num = dfs(1, 0, 0, 0) + dfs(1, 0, 0, 2);
        sort(ans.begin(), ans.end());
        for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++)
            cout << *it << '\n';
        cout << "Found " << num << " golygon(s).\n\n";
    }
    return 0;
}
