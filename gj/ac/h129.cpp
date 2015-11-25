#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100000;
int main()
{
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        vector<int> tail;
        for (int i = 0, a; i < n; i++) {
            scanf("%d", &a);
            if (a >= m) {
                if (tail.empty() || a >= tail.back())
                    tail.push_back(a);
                else if (2 * a >= tail.back()) {
                    tail.push_back(2 * a);
                    *upper_bound(tail.begin(), tail.end(), a) = a;
                } else {
                    *upper_bound(tail.begin(), tail.end(), 2 * a) = 2 * a;
                    *upper_bound(tail.begin(), tail.end(), a) = a;
                }
            } else if (2 * a >= m) {
                a *= 2;
                if (tail.empty() || a >= tail.back())
                    tail.push_back(a);
                else
                    *upper_bound(tail.begin(), tail.end(), a) = a;
            }
        }
        printf("%d\n", tail.size());
    }

    return 0;
}
