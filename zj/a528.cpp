#include <algorithm>
#include <string>
#include <iostream>
#define MAXN 1000
using namespace std;

string s[MAXN];
int a[MAXN];

bool cmp(int x, int y) {
    bool sx = s[x][0] == '-', sy = s[y][0] == '-';
    if ((sx || sy) && (sx != sy))
        return sx;
    if (s[x].size() != s[y].size())
        return s[x].size() < s[y].size() != sx;
    int i, j;
    for (i = j = sx ? 1 : 0; i < s[x].size(); i++, j++)
        if (s[x][i] != s[y][j])
            return s[x][i] < s[y][j] != sx;
    return false;
}

int main(void)
{
    int n;
    ios_base::sync_with_stdio(false);
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            a[i] = i;
        }
        sort(a, a + n, cmp);
        for (int i = 0; i < n; i++)
            cout << s[a[i]] << '\n';
    }
    return 0;
}
