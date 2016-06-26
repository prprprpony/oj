#include <cstdio>
using namespace std;
int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int score;
            scanf("%d", &score);
            sum += score;
        }
        puts((sum + n - 1) / n > 59 ? "no" : "yes");
    }
}

