#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        vector<pair<int, int>> a;
        for (int i = 0; i < n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            if (x == y)
                a.emplace_back(x, y);
            else
                a.emplace_back(x, y), a.emplace_back(y, x);
        }
        sort(a.begin(), a.end());
        vector<int> tail = {0};
        for (auto p : a) {
            int x = p.second;
            if (x >= tail.back())
                tail.push_back(x);
            else
                *lower_bound(tail.begin(), tail.end(), x) = x;
        }
        printf("%d\n", (int)tail.size() - 1);
    }
}
