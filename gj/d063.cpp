#include <cstdio>
using namespace std;
int main()
{
    int t[2] = {0};
    int h, m, s;
    for (int i = 0; i < 2; i++) {
        scanf("%d:%d:%d", &h, &m, &s);
        t[i] = 3600 * h + 60 * m + s;
    }
    if (t[0] > t[1])
        t[1] += 3600 * 24;
    t[0] = t[1] - t[0];
    h = t[0] / 3600;
    t[0] %= 3600;
    m = t[0] / 60;
    t[0] %= 60;
    s = t[0];
    printf("%02d:%02d:%02d\n", h, m, s);

    return 0;
}
