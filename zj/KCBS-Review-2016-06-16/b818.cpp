#include <cstdio>
#include <queue>
using namespace std;
const char players[] = {'O', 'X', 'D'};
int main()
{
    int n;
    scanf("%d", &n);
    deque<int> dk;
    while (n--) {
        int v;
        scanf("%d", &v);
        dk.push_back(v);
    }
    int sum[2] = {0, 0};
    for (int i = 0; dk.size(); ++i) {
        if (dk.front() >= dk.back()) {
            sum[i & 1] += dk.front();
            dk.pop_front();
        } else {
            sum[i & 1] += dk.back();
            dk.pop_back();
        }
    }
    printf("%c\n", players[sum[0] > sum[1] ? 0 : (sum[0] < sum[1] ? 1 : 2)]);
    printf("%d %d\n", sum[0], sum[1]);
}
