#include <cstdio>
#include <algorithm>
#define MAXN 4294967296
using namespace std;
int main()
{
    int t;
    unsigned long long l[3];
    unsigned long long d;
    unsigned long long s;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 3; ++i)
            scanf("%llu", &l[i]);
        sort(l, l+3);
        if (l[0] == MAXN) {
            printf("acute triangle\n");
            continue;
        }

        d = (l[2] + l[1]) * (l[2] - l[1]);
        s = l[0] * l[0];

        if (s > d)
            printf("acute triangle\n");
        else if (s == d)
            printf("right triangle\n");
        else
            printf("obtuse triangle\n");
    }

    return 0;
}
