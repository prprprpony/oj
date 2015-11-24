#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 25
vector< pair<int, int> > ban;
int n;
int dir[] = {'e', 'n', 's', 'w'}; // sorted in dictionary order
// turn 180 degrees from dir[x]:  dir[3 - x]
// turn 90 degrees from dir[x]:  dir[(x + 2) % 4]
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
int route[maxn];

int dfs(int step, int x, int y, int d)
{
    if (step == 0) {
        int num = 0;
        for (int i = 0; i < 4; i++) {
            route[0] = i;
            num += dfs(1, dx[i], dy[i], i);
        }
        return num;
    } else if (step < n) {
        d = min(d, 3 - d);
        for (int i = 0; i < 2; i++, d = 3 - d) {
            route[step] = d;
            dfs(step + 1)
        }

    } else {

    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int l, b, num = 0;
        cin >> l >> b;
        ban.resize(b);
        for (int i = 0; i < b; i++)
            cin >> ban[i].first >> ban[i].second;
        num = dfs(0, 0, 0, -1);
        printf("Found %d golygon(s).\n\n", num);
    }

    return 0;
}
