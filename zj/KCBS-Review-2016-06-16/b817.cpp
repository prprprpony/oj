#include <queue>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    int k[2];
    deque<int> dk[2];
    scanf("%d", &n);
    for (int i = 0; i <= 1; ++i) {
        scanf("%d", k + i);
        for (int j = 0; j < k[i]; ++j) {
            int v;
            scanf("%d", &v);
            dk[i].push_back(v);
        }
    }
    int round;
    for (round = 0; dk[0].size() && dk[1].size(); ++round) {
        int b = dk[0].front() > dk[1].front() ? 0 : 1;
        dk[b].push_back(dk[b^1].front());
        dk[b].push_back(dk[b].front());
        dk[0].pop_front();
        dk[1].pop_front();
    }
    printf("%d %d\n", round, dk[0].size() ? 1 : 2);
}
