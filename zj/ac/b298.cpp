#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 10005;
vector<int> child[maxn];
bool unsafe[maxn];
void dfs(int x)
{
    if (unsafe[x]) {
        return;
    } else {
        unsafe[x] = true;
        for (vector<int>::iterator it = child[x].begin(); it != child[x].end(); it++)
            dfs(*it);
    }
}
int main()
{
    int n, m, l, q;
    cin >> n >> m >> l >> q;
    memset(unsafe, 0, sizeof(bool) * (n + 1));
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        child[a].push_back(b);
    }
    for (int i = 0, x; i < l; i++) {
        cin >> x;
        dfs(x);
    }
    for (int i = 0, y; i < q; i++) {
        cin >> y;
        cout << (unsafe[y] ? "TUIHUOOOOOO" : "YA~~") << '\n';
    }

    return 0;
}
