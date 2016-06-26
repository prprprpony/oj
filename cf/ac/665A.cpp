#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
// let 5:00 = 0
// 23:59 = 1139
//
// b start time = b * g
// b arrive time = b * g + tb
// S start time = S
// S arrive time = S + ta
//
// 0 <= b * g <= 1139
// b * g < S + ta
// S < b * g + tb
//
//  S - tb < b * g < S + ta
//  -1 < b * g < 1140
//  
    int ta, b, tb;
    scanf("%*d%d%d%d", &ta, &b, &tb);
    int h, m;
    scanf("%d:%d", &h, &m);
    int S = m + 60 * (h - 5);
    int f = S - tb < 0 ? -b : S - tb, l = min(1140, S + ta);

    // printf("l / b = %d\nf / b = %d\n", l / b, f / b);
    int ans = l / b - f / b;

    if (l % b == 0)
        --ans;

    printf("%d\n", ans);

    return 0;
}
