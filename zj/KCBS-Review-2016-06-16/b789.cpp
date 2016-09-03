#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1.228e6;
int main()
{
    int N;
    scanf("%d", &N);
    vector<int> g;
    for (int i = 0; i < N; ++i) {
        int x;
        scanf("%d", &x);
        if (g.empty() || x > g.back())
            g.push_back(x);
        else
            *lower_bound(g.begin(), g.end(), x) = x;
    }
    printf("%d\n", g.size());
}
