#include<bits/stdc++.h>
using namespace std;
const int N = 55;
vector<tuple<int, int, int, int>> ans;
int a[N][N];
int px[N], py[N];
int main()
{
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << "0\n";
        return 0;
    }
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x][y] = i;
    }
    vector<pair<int, int>> r1;
    vector<pair<int, int>> r2;
    vector<tuple<int, int, int>> r3;
    for (int i = 1; i <= m; ++i) {
        cin >> px[i] >> py[i];
        if (px[i] == 1) {
            r1.emplace_back(py[i], i);
        } else if (px[i] == 2) {
            r2.emplace_back(py[i], i);
        } else {
            r3.emplace_back(px[i], py[i], i);
        }
    }
    sort(begin(r1), end(r1));
    sort(begin(r2), end(r2));
    sort(rbegin(r3), rend(r3));
    int tp = 0;
    for (int i = 1; i <= n; ++i)
        if (i == 2) {
            for (int j = n; j >= 1; --j) {
                if (a[i][j]) {
                    int u = a[i][j];
                    a[i][j] = 0;
                    ++tp;
                    int x = i, y = j;
                    if (y >= tp) {
                        ans.emplace_back(x, y, x - 1, y);
                        --x;
                    }
                    while (y < tp) {
                        ans.emplace_back(x, y, x, y + 1);
                        ++y;
                    }
                    while (y > tp) {
                        ans.emplace_back(x, y, x, y - 1);
                        --y;
                    }
                    if (x > 1) {
                        ans.emplace_back(x, y, x - 1, y);
                        --x;
                    }
                    a[x][y] = u;
                }
            }
        } else {
            for (int j = 1; j <= n; ++j) {
                if (a[i][j]) {
                    int u = a[i][j];
                    a[i][j] = 0;
                    ++tp;
                    int x = i, y = j;
                    while (x > 2) {
                        ans.emplace_back(x, y, x - 1, y);
                        --x;
                    }
                    while (y < tp) {
                        ans.emplace_back(x, y, x, y + 1);
                        ++y;
                    }
                    while (y > tp) {
                        ans.emplace_back(x, y, x, y - 1);
                        --y;
                    }
                    if (x > 1) {
                        ans.emplace_back(x, y, x - 1, y);
                        --x;
                    }
                    a[x][y] = u;
                }
            }
        }
    for (auto [_, i] : r1) {
        int x = 1, y = find(a[1] + 1, a[1] + n + 1, i) - a[1];
        int y0 = y;
        a[x][y] = 0;
        ans.emplace_back(x, y, x + 1, y); ++x;
        while (y > 1 && a[x][y - 1] == 0) {
            ans.emplace_back(x, y, x, y - 1); --y;
        }
        a[x][y] = i;
        x = 1, y = y0;
        while (y - 1 >= 1 && a[x][y - 1]) {
            swap(a[x][y - 1], a[x][y]);
            ans.emplace_back(x, y - 1, x, y);
            --y;
        }
    }
    for (auto [_, i] : r2) {
        int x = 1, y = find(a[1] + 1, a[1] + n + 1, i) - a[1];
        int y0 = y;
        a[x][y] = 0;
        ans.emplace_back(x, y, x + 1, y); ++x;
        while (y - 1 >= 1 && a[x][y - 1] == 0) {
            ans.emplace_back(x, y, x, y - 1); --y;
        }
        a[x][y] = i;
        x = 1, y = y0;
        while (y - 1 >= 1 && a[x][y - 1]) {
            swap(a[x][y - 1], a[x][y]);
            ans.emplace_back(x, y - 1, x, y);
            --y;
        }
    }
    for (int j = 1; j <= n; ++j)
        if (a[2][j]) {
            ans.emplace_back(2, j, 1, j);
            swap(a[2][j], a[1][j]);
        }
    for (auto [_1, _2, i] : r3) {
        int x = 1, y = find(a[1] + 1, a[1] + n + 1, i) - a[1];
        a[1][y] = 0;
        while (x + 2 <= px[i]) { ans.emplace_back(x, y, x + 1, y); ++x; }
        while (y < py[i]) { ans.emplace_back(x, y, x, y + 1); ++y; }
        while (y > py[i]) { ans.emplace_back(x, y, x, y - 1); --y; }
        while (x + 1 <= px[i]) { ans.emplace_back(x, y, x + 1, y); ++x; }
    }
    for (auto [_, i] : r2) {
        int x = 1, y = find(a[1] + 1, a[1] + n + 1, i) - a[1];
        a[1][y] = 0;
        while (x + 1 <= px[i]) { ans.emplace_back(x, y, x + 1, y); ++x; }
        while (y - 1 >= 1 && a[x][y - 1] == 0) { ans.emplace_back(x, y, x, y - 1); --y; }
        a[x][y] = i;
    }
    reverse(begin(r2), end(r2));
    for (auto [_, i] : r2) {
        int x = 2, y = find(a[x] + 1, a[x] + n + 1, i) - a[x];
        a[x][y] = 0;
        while (y + 1 <= py[i] && a[x][y + 1] == 0) { ans.emplace_back(x, y, x, y + 1); ++y; }
        a[x][y] = i;
    }
    reverse(begin(r1), end(r1));
    for (auto [_, i] : r1) {
        int x = 1, y = find(a[x] + 1, a[x] + n + 1, i) - a[x];
        a[x][y] = 0;
        while (y + 1 <= py[i] && a[x][y + 1] == 0) { ans.emplace_back(x, y, x, y + 1); ++y; }
        a[x][y] = i;
    }
    assert(ans.size() <= 10800);
    cout << ans.size() << '\n';
    for (auto [a, s, d, f] : ans)
        cout << a << ' ' << s << ' ' << d << ' ' << f << '\n';
}
